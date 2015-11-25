#include Plane

func Initialize()
{
	AddEffect("IntPlane", this, 1, 1, this);
	SetAction("Land");
	throttle = 0;
	thrust = 0;
	rdir = 0;
	dir = 0;
	health = 50000;
	SetR();
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
	if (this.fuel)
	{
		SetAction("Fly");
		Sound("Energize");
		SetYDir(-30);
		ScheduleCall(this, "StartInstantFlight", 30, 0, GetR(), 15);
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
//	if (GetComDir() == COMD_Up) SetYDir(-15);
//	if (GetComDir() == COMD_Down) SetYDir(10);
//	if (GetComDir() == COMD_Left) SetXDir(-20);
//	if (GetComDir() == COMD_Right) SetXDir(15);
//	if (GetComDir() == COMD_None) SetXDir(0);
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

private func FxIntPlaneTimer(object target, effect, int timer)
{
	//Lift
	var lift = Distance(0,0,GetXDir(),GetYDir()) / 2;
	if(lift > 20) lift = 20;
	if(throttle < 1) lift = 0;

	if(GetAction() == "Fly")
	{
	//--Ailerons--
		//clockwise
		if(rdir == 1)
			if(GetRDir() < 5) SetRDir(GetRDir() + 3);
		//counter-clockwise
		if(rdir == -1)
			if(GetRDir() > -5) SetRDir(GetRDir() - 3);
		if(rdir == 0) SetRDir();

		//Roll plane to movement direction
		if(throttle > 0)
		{
			if(GetXDir() > 10 && dir != 1) RollPlane(1);
			if(GetXDir() < -10 && dir != 0) RollPlane(0);
		}

		//Vfx
//		var colour = 255 - (GetDamage() * 3);
//		var particles = 
//		{
//			Prototype = Particles_Smoke(),
//			R = colour, G = colour, B = colour,
//			Size = PV_Linear(PV_Random(20, 30), PV_Random(70, 100))
//		};
//		CreateParticle("Smoke", 0, 0, 0, 0, PV_Random(36, 2 * 36), particles, 2);
	}

	//Throttle-to-thrust lag
	if(timer % 10 == 0)
	{
		if(throttle > thrust) ++thrust;
		if(throttle < thrust) --thrust;
	}
	
	//propellor
//	var change = GetAnimationPosition(propanim) + thrust * 3;
//	if(change > GetAnimationLength("Propellor"))
//		change = (GetAnimationPosition(propanim) + thrust * 3) - GetAnimationLength("Propellor");
//	if(change < 0)
//		change = (GetAnimationLength("Propellor") - thrust * 3);
//
//	SetAnimationPosition(propanim, Anim_Const(change));

	//Thrust
	SetXDir(Sin(GetR()+90,thrust) + GetXDir(100), 100);
	SetYDir(-Cos(GetR()+90,thrust) + GetYDir(100) - lift, 100);

	//Drag
	var maxspeed = 40;
	var speed = Distance(0,0,GetXDir(),GetYDir());
	if(speed > 40)
	{
		SetXDir(GetXDir(100)*maxspeed/speed,100);
		SetYDir(GetYDir(100)*maxspeed/speed,100);
	}

	// No pilot? Look for all layers, since an NPC might be in a different layer.
	var pilot = FindObject(Find_OCF(OCF_CrewMember), Find_Container(this), Find_AnyLayer());
	if(!pilot && throttle != 0) CancelFlight();

	//Planes cannot fly underwater!
	if(GBackLiquid())
	{
		if(pilot) Ejection(pilot);
		if(throttle != 0) CancelFlight();
	}

	//Pilot, but no mesh? In case they are scripted into the plane.
//	if(FindContents(Clonk) && !clonkmesh)
//		PlaneMount(FindContents(Clonk));
}

public func StartFlight(int new_throttle)
{
	TakeOff();
	_inherited(...);
}
