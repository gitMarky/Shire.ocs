
func Initialize()
{
	SetAction("Land");
}


func ActivateEntrance(object controller)
{
	var tarydium = controller->FindContents(Tarydium);
	if (this.fuel)
	{
        if (GetAction() != "OpenDoor"
         && GetAction() != "DoorOpen"
         && GetAction() != "Fly")
         {
         	SetAction("OpenDoor");
     	 }
	}
	else
	{
		if (tarydium)
		{
			tarydium->RemoveObject();
			this.fuel = true;
		}
		else
		{
			Dialogue->MessageBox("Hmm, das Ding braucht wohl noch Treibstoff...", controller, controller);
			controller->SetCommand("None");
		}
	}
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


public func ContainedUp(object clonk)
{
	if (GetAction() == "Land")
	{
		TakeOff();
	}
	else if (GetAction() == "Fly")
	{
	 	SetComDir(COMD_Up);
	}
}


public func ContainedDown(object clonk)
{
	SetComDir(COMD_Down);
}

public func ContainedLeft(object clonk)
{
	SetComDir(COMD_Left);
}

public func ContainedRight(object clonk)
{
	SetComDir(COMD_Right);
}


func TakeOff()
{
	if (this.fuel)
	{
		SetAction("Fly");
		Sound("Energize");
		SetYDir(-30);
	}
}

func Hit()
{
	if(GetAction() == "Fly")
	{
		SetAction("Land");
		Sound("DeEnergize");
	}
}

func Fly()
{
	if (GetComDir() == COMD_Up) SetYDir(-15);
	if (GetComDir() == COMD_Down) SetYDir(10);
	if (GetComDir() == COMD_Left) SetXDir(-20);
	if (GetComDir() == COMD_Right) SetXDir(20);
	if (GetComDir() == COMD_None) SetXDir(0);
	if (GetXDir() > 0)
	{
		SetDir(DIR_Right);
	}
	else
	{
		SetDir(DIR_Left);
	}

	Puff();
}

func Puff()
{
	Sound("Chuff");
	var index = 4 + GetDir();
	SmokeCrazy(GetVertex(index, 0), GetVertex(index, 1), 5 + Random(4));
}

func SmokeCrazy(int x, int y, int level)
{
	level = level ?? 10;
	var particles = Particles_Smoke(false);
	
		particles.R = PV_KeyFrames(0, 0,   0, 300,  0, 600, 244, 900, 252);
		particles.G = PV_KeyFrames(0, 0,   0, 300, 80, 600,   0, 900, 244);
		particles.B = PV_KeyFrames(0, 0, 152, 300,  0, 600,   0, 900,   8);

	particles.Size = PV_Linear(PV_Random(level/2, level), PV_Random(2 * level, 3 * level));
	CreateParticle("Smoke", x, y, PV_Random(-level/3, level/3), PV_Random(-level/2, -level/3), PV_Random(level * 2, level * 10), particles, BoundBy(level/5, 3, 20));
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
	Directions = 2,
	FlipDir = 1,
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
	Directions = 2,
	FlipDir = 1,
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
	NextAction = "Land",
	StartCall = "DoorIsClosed",
	Reverse = 1,
	Directions = 2,
	FlipDir = 1,
},

Fly = {
	Prototype = Action,
	Name = "Fly",
	Procedure = DFA_NONE,
	Length = 1,
	Delay = 1,
	FacetBase = 1,
	NextAction = "Fly",
	StartCall = "Fly",
	Directions = 2,
	FlipDir = 1,
},

Land = {
	Prototype = Action,
	Name = "Land",
	Procedure = DFA_NONE,
	Delay = 1,
	FacetBase = 1,
	NextAction = "Land",
	ObjectDisabled = 1,
	Directions = 2,
	FlipDir = 1,
},

};
