#appendto Sequence

func Rift_Warp_Start(object hero, object dimension_vector)
{
	this.vehicle = dimension_vector;
	this.hero = hero;

	SetViewTarget(dimension_rift);

	return ScheduleNext(1);
}

func Rift_Warp_1()
{
	this.hero->Exit();
	this.hero->SetPosition(2950, 230);
	this.hero->SetDir(DIR_Right);
	
	this.vehicle->FadeOut(60);
	
	dimension_rift->ShrinkRift();
	return ScheduleNext(30);
}

func Rift_Warp_2()
{
	RiftSparks(50);
	return ScheduleNext(20);
}

func Rift_Warp_3()
{
	RiftSparks(20);
	return ScheduleNext(100);
}

func Rift_Warp_4()
{
	SetViewTarget(this.hero);
	return ScheduleNext(30);
}

func Rift_Warp_5()
{
	this.dialogue = npc_doctor->SetDialogueEx("Doctor"); // does not need a stop, because this dialogue ends the game
	this.dialogue->Interact(this.hero);
	return ScheduleNext(1);
}

func Rift_Warp_6() // dummy... 
{
	return ScheduleSame(100);
}
