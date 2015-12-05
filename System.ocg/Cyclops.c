
global func AddCyclopsAI(object clonk) // somewhat hacky, but it works
{
	var effect_name = "IntCyclopsAI";
	var fx = GetEffect(effect_name, clonk);
	if (!fx) fx = AddEffect(effect_name, clonk, 1, 10);
	if (!fx || !clonk) return nil;
	
//	fx.ai = AI;
//	clonk.ExecuteAI = AI.Execute;
	clonk.ai = fx;
//	if (clonk->GetProcedure() == "PUSH") fx.vehicle = clonk->GetActionTarget();
//	AI->BindInventory(clonk); // this works
	var cnt = clonk->ContentsCount();
	fx.bound_weapons = CreateArray(cnt);
	for (var i=0; i<cnt; ++i) fx.bound_weapons[i] = clonk->Contents(i);

//	AI->SetHome(clonk); // this did not
	fx.home_x = clonk->GetX();
	fx.home_y = clonk->GetY();
	fx.home_dir = DIR_Left;

//	AI->SetGuardRange(clonk, fx.home_x-AI_DefGuardRangeX, fx.home_y-AI_DefGuardRangeY, AI_DefGuardRangeX*2, AI_DefGuardRangeY*2);
	fx.guard_range = {//x=x, y=y, wdt=wdt, hgt=hgt};
                      x = fx.home_x-AI_DefGuardRangeX,
                      y = fx.home_y-AI_DefGuardRangeY,
                      wdt = AI_DefGuardRangeX*2,
                      hgt =  AI_DefGuardRangeY*2};

	AI->SetMaxAggroDistance(clonk, AI_DefMaxAggroDistance);
	// AI editor commands
	//if (!clonk.EditCursorCommands)
	//	clonk.EditCursorCommands = [];
	//else if (clonk.EditCursorCommands == clonk.Prototype.EditCursorCommands)
	//	clonk.EditCursorCommands = clonk.EditCursorCommands[:];
	//var idx;
	//if ((idx=GetIndexOf(clonk.EditCursorCommands, "AI_Add()"))>=0) clonk.EditCursorCommands[idx] = nil;
	//if (GetIndexOf(clonk.EditCursorCommands, AI.AI_SetHome)<0)
	//{
	//	var l = GetLength(clonk.EditCursorCommands);
	//	clonk.EditCursorCommands[l++] = clonk.AI_SetHome = AI.AI_SetHome;
	//	clonk.EditCursorCommands[l++] = clonk.AI_BindInventory = AI.AI_BindInventory;
	//}
	return fx;
}

global func FxIntCyclopsAITimer(object cyclops, proplist fx, int time)
{
	if (!fx.cyclops)
	{
		fx.cyclops = cyclops;
		fx.weapon = cyclops->FindContents(Club);
	}

	fx.time = time;

	// Find an enemy
	if (fx.target) if (!fx.target->GetAlive() || (!fx.ranged && ObjectDistance(fx.target) >= fx.max_aggro_distance)) fx.target = nil;
	if (!fx.target)
	{
		if (!(fx.target = CyclopsFindTarget(fx))) return CyclopsExecuteIdle(fx);
	}

	// Attack it!
	return CyclopsExecuteMelee(fx);
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
//	for (var target in FindObjects(Find_InRect(fx.guard_range.x-fx.cyclops->GetX(),fx.guard_range.y-fx.cyclops->GetY(),fx.guard_range.wdt,fx.guard_range.hgt), Find_OCF(OCF_CrewMember), hostile_criteria, Find_NoContainer(), Sort_Random()))
	for (var target in FindObjects(Find_InRect(fx.guard_range.x,fx.guard_range.y,fx.guard_range.wdt,fx.guard_range.hgt), Find_OCF(OCF_CrewMember), hostile_criteria, Find_NoContainer(), Sort_Random()))
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
		if (Abs(dx) <= 35 && dy >= -15)
		{
			// OK, slash!
			if (fx.cyclops->IsAiming())
			{
//				if (!fx.did_aim)
//				{
					fx.weapon->ControlUseHolding(fx.cyclops, dx, dy);
//					fx.did_aim = true;
//				}
//				else
//				{
					fx.weapon->ControlUseStop(fx.cyclops, dx, dy);
//					fx.did_aim = false;
//				}
				return;
			}

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
			if (!fx.cyclops->IsAiming())
				fx.weapon->ControlUseStart(fx.cyclops, dx, dy);
			
			return;
		}
	}
	
	// Not in range. Walk there.
//	if (!fx.cyclops->GetCommand() || !Random(10)) fx.cyclops->SetCommand("MoveTo", nil, tx+20-40*fx.cyclops->GetDir(), y);
	
	return true;
}



global func CyclopsCheckHandsAction(fx)
{
//	return true;
	// can use hands?
	if (fx.cyclops->~HasHandAction()) return true;
	// Can't throw: Is it because e.g. we're scaling?
	if (!fx.cyclops->HasActionProcedure()) { CyclopsExecuteStand(fx); return false; }
	// Probably hands busy. Just wait.
	return false;
}
