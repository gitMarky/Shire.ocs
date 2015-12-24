
#include DecoDoor

local Name = "$Name$";
local Description = "$Description$";

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
	Direction = 2,
	X = 50,
	Y = 0,
	Wdt = 25,
	Hgt = 19,
	FacetBase = 1,
	NextAction = "DoorOpen",
	Reverse = 0,
},

DoorOpen = {
	Prototype = Action,
	Procedure = DFA_NONE,
	Name = "DoorOpen",
	Delay = 20,
	Direction = 2,
	X = 125,
	Y = 0,
	Wdt = 25,
	Hgt = 19,
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
	Direction = 2,
	X = 50,
	Y = 0,
	Wdt = 25,
	Hgt = 19,
	FacetBase = 1,
	NextAction = "DoorClosed",
	Reverse = 1,
},

DoorClosed = {
	Prototype = Action,
	Procedure = DFA_NONE,
	Name = "DoorClosed",
	Delay = 1,
	Direction = 2,
	X = 25,
	Y = 0,
	Wdt = 25,
	Hgt = 19,
	FacetBase = 1,
	NextAction = "DoorClosed",
},

};
