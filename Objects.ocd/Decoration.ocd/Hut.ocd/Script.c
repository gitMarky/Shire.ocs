//ActivateEntrance: 
//  if (Not(ActIdle())) return(1);
//  SetAction("OpenDoor");
//  Sound("DoorOpen");
//  return(1);
//DoorIsOpen:
//  SetEntrance(1);
//  return(1);
//DoorIsClosed:
//  SetEntrance(0);
//  Sound("DoorClose");
//  return(1);
//Shift:
//  if(Not(AssignVar(0,Contents()))) return(1);
//  Exit(Var(0));
//  ForcePosition(Var(0),875,2208);
//  return(Call("Shift"));

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// properties

local Name = "$Name$";
local Description = "$Description$";

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// actions

local ActMap = {
OpenDoor = {
	Prototype = Action,
	Name = "OpenDoor",
	Procedure = DFA_NONE,
	Length = 4,
	Delay = 1,
	X = 60,
	Y = 0,
	Wdt = 13,
	Hgt = 15,
	OffX = 11,
	OffY = 34,
	FacetBase = 1,
	NextAction = "DoorOpen",
},

DoorOpen = {
	Prototype = Action,
	Name = "DoorOpen",
	Procedure = DFA_NONE,
	Delay = 20,
	X = 112,
	Y = 0,
	Wdt = 13,
	Hgt = 15,
	OffX = 11,
	OffY = 34,
	FacetBase = 1,
	NextAction = "CloseDoor",
//	StartCall = "DoorIsOpen",
},

CloseDoor = {
	Prototype = Action,
	Name = "CloseDoor",
	Procedure = DFA_NONE,
	Length = 4,
	Delay = 1,
	X = 60,
	Y = 15,
	Wdt = 13,
	Hgt = 15,
	OffX = 11,
	OffY = 34,
	FacetBase = 1,
	NextAction = "Shift",
//	StartCall = "DoorIsClosed",
},

Shift = {
	Prototype = Action,
	Name = "Shift",
	Procedure = DFA_NONE,
	Length = 1,
	Delay = 1,
	X = 0,
	Y = 0,
	Wdt = 0,
	Hgt = 0,
	OffX = 0,
	OffY = 0,
	FacetBase = 1,
	NextAction = "Idle",
//	StartCall = "Shift",
},

};
