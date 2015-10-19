#appendto Sequence


func Iolo_Elevator_Init()
{
	npc_iolo->SetPosition(npc_iolos_father->GetX() - 20, npc_iolos_father->GetY());

	if (!npc_iolo->FindContents(Bow))
	{
		npc_iolo->CreateContents(Bow);
	}

	if (!npc_iolo->FindContents(BombArrow))
	{
		npc_iolo->CreateContents(BombArrow);
	}
	
	this.elevator_case = FindObject(Find_ID(ElevatorCase));
	
}

func Iolo_Elevator_Start(object dialogue, object hero)
{
	this.dialogue = dialogue;
	this.hero = hero;

	SetViewTarget(npc_iolo);
	
	return ScheduleNext(50);
}

func Iolo_Elevator_1()
{
	npc_iolo->SetCommand("MoveTo", nil, 1144, 1020);
	this.hero->SetCommand("MoveTo", nil, 1120, 1020);
	return ScheduleNext(50);
}

func Iolo_Elevator_2()
{
	if (npc_iolo->GetCommand() == "MoveTo"
	 || this.hero->GetCommand() == "MoveTo")
	{
		return ScheduleSame(1);
	}
	return ScheduleNext(10);
}

func Iolo_Elevator_3()
{
	var aim_x = 17;
	var aim_y = -77;

	// loads and fires the bow
	this.bow = npc_iolo->FindContents(Bow);
	this.bow->ControlUseStart(npc_iolo, aim_x, aim_y);
	this.bow->ControlUseStop(npc_iolo, aim_x, aim_y);
	return ScheduleNext(1);
}

func Iolo_Elevator_4()
{
	var arrow = FindObject(Find_ID(BombArrow), Find_NoContainer());
	if (!arrow)
	{
		return ScheduleSame(1);
	}
	else
	{
		SetViewTarget(arrow);
		var strength = 120; // make Iolo's arrow a little faster, so that it hits the top
		var angle = 1445;
		var precision = 100;
		arrow->SetXDir(Sin(angle, strength, precision));
		arrow->SetYDir(Cos(angle, -strength, precision));
		return ScheduleNext(1);
	}
}

func Iolo_Elevator_5()
{
	var arrow = FindObject(Find_ID(BombArrow), Find_NoContainer());
	if (arrow)
	{
		return ScheduleSame(1);
	}
	else
	{
		var elevator = FindObject(Find_ID(Elevator));
		SetViewTarget(elevator);
		ShakeFree(1255, 770, 20); 
		Sound("Earthquake");
		return ScheduleNext(10);
	}
}

func Iolo_Elevator_6()
{
	Iolo_Elevator_DigShaft();
	this.elevator_case->ControlUp(this.hero);

	ShakeViewport(30, 1253, 740);
	for (var y = 720; y < 761; y+=10)
	{
		ShakeFree(1256, y, 12);
	}
	
	// TODO: mystery sound
	return ScheduleNext(50);
}

func Iolo_Elevator_7()
{
	this.elevator_case->ControlDown(this.hero);
	return ScheduleNext(10);
}

func Iolo_Elevator_8()
{
	// dig again in case something got stuck
	Iolo_Elevator_DigShaft();
	this.elevator_case->ControlDown(this.hero);
	// so that the elevator lands on a flat surface
	DigFreeRect(1225, 1000, 60, 37, true);
	return ScheduleNext(30);
}

func Iolo_Elevator_9()
{
	SetViewTarget(this.hero);
	this.dialogue->Interact(this.hero);
	return ScheduleNext(10);
}

func Iolo_Elevator_10() // dummy phase
{
	return ScheduleSame(50);
}

func Iolo_Elevator_Stop()
{
	return true;
}

func Iolo_Elevator_DigShaft()
{
	var x = this.elevator_case->GetX();
	var y = this.elevator_case->GetY();
	this.elevator_case->SetPosition();
	DigFreeRect(1244, 720, 24, 60); // the shaft itself
	this.elevator_case->SetPosition(x, y);
}
