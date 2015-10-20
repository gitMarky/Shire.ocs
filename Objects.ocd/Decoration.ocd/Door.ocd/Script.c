
local Name = "$Name$";
local Description = "$Description$";

func Initialize()
{
	SetAction("DoorClosed");
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// actions

local ActMap = {
OpenDoor = {
	Prototype = Action,
	Procedure = DFA_NONE,
	Name = "OpenDoor",
	Length = 3,
	Delay = 2,
	X = 28,
	Y = 0,
	Wdt = 14,
	Hgt = 17,
	FacetBase = 1,
	NextAction = "DoorOpen",
	Reverse = 1,
},

DoorOpen = {
	Prototype = Action,
	Procedure = DFA_NONE,
	Name = "DoorOpen",
	Delay = 20,
	X = 14,
	Y = 0,
	Wdt = 14,
	Hgt = 17,
	FacetBase = 1,
	NextAction = "CloseDoor",
	StartCall = "OpenEntrance",
	EndCall = "CloseEntrance",
},

CloseDoor = {
	Prototype = Action,
	Procedure = DFA_NONE,
	Name = "CloseDoor",
	Length = 3,
	Delay = 2,
	X = 28,
	Y = 0,
	Wdt = 14,
	Hgt = 17,
	FacetBase = 1,
	NextAction = "DoorClosed",
},

DoorClosed = {
	Prototype = Action,
	Procedure = DFA_NONE,
	Name = "DoorClosed",
	Delay = 1,
	X = 70,
	Y = 0,
	Wdt = 14,
	Hgt = 17,
	FacetBase = 1,
	NextAction = "DoorClosed",
},

};
