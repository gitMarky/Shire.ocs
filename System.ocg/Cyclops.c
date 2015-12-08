
global func AddCyclopsAI(object clonk) // somewhat hacky, but it works
{
	var effect_name = "IntCyclopsAI";
	var fx = GetEffect(effect_name, clonk);
	if (!fx) fx = AddEffect(effect_name, clonk, 1, 2);
	if (!fx || !clonk) return nil;
	
	clonk.ai = fx;

	// bin inventory
	var cnt = clonk->ContentsCount();
	fx.bound_weapons = CreateArray(cnt);
	for (var i=0; i<cnt; ++i) fx.bound_weapons[i] = clonk->Contents(i);

	// set home
	fx.home_x = clonk->GetX();
	fx.home_y = clonk->GetY();
	fx.home_dir = DIR_Left;

	// set guard range
	fx.guard_range = {
                      x = fx.home_x-AI_DefGuardRangeX,
                      y = fx.home_y-AI_DefGuardRangeY,
                      wdt = AI_DefGuardRangeX*2,
                      hgt =  AI_DefGuardRangeY*2};

	AI->SetMaxAggroDistance(clonk, AI_DefMaxAggroDistance);
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
	
	// do not idle
	var effect = GetEffect("IntWalk", fx.cyclops);
	if (effect) effect.idle_time = 0;

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
	
	if (GetActiveSequence())
	{
		fx.spraying = 0;
		fx.spraying_charge = 0;
		return;
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
		// hit objects
		if (Abs(dx) <= 35 && dy >= -15)
		{
			// OK, slash!
			if (fx.cyclops->IsAiming())
			{
				fx.weapon->ControlUseHolding(fx.cyclops, dx, dy);
				fx.weapon->ControlUseStop(fx.cyclops, dx, dy);
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
		
		if (Inside(ObjectDistance(fx.cyclops, fx.target), 40, 120))
		{
			DoFireBreath(fx, x ,y , tx, ty);
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

global func DoFireBreath(proplist fx, int x, int y, int tx, int ty)
{
	var reach = 90;
	var spray_max = 30;
	var anim_length = 20;

//	var sx = x - 6;
//	var sy = y - 15;
	var sx = x - 3;
	var sy = y - 15;	
	
	// effects
	if (ObjectDistance(fx.cyclops, fx.target) < reach && fx.spraying < spray_max)
	{
		if (fx.spraying_charge <= 0)
		{
			var action = "IdleLookAround";
			fx.cyclops->PlayAnimation(action, CLONK_ANIM_SLOT_Arms, Anim_Linear(0, 0, fx.cyclops->GetAnimationLength(action), anim_length, ANIM_Remove), Anim_Linear(0, 0, 1000, 5, ANIM_Remove));
			fx.spraying_charge = 1;
		}
		else if (fx.spraying_charge < anim_length)
		{
			fx.spraying_charge++;
		}
		else
		{
			var target_angle = Normalize(Angle(sx, sy, tx, ty), -180);
			var source_angle = -90 + fx.cyclops->GetDir() * 180;
			
			var a = Min(spray_max, fx.spraying * 2);
			var b = spray_max - a;
			var angle = (b * source_angle + a * target_angle) / spray_max;
			angle = Normalize(angle, -180);
			var head_angle = Normalize(angle - source_angle, -180);

			// turn his head towards the clonk
			// somehow the turning head makes the cyclops invisible, though
			//var transform = Trans_Rotate(10, 0, 0, 1);
			var transform = Trans_Rotate(head_angle, 0, 0, 1);

			if (!fx.anim_nr)
			{
				fx.anim_nr = fx.cyclops->TransformBone("skeleton_head", transform, 5, Anim_Const(1000));
			}
			else
			{
				fx.cyclops->SetAnimationBoneTransform(fx.anim_nr, transform);
			}

			fx.spraying = Min(spray_max, fx.spraying + 1);

			var fuzzy = 10;
			var velocity = reach * 3; // should take 20 frames to reach the end
			var vx = +Sin(angle, velocity);
			var vy = -Cos(angle, velocity);
			var vxs = +Sin(angle, 8 * velocity / 10);
			var vys = -Cos(angle, 8 * velocity / 10);
			var vx0 = +Sin(angle, velocity / 3);
			var vy0 = -Cos(angle, velocity / 3);

			var smoke = Particles_Smoke();
			
			smoke.ForceX = 0;
			smoke.ForceY = PV_Gravity(-10);
			
			
			smoke.R = smoke.G = smoke.B = PV_Linear(255, 100);
			smoke.Size = PV_Linear(5, PV_Random(20, 30));

			for (var i = 0; i < RandomX(3, 5); i++)
			{
				var vxd = vx + RandomX(-fuzzy, +fuzzy);
				var vyd = vy + RandomX(-fuzzy, +fuzzy);
				CreateParticle("Fire", sx, sy, PV_Linear(vx0, vxd), PV_Linear(vy0, vyd), PV_Random(30, 40), smoke, 1);
			}
			for (var i = 0; i < RandomX(3, 5); i++)
			{
				var vxd = vxs + RandomX(-fuzzy, +fuzzy);
				var vyd = vys + RandomX(-fuzzy, +fuzzy);
				CreateParticle("Fire", sx, sy, PV_Linear(vx0, vxd), PV_Linear(vy0, vyd), PV_Random(50, 60), smoke, 1);
			}
		}
	}
	else
	{
		// cooldown and reset
		fx.spraying = Min(2 * spray_max, Max(spray_max + 1, fx.spraying + 1));
		if (fx.spraying == 2 * spray_max)
		{
			fx.spraying = 0;
			fx.spraying_charge = 0;
		}
	}

	// damage the clonk
	if (fx.spraying > 0
	 && fx.spraying <= spray_max
	 && ObjectDistance(fx.cyclops, fx.target) < (spray_max + fx.spraying)*reach/(2*spray_max))
	{
		fx.target->Message("*!*");
		//var damage=1000;
		//fx.target->DoEnergy(-damage, true, FX_Call_EngGetPunched, NO_OWNER);
	}
}