
local thrust;

func Initialize()
{
	SetAction("Land");
}


func ActivateEntrance(object controller)
{
	var tarydium = controller->FindContents(Tarydium);

	if (!this.fuel)
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
	else if (!dimension_rift)
	{
		Dialogue->MessageBox("Jetzt habe ich ein Fahrzeug, aber ich habe noch keinen Weg in meine eigene Welt gefunden...", controller, controller);
		controller->SetCommand("None");
	}
	else
	{
        if (GetAction() != "OpenDoor"
         && GetAction() != "DoorOpen"
         && GetAction() != "Fly")
         {
         	SetAction("OpenDoor");
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
	TakeOff();
}


func TakeOff()
{
	SetYDir(-20);
	SetDir(DIR_Right);
	ScheduleCall(this, "SetAction", 10, 0, "Fly");
	Sound("Energize");
}

func Fly()
{
	ApproachRift();

	SetDir(DIR_Right);

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
	
//	var pos = [300, 600, 900];
	var pos = [100, 300, 600];
	
		particles.R = PV_KeyFrames(0, 0,   0, pos[0],  0, pos[1], 244, pos[2], 252);
		particles.G = PV_KeyFrames(0, 0,   0, pos[0], 80, pos[1],   0, pos[2], 244);
		particles.B = PV_KeyFrames(0, 0, 152, pos[0],  0, pos[1],   0, pos[2],   8);

	particles.Size = PV_Linear(PV_Random(level/2, level), PV_Random(2 * level, 3 * level));
	CreateParticle("Smoke", x, y, PV_Random(-level/3, level/3), PV_Random(-level/2, -level/3), PV_Random(level * 2, level * 10), particles, BoundBy(level/5, 3, 20));
}

func ApproachRift()
{
	if (!dimension_rift) return;
	
	var target_r = Angle(GetX(), GetY(), dimension_rift->GetX(), dimension_rift->GetY());
	var actual_r = GetR() + 90;
	var dist = Distance(GetX(), GetY(), dimension_rift->GetX(), dimension_rift->GetY());
	var max_thrust = 300;
	var min_thrust = 30;
	
	target_r = Normalize(target_r, -180);
	actual_r = Normalize(actual_r, -180);

	if (target_r < actual_r)
	{
		SetRDir(-2, 100);
	}
	else
	{
		SetRDir(+2, 100);
	}
	
	if (Abs(actual_r - target_r) <= 2)
	{
		SetRDir();
		SetR(target_r);
		actual_r = target_r;
	}
	
	if (thrust  < dist)
	{
		thrust = Min(max_thrust, thrust + 5);
	}
	else if (dist < max_thrust / 2)
	{
		thrust = Max(min_thrust, dist * 2);
	}
	
	SetXDir(+Sin(actual_r, thrust), 100);
	SetYDir(-Cos(actual_r, thrust), 100);
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
