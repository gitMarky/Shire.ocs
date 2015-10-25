#appendto BackgroundSequence

func Trigger_Bird_Cyclops_Start()
{
	return ScheduleNext(30, "Wait");
}

func Trigger_Bird_Cyclops_JoinPlayer(int player)
{
	if (!this.hero)
	{
		this.hero = GetHiRank(player);
	}
}


func Trigger_Bird_Cyclops_Wait()
{
	if (this.hero
	 && this.hero->GetX() > 2450)
	{
		StartSequence("Bird_Warning", 0, this.hero);
		return ScheduleNext(30, "WaitRescue");
	}
	return ScheduleSame(5);
}

func Trigger_Bird_Cyclops_WaitRescue()
{
	if (this.hero
	 && this.hero->GetX() > 2770)
	{
		StartSequence("Bird_Rescue", 0, this.hero);
		return Stop();	
	}
	return ScheduleSame(5);
}
