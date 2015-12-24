/*
 * Bird
 *
 * With decorative behavior.
 *
 * Author: Marky, original found in Clonk Rage
 */


/* Initialisierung */

func Initialize()
{
	SetAction("Fly");
	AddEffect("IntAnimalTurn", this, 1, 1, this);
}

/* Movement */

public func AnimalTurnRight()
{
	if (AnimalCanTurn())
	{
		if (GetXDir() < 0) SetXDir(0);
		SetDir(DIR_Right);
		SetComDir(COMD_Right);
		AnimalOnTurnRight();
	}
}

public func AnimalTurnLeft()
{
	if (AnimalCanTurn())
	{
		if (GetXDir() > 0) SetXDir(0);
		SetDir(DIR_Left);
		SetComDir(COMD_Left);
		AnimalOnTurnLeft();
	}
}

private func FxIntAnimalTurnTimer(object target, proplist effect)
{
	if (target != this) return;

	AvoidHittingLandscape();

	// Flying backwards? Turn around!
	if (GetXDir()>0 && GetDir() == DIR_Left)  return AnimalTurnRight();
	if (GetXDir()<0 && GetDir() == DIR_Right) return AnimalTurnLeft();
}

private func AnimalCanTurn(){ return !Stuck() && GetAction() == "Fly"; }
private func AnimalOnTurnLeft()
{
	SetAction("Turn");
}
private func AnimalOnTurnRight()
{
	SetAction("Turn");
}

/* Hitting the landscape... */

protected func ContactLeft()
{
	return AnimalTurnRight();
}

protected func ContactRight()
{
	return AnimalTurnLeft();
}

protected func ContactTop()
{
	return SetComDir(COMD_Down);
}

protected func ContactBottom()
{
	return SetComDir(COMD_Up);
}


/* Animations */

local ActMap = {
Fly = {
	Prototype = Action,
	Name = "Fly",
	Procedure = DFA_FLOAT,
	Speed = 200,
	Accel = 16,
	Decel = 16,
	Directions = 2,
	FlipDir = 1,
	Length = 20,
	Delay = 1,
	X = 0,
	Y = 0,
	Wdt = 14,
	Hgt = 12,
	NextAction = "Fly",
	TurnAction = "Turn",
	StartCall = "FlyTryAttack",
	PhaseCall = "FlyAvoidDanger",
},

Turn = {
	Prototype = Action,
	Name = "Turn",
	Procedure = DFA_FLOAT,
	Speed = 100,
	Accel = 16,
	Decel = 32,
	Directions = 2,
	FlipDir = 1,
	Length = 20,
	Delay = 1,
	X = 0,
	Y = 12,
	Wdt = 14,
	Hgt = 12,
	NextAction = "Fly",
},

Attack = {
	Prototype = Action,
	Name = "Attack",
	Procedure = DFA_FLOAT,
	Directions = 2,
	FlipDir = 1,
	Length = 20,
	Delay = 1,
	X = 0,
	Y = 24,
	Wdt = 14,
	Hgt = 12,
	NextAction = "Fly",
},

Tumble = {
	Prototype = Action,
	Name = "Tumble",
	Procedure = DFA_NONE,
	Directions = 2,
	FlipDir = 1,
	Length = 20,
	Delay = 1,
	X = 0,
	Y = 36,
	Wdt = 14,
	Hgt = 12,
	NextAction = "Fly",
	ObjectDisabled = 1,
	InLiquidAction = "Fly",
},

Eat = {
	Prototype = Action,
	Name = "Eat",
	Procedure = DFA_FLOAT,
	Directions = 2,
	FlipDir = 1,
	Length = 20,
	Delay = 2,
	X = 0,
	Y = 24,
	Wdt = 14,
	Hgt = 12,
	NextAction = "Fly",
	//EndCall = "Eating",
},

BuildNest = {
	Prototype = Action,
	Name = "BuildNest",
	Procedure = DFA_FLOAT,
	Directions = 2,
	FlipDir = 1,
	Length = 20,
	Delay = 2,
	X = 0,
	Y = 24,
	Wdt = 14,
	Hgt = 12,
	NextAction = "BuildNest",
	PhaseCall = "BirdDoBuildNest",
},

Sit = {
	Prototype = Action,
	Name = "Sit",
	Procedure = DFA_FLOAT,
	Directions = 2,
	FlipDir = 1,
	Length = 1,
	Delay = 40,
	X = 96,
	Y = 48,
	Wdt = 14,
	Hgt = 12,
	OffY = 2,
	NextAction = "Sit",
},

Sleep = {
	Prototype = Action,
	Name = "Sleep",
	Procedure = DFA_FLOAT,
	Directions = 2,
	FlipDir = 1,
	Length = 1,
	Delay = 40,
	X = 96,
	Y = 48,
	Wdt = 14,
	Hgt = 12,
	OffY = 3,
	NextAction = "Sleep",
},
};

