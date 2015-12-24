#appendto Sequence


func Iolo_Comes_Init()
{
}

func Iolo_Comes_Start(object dialogue, object hero, bool player_follows)
{
	this.dialogue = dialogue;
	this.hero = hero;
	this.player_follows = player_follows;

	SetViewTarget(npc_iolo);
	
	return ScheduleNext(30);
}

func Iolo_Comes_1()
{
	npc_iolo->SetCommand("MoveTo", door_hut_iolo_low);

	if (this.player_follows)
	{
		this.hero->SetCommand("MoveTo", door_hut_iolo_low);
	}
	return ScheduleNext(5);
}

func Iolo_Comes_2()
{
	if (npc_iolo->GetCommand() == "MoveTo")
	{
		return ScheduleSame(1);
	}

	door_hut_iolo_low->Interact(npc_iolo);
	
	if (this.player_follows)
	{
		return ScheduleNext(30);
	}
	else
	{
		return ScheduleNext(25);
	}
}

func Iolo_Comes_3()
{
	if (this.player_follows)
	{
		if (this.hero->GetCommand() == "MoveTo")
		{
			return ScheduleSame(1);
		}
		
		npc_iolo->SetCommand("MoveTo", nil, npc_iolos_father->GetX() - 20, npc_iolos_father->GetY());
		door_hut_iolo_low->Interact(this.hero);
		return ScheduleNext(15);
	}
	else
	{
		return ScheduleNext(5);
	}
}

func Iolo_Comes_4()
{
	npc_iolo->SetCommand("MoveTo", nil, npc_iolos_father->GetX() - 20, npc_iolos_father->GetY());

	if (this.player_follows)
	{
		this.hero->SetCommand("MoveTo", nil, npc_iolos_father->GetX() - 40, npc_iolos_father->GetY());
	}

	return ScheduleNext(5);
}

func Iolo_Comes_5()
{
	if (npc_iolo->GetCommand() == "MoveTo"
	|| (this.player_follows && this.hero->GetCommand() == "MoveTo"))
	{
		return ScheduleSame(20);
	}
	
	SetViewTarget(this.hero);
	// this has to be called in an interaction, then it can stop:
	// the interaction depends on the sequence being active
	this.dialogue->Interact(this.hero);
	return ScheduleNext(50);
}

func Iolo_Comes_6() // dummy phase
{
	return ScheduleSame(50);
}

func Iolo_Comes_Stop()
{
	return true;
}
