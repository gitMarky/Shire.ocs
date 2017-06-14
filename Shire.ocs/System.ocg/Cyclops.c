
static const CYCLOPS_FireBreath_Duration = 30;
static const CYCLOPS_FireBreath_Precision = 10;
static const CYCLOPS_FireBreath_Reach = 120;

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
                      x = fx.home_x - AI.GuardRangeX,
                      y = fx.home_y - AI.GuardRangeY,
                      wdt = AI.GuardRangeX*2,
                      hgt =  AI.GuardRangeY*2};
                      

	fx.spray_old = {time = 0, v0 = 0, v1 = 0, reach = 0};
	fx.spray_cur = {time = 0, v0 = 0, v1 = 0, reach = 0};

	AI->SetMaxAggroDistance(clonk, AI.MaxAggroDistance);
	return fx;
}

global func FxIntCyclopsAITimer(object cyclops, proplist fx, int time)
{
	if (!fx.cyclops)
	{
		fx.cyclops = cyclops;
		fx.weapon = cyclops->FindContents(Club);
	}
	if (!fx.eye) fx.eye = FindObject(Find_ID(CyclopsEye));

	fx.time = time;
	
	// do not idle
	var effect = GetEffect("IntWalk", fx.cyclops);
	if (effect) effect.idle_time = 0;
	
	fx.eye->SetPosition(fx.cyclops->GetX() -4 + fx.cyclops->GetDir() * 8, fx.cyclops->GetY() - 19);

	// Find an enemy
	if (fx.target) if (!fx.target->GetAlive() || (!fx.ranged && ObjectDistance(fx.target) >= fx.max_aggro_distance)) fx.target = nil;
	if (!fx.target)
	{
		if (!(fx.target = CyclopsFindTarget(fx))) return CyclopsExecuteIdle(fx);
	}

	// Attack it!
	return CyclopsExecuteMelee(fx, time);
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

global func CyclopsExecuteMelee(fx, int timer)
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

	if (tx > x)
	{
		fx.cyclops->SetDir(DIR_Right);
	}
	else
	{
		fx.cyclops->SetDir(DIR_Left);
	}

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
			
			// fire breath cooldown
			fx.spraying = CYCLOPS_FireBreath_Duration;
			
			return;
		}
		
			DoFireBreath(fx, x ,y , tx, ty, timer);
	}
	
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

global func DoFireBreath(proplist fx, int x, int y, int tx, int ty, int timer)
{
	var anim_length = 12;

	var sx = x - 3 + 6 * fx.cyclops->GetDir();
	var sy = y - 15;	

	// effects
	if (fx.spraying_charge <= 0)
	{
		if (ObjectDistance(fx.cyclops, fx.target) < CYCLOPS_FireBreath_Reach && fx.spraying < CYCLOPS_FireBreath_Duration)
		{
			var action = "IdleLookAround";
			fx.cyclops->PlayAnimation(action, CLONK_ANIM_SLOT_Arms, Anim_Linear(0, 0, fx.cyclops->GetAnimationLength(action), anim_length, ANIM_Remove), Anim_Linear(0, 0, 1000, 5, ANIM_Remove));
			fx.spraying_charge = 1;
		}
	}
	else if (fx.spraying_charge < anim_length)
	{
		fx.spraying_charge++;
		
		if (fx.spraying_charge >= anim_length)
		{
			fx.cyclops->Sound("BalloonInflate");
		}
	}
	else if (fx.spraying < CYCLOPS_FireBreath_Duration)
	{
		var target_angle = Normalize(Angle(sx, sy, tx, ty), -180);
		var source_angle = -90 + fx.cyclops->GetDir() * 180;

		var a = Min(CYCLOPS_FireBreath_Duration, fx.spraying * 2);
		var b = CYCLOPS_FireBreath_Duration - a;
		var angle = (b * source_angle + a * target_angle) / CYCLOPS_FireBreath_Duration;
		angle = Normalize(angle, -180);
		var head_angle = Normalize(angle - source_angle, -180);

		// turn his head towards the clonk
		// somehow the turning head makes the cyclops invisible, though
		var transform = Trans_Rotate(10, 0, 0, 1);
		//var transform = Trans_Rotate(head_angle, 0, 0, 1);

		if (!fx.anim_nr)
		{
			fx.anim_nr = fx.cyclops->TransformBone("skeleton_head", transform, 5, Anim_Const(1000));
		}
		else
		{
			fx.cyclops->SetAnimationBoneTransform(fx.anim_nr, transform);
		}

		fx.spraying = Min(CYCLOPS_FireBreath_Duration, fx.spraying + 1);
		var distance = Min(CYCLOPS_FireBreath_Reach, ObjectDistance(fx.cyclops, fx.target));

		FireBreathEffect(fx, angle, distance, sx, sy, timer);
		FireBreathDamage(fx, angle, distance, sx, sy);
	}
	else
	{
		// cooldown and reset
		fx.spraying = Min(2 * CYCLOPS_FireBreath_Duration, Max(CYCLOPS_FireBreath_Duration + 1, fx.spraying + 1));
		if (fx.spraying == 2 * CYCLOPS_FireBreath_Duration)
		{
			fx.spraying = 0;
			fx.spraying_charge = 0;
			fx.spray_old = {time = 0, v0 = 0, v1 = 0, reach = 0};
			fx.spray_cur = {time = 0, v0 = 0, v1 = 0, reach = 0};
		}
	}
}

