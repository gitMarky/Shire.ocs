#appendto BackgroundSequence

func Trigger_Bird_Cyclops_Start()
{
	return ScheduleNext(30, "Wait");
}

func Trigger_Bird_Cyclops_Wait()
{
	if (this.hero
	 && this.hero->GetX() > 2450)
	{
		StartSequence("Bird_Warning");		
		return ScheduleNext(30, "WaitRescue");
	}
	return ScheduleSame(5);
}

func Trigger_Bird_Cyclops_WaitRescue()
{
	if (this.hero
	 && this.hero->GetX() > 2750)
	{
		StartSequence("Bird_Rescue");
		return Stop();	
	}
	return ScheduleSame(5);
}
