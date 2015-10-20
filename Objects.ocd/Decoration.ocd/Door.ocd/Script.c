
local Name = "$Name$";
local Description = "$Description$";

local transfer_target;
local is_enabled = true;

func Initialize()
{
	SetAction("DoorClosed");
}

// can we open the door?
public func IsInteractable() { return is_enabled && transfer_target; }

// Called on player interaction.
public func Interact(object target)
{
	if (!GetEffect("IntTransfer", target))
	{
		AddEffect("IntTransfer", target, 1, 1, this, nil);
	}
}

func FxIntTransferTimer(object target, proplist effect, int timer)
{
	if (ObjectDistance(target) > 20 || !transfer_target)
	{
		return FX_Execute_Kill;
	}

	if (GetAction() == "DoorClosed")
	{
		SyncAction("OpenDoor");
	}
	
	if (GetAction() == "DoorOpen")
	{
		Transfer(target);
		return FX_Execute_Kill;
	}
}

func SyncAction(string action)
{
		SetAction(action);
		if (transfer_target) transfer_target->SetAction(action);
}

func Transfer(object target)
{
	target->SetPosition(transfer_target->GetX(), transfer_target->GetY());
}

func ConnectTo(object target)
{
	transfer_target = target;

	if (target.transfer_target != this)
	{
		target->ConnectTo(this);
	}
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
	Direction = 2,
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
	Direction = 2,
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
	Direction = 2,
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
	Direction = 2,
	X = 70,
	Y = 0,
	Wdt = 14,
	Hgt = 17,
	FacetBase = 1,
	NextAction = "DoorClosed",
},

};