local Name = "$Name$";
local Description = "$Description$";

public func AvoidHittingLandscape()
{
	if(Contained()) return;

	var dist = GetDefHeight()*2;

	var d_top = 0;
	var d_down = 0;
	var d_top_dir = 0;
	var d_down_dir = 0;

	var tolerance_y = 20;
	//var ydir_max = 10;
	var ydir_change = 1;

	var dx = GetXDir()*15;
	var dist2 = dist + 10*BoundBy(Abs(GetXDir())-3,0,10);
	var d_min = 40;

	// calculate distance to landscape right below the bird
	for(d_top = Abs(GetDefOffset(1)); d_top < dist; d_top++)
	{
		if(GBackSemiSolid(0,-d_top)) break;
	}

	for(d_down = GetDefOffset(1) + GetDefHeight(); d_down < dist; d_down++)
	{
		if(GBackSemiSolid(0,d_down)) break;
	}

	// calculate distance to landscape in movement direction
	for(d_top_dir = Abs(GetDefOffset(1)); d_top_dir < dist2; d_top_dir++)
	{
		if(GBackSemiSolid(dx,-d_top_dir)) break;
	}

	for(d_down_dir = GetDefOffset(1) + GetDefHeight(); d_down_dir < dist2; d_down_dir++)
	{
		if(GBackSemiSolid(dx,d_down_dir)) break;
	}

	// adjust height

	var target_y = GetY()+(d_down-d_top)/2 +BoundBy(+d_min-d_top,0,d_min)-BoundBy(+d_min-d_down,0,d_min);
	var target_y_dir = GetY()+(d_down_dir-d_top_dir)/2 +BoundBy(+d_min-d_top_dir,0,d_min)-BoundBy(+d_min-d_down_dir,0,d_min);

	var w1, w2;

	if(GetYDir() <= 3)
	{
		w1 = 2;
		w2 = 1;
	}
	else
	{
		w1 = 1;
		w2 = 2;
	}
	target_y = (w1*target_y + w2*target_y_dir)/(w1+w2);

	if(GetY() < target_y - tolerance_y)
	{
		SetYDir(BoundBy(GetYDir()+ydir_change, -7, 7));
	}

	if(GetY() > target_y + tolerance_y)
	{
		SetYDir(BoundBy(GetYDir()-ydir_change, -7, 7));
	}
}

private func GetFeasableHeight(int x)
{
	var height = GetY();

	var safe_distance = GetDefHeight() * 2;

	var found_starting_point = false;

	var top_range, bottom_range;

	// first look for a good point upwards!
	while ( height > safe_distance && !found_starting_point)
	{
		height -= 10;

		if (GBackSemiSolid(x-GetX(),height-GetY())) continue; // actually free where we move
		if (GBackSemiSolid(x-GetX(),height-GetY()+safe_distance)) continue; // keep safe distance to bottom

		if (GetPathLength(GetX(),GetY(), x, height) != nil) // and we can plan to this point!!
			found_starting_point = true;
	}

	if (found_starting_point)
	{
		bottom_range = height;

		while ( height > 0 && !GBackSemiSolid(x-GetX(),height-GetY()))
		{
			height -= 10;
		}

		top_range = height + safe_distance;

		return [top_range, bottom_range];
	}


	// now look for a good point downwards!
	height = GetY();
	while ( height < LandscapeHeight()-safe_distance && !found_starting_point)
	{
		height += 10;

		if (GBackSemiSolid(x-GetX(),height-GetY())) continue; // actually free where we move
		if (GBackSemiSolid(x-GetX(),height-GetY()-safe_distance)) continue; // keep safe distance to top

		if (GetPathLength(GetX(),GetY(), x, height) != nil) // and we can plan to this point!!
			found_starting_point = true;
	}

	if (found_starting_point)
	{
		top_range = height;

		while ( height < LandscapeHeight() && !GBackSemiSolid(x-GetX(),height-GetY()))
		{
			height += 10;
		}

		bottom_range = height - safe_distance;

		return [top_range, bottom_range];
	}

	return nil;
}
