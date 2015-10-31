func Initialize()
{
    SetAction("Ruhe");
}


func ActivateEntrance()
{ 
    if (ActIdle()) SetAction("OpenDoor");
    return true;
}

func OpenDoorSound()
{
	Sound("SteelGate2");
}

func DoorIsOpen()
{
	SetEntrance(1);
}

func DoorIsClosed()
{
	SetEntrance(0);
	Sound("SteelGate2");
}

//ContainedLeft:
//  if (SEqual(GetAction(),"Idle")) return(1);
//  SetComDir("COMD_Left");
//  return(1);
//ContainedRight:
//  if (SEqual(GetAction(),"Idle")) return(1);
//  SetComDir("COMD_Right");
//  return(1);
//ContainedDown:
//  if (SEqual(GetAction(),"Idle")) return(1);
//  SetComDir("COMD_Down");
//  return(1);
//ContainedUp:
//  if (SEqual(GetAction(),"Idle")) return(Call("TakeOff"));
//  SetComDir("COMD_Up");
//  return(1);

func TakeOff()
{
	SetAction("Fly");
	Sound("Energize");
	SetYDir(-30);
}

func Hit()
{
	if(GetAction() == "Fly")
	{
		SetAction("Idle");
		Sound("DeEnergize");
	}
}

func Fly()
{
	if (GetComDir() == COMD_Up) SetYDir(-15);
	if (GetComDir() == COMD_Down) SetYDir(10);
	if (GetComDir() == COMD_Left) SetXDir(-20);
	if (GetComDir() == COMD_Right) SetXDir(15);
	if (GetComDir() == COMD_None) SetXDir(0);
	Puff();
}

func Puff()
{
	Sound("Chuff");
	Smoke(-19, -27, 5 + Random(4));
}


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
	Length = 4,
	Delay = 1,
	X = 0,
	Y = 70,
	Wdt = 20,
	Hgt = 16,
	OffX = 36,
	OffY = 48,
	FacetBase = 1,
	NextAction = "DoorOpen",
	StartCall = "OpenDoorSound",
},

DoorOpen = {
	Prototype = Action,
	Name = "DoorOpen",
	Delay = 20,
	X = 80,
	Y = 70,
	Wdt = 20,
	Hgt = 16,
	OffX = 36,
	OffY = 48,
	FacetBase = 1,
	NextAction = "CloseDoor",
	StartCall = "DoorIsOpen",
},

CloseDoor = {
	Prototype = Action,
	Name = "CloseDoor",
	Length = 4,
	Delay = 1,
	X = 0,
	Y = 70,
	Wdt = 20,
	Hgt = 16,
	OffX = 36,
	OffY = 48,
	FacetBase = 1,
	NextAction = "Idle",
	StartCall = "DoorIsClosed",
	Reverse = 1,
},

Fly = {
	Prototype = Action,
	Name = "Fly",
	Procedure = DFA_FLOAT,
	Length = 1,
	Delay = 1,
	FacetBase = 1,
	NextAction = "Fly",
	StartCall = "Fly",
},

Ruhe = {
	Prototype = Action,
	Name = "Ruhe",
	Procedure = DFA_NONE,
	Delay = 1,
	FacetBase = 1,
	NextAction = "Ruhe",
	ObjectDisabled = 1,
},

};
