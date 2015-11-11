/*-- I'm on a boat! --*/


protected func Initialize() { SetAction("OnLand"); }

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// properties

local Name = "$Name$";
local Description = "$Description$";

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// actions

local ActMap = {
OnLand = {
	Prototype = Action,
	Name = "OnLand",
	FacetBase = 1,
	NextAction = "OnLand",
	InLiquidAction = "InWater",
},

InWater = {
	Prototype = Action,
	Name = "InWater",
	Length = 1,
	Delay = 5,
	X = 36,
	Y = 0,
	Wdt = 36,
	Hgt = 44,
	NextAction = "InWater",
},

};
