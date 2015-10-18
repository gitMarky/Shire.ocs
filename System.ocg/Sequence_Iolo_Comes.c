#appendto Sequence


func Iolo_Comes_Init()
{
}

func Iolo_Comes_Start(object dialogue, object hero)
{
	this.dialogue = dialogue;
	this.hero = hero;

	SetViewTarget(npc_iolo);
	
	return ScheduleNext(50);
}

func Iolo_Comes_1()
{
	npc_iolo->SetPosition(npc_iolos_father->GetX() - 20, npc_iolos_father->GetY());
	return ScheduleNext(50);
}

func Iolo_Comes_2()
{
	// this has to be called in an interaction, then it can stop:
	// the interaction depends on the sequence being active
	this.dialogue->Interact(this.hero);
	return ScheduleNext();
}

func Iolo_Comes_3() // dummy phase
{
	return ScheduleSame(50);
}

func Iolo_Comes_Stop()
{
	return true;
}