global func FireBreathEffect(proplist fx, int angle, int distance, int x, int y, int timer)
{
		// calculate velocity and coordinates for the effects
		
		var fuzzy = distance / 9;
		var velocity = distance * 3;
		var vx = +Sin(angle, velocity);
		var vy = -Cos(angle, velocity);
		var vxs = +Sin(angle, 8 * velocity / 10);
		var vys = -Cos(angle, 8 * velocity / 10);
		var vx0 = +Sin(angle, velocity / 3);
		var vy0 = -Cos(angle, velocity / 3);

		// replace with faster flame
		if (velocity > fx.spray_old.v1 && fx.spray_cur.reach >= fx.spray_old.reach)
		{
			// transfer new values to old values
			fx.spray_old.reach = fx.spray_cur.reach;
			fx.spray_old.time = fx.spray_cur.time;
			fx.spray_old.v0 = fx.spray_cur.v0;
			fx.spray_old.v1 = fx.spray_cur.v1;
			fx.spray_old.rmax = fx.spray_cur.rmax;

			// start a new beam at the beginning
			fx.spray_cur.reach = 0;
			fx.spray_cur.time = 0;
			fx.spray_cur.v0 = velocity / 3;
			fx.spray_cur.v1 = velocity;
			fx.spray_cur.rmax = distance * CYCLOPS_FireBreath_Precision;
		}

		// calculate position of the flame
		
		FireBreathReach(fx.spray_old);
		FireBreathReach(fx.spray_cur);

		// particle definitions

		var smoke = Particles_Smoke();
		
		smoke.ForceX = 0;
		smoke.ForceY = PV_Gravity(-10);
		
		smoke.R = smoke.G = smoke.B = PV_Linear(255, 100);
		smoke.Size = PV_Linear(5, PV_Random(20, 30));

		for (var i = 0; i < RandomX(3, 5); i++)
		{
			var scale = 15;
			var factor = (scale - i);
			var x0 = x + i * vx0 / 20;
			var y0 = y + i * vy0 / 20;
			var vx1 = vx * factor / scale + RandomX(-fuzzy, +fuzzy);
			var vy1 = vy * factor / scale + RandomX(-fuzzy, +fuzzy);
			CreateParticle("Fire", x0, y0, PV_Linear(vx0, vx1), PV_Linear(vy0, vy1), PV_Random(30, 40), smoke, 1);
		}
		for (var i = 0; i < RandomX(3, 5); i++)
		{
			var scale = 15;
			var factor = (scale - i);
			var x0 = x + i * vx0 / 20;
			var y0 = y + i * vy0 / 20;
			var vxm = vx0 + RandomX(-fuzzy, + fuzzy);
			var vym = vy0 + RandomX(-fuzzy, + fuzzy);
			var vx1 = vxs * factor / scale + RandomX(-fuzzy, +fuzzy);
			var vy1 = vys * factor / scale + RandomX(-fuzzy, +fuzzy);
			CreateParticle("Fire", x0, y0, PV_Linear(vxm, vx1), PV_Linear(vym, vy1), PV_Random(50, 60), smoke, 1);
		}
}

global func FireBreathDamage(proplist fx, int angle, int max_reach, int x, int y)
{
	var reach = Min(fx.spray_cur.reach, max_reach * CYCLOPS_FireBreath_Precision);
	var dx = +Sin(angle, reach) / CYCLOPS_FireBreath_Precision;
	var dy = -Cos(angle, reach) / CYCLOPS_FireBreath_Precision;

	if (false)
	{
		if (!fx.rock) fx.rock = CreateObject(Rock);
		fx.rock->SetPosition(x + dx, y + dy);
		fx.rock->SetXDir();
		fx.rock->SetYDir();
	}

	// damage the clonk
	reach /= CYCLOPS_FireBreath_Precision;
	reach += 5; // the fuzzy part of the flames
	if (ObjectDistance(fx.cyclops, fx.target) < reach)
	{
		if (cyclops_dangerous)
		{
			var damage=1000;
			fx.target->DoEnergy(-damage, true, FX_Call_EngGetPunched, NO_OWNER);
		}
		else
		{
			fx.target.hurt_by_cyclops = true;
		}
	}
}

global func FireBreathReach(proplist info)
{
	info.time += 1;
	if (info.time <= CYCLOPS_FireBreath_Duration)
	{
		var v = ((CYCLOPS_FireBreath_Duration - info.time) * info.v0 + info.time * info.v1) / CYCLOPS_FireBreath_Duration;
		info.reach = BoundBy(info.reach + v, 0, info.rmax);
	}
}