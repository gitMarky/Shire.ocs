/*
	Flag
	Author: Marky

	High resolution version of the original flag :)
*/

private func Flying()
{
	SetDir(BoundBy(GetWind()/10+4,0,8));
	if (!GetActTime() && GetActionTarget())
	{
		SetCategory(31 & GetActionTarget()->GetCategory());
	}
}

public func Construction()
{
	SetAction("FlyBase");
}

local ActMap = {
FlyBase = {
	Prototype = Action,
	Name = "FlyBase",
	Procedure = DFA_NONE,
	Directions = 9,
	FlipDir = 5,
	Length = 6,
	Delay = 3,
	X = 0,
	Y = 12,
	Wdt = 24,
	Hgt = 12,
	NextAction = "FlyBase",
	StartCall = "Flying",
},
};


local Name = "$Name$";
local Description = "$Description$";
