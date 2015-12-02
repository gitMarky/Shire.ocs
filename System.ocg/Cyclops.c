
global func FxIntCyclopsAITimer(object cyclops, proplist ai, int timer)
{
	if (!ai.cyclops)
	{
		ai.cyclops = cyclops;
	}
}

// called in context of the Clonk that is being controlled
private func Execute(proplist fx, int time)
{
	fx.time = time;
	// Evasion, healing etc. if alert
	if (fx.alert) if (ExecuteProtection(fx)) return true;
	// Find something to fight with
	if (!fx.weapon) { CancelAiming(fx); if (!ExecuteArm(fx)) return ExecuteIdle(fx); else if (!fx.weapon) return true; }
	// Weapon out of ammo?
	if (fx.ammo_check && !Call(fx.ammo_check, fx, fx.weapon)) { fx.weapon=nil; return false; }
	// Find an enemy
	if (fx.target) if (!fx.target->GetAlive() || (!fx.ranged && ObjectDistance(fx.target) >= fx.max_aggro_distance)) fx.target = nil;
	if (!fx.target)
	{
		CancelAiming(fx);
		if (!(fx.target = FindTarget(fx))) return ExecuteIdle(fx);
		// first encounter callback. might display a message.
		if (fx.encounter_cb) if (GameCall(fx.encounter_cb, this, fx.target)) fx.encounter_cb = nil;
		// wake up nearby allies
		if (fx.ally_alert_range)
		{
			var ally_fx;
			for (var ally in FindObjects(Find_Distance(fx.ally_alert_range), Find_Exclude(this), Find_OCF(OCF_CrewMember), Find_Owner(GetOwner())))
				if (ally_fx = AI->GetAI(ally))
					if (!ally_fx.target)
					{
						ally_fx.target = fx.target;
						ally_fx.alert = ally_fx.time;
						if (ally_fx.encounter_cb) if (GameCall(ally_fx.encounter_cb, ally, fx.target)) ally_fx.encounter_cb = nil;
					}
			// waking up works only once. after that, AI might have moved and wake up Clonks it shouldn't
			fx.ally_alert_range = nil;
		}
	}
	// Attack it!
	return Call(fx.strategy, fx);
}



global func CyclopsExecuteIdle(fx)
{
	if (!Inside(fx.cyclops->GetX()-fx.home_x, -5,5) || !Inside(fx.cyclops->GetY()-fx.home_y, -15,15))
	{
		fx.cyclops->SetCommand("MoveTo", nil, fx.home_x, fx.home_y);
	}
	else
	{
		fx.cyclops->SetCommand("None");
		fx.cyclops->SetComDir(COMD_Stop);
		fx.cyclops->SetDir(fx.home_dir);
	}
	return true;
}

global func CyclopsFindTarget(fx)
{
	// Consider hostile clonks, or all clonks if the AI does not have an owner.
	var hostile_criteria = Find_Hostile(fx.cyclops->GetOwner());
	if (fx.cyclops->GetOwner() == NO_OWNER)
		hostile_criteria = Find_Not(Find_Owner(fx.cyclops->GetOwner()));
	for (var target in FindObjects(Find_InRect(fx.guard_range.x-GetX(),fx.guard_range.y-GetY(),fx.guard_range.wdt,fx.guard_range.hgt), Find_OCF(OCF_CrewMember), hostile_criteria, Find_NoContainer(), Sort_Random()))
		if (PathFree(fx.cyclops->GetX(),fx.cyclops->GetY(),target->GetX(),target->GetY()))
			return target;
	// Nothing found.
	return;
}


global func CyclopsExecuteStand(fx)
{
	fx.cyclops->SetCommand("None");
	fx.cyclops->SetComDir(COMD_Stop);
	fx.cyclops->SetDir(DIR_Left);
	return true;
}

global func CyclopsExecuteMelee(fx)
{
	// Still carrying the melee weapon?
	if (fx.weapon->Contained() != fx.cyclops)
	{
		fx.weapon=nil;
		return false;
	}
	// Are we in range?
	var x=fx.cyclops->GetX();
	var y=fx.cyclops->GetY();
	var tx=fx.target->GetX();
	var ty=fx.target->GetY();
	var dx = tx-x, dy = ty-y;
	
	// the cyclops stands in its place and hits objects or breathes fire
	if (PathFree(x,y,tx,ty))
	{
		if (Abs(dx) <= 10 && dy >= -15)
		{
			// target is under us - sword slash downwards!
			if (!CyclopsCheckHandsAction(fx)) return true;
			// Stop here
			fx.cyclops->SetCommand("None");
			fx.cyclops->SetComDir(COMD_None);
			// cooldown?
			if (!fx.weapon->CanStrikeWithWeapon(fx.cyclops))
			{
				return true;
			}
			// OK, slash!
			return fx.weapon->ControlUse(fx.cyclops, tx,ty);
		}
	}
	
	// Not in range. Walk there.
	if (!GetCommand() || !Random(10)) SetCommand("MoveTo", fx.target);
	
	return true;
}



global func CyclopsCheckHandsAction(fx)
{
	// can use hands?
	if (fx.cyclops->~HasHandAction()) return true;
	// Can't throw: Is it because e.g. we're scaling?
	if (!fx.cyclops->HasActionProcedure()) { CyclopsExecuteStand(fx); return false; }
	// Probably hands busy. Just wait.
	return false;
}
