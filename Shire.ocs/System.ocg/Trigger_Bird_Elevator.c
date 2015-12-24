#appendto BackgroundSequence


func Trigger_Bird_Elevator_Init()
{
}

func Trigger_Bird_Elevator_JoinPlayer(int player)
{
	if (!this.hero)
	{
		this.hero = GetHiRank(player);
	}
}

func Trigger_Bird_Elevator_Start()
{
	return ScheduleNext(30, "Wait");
}

func Trigger_Bird_Elevator_Wait()
{
	if (this.hero
	 && this.hero->GetX() > 1280
	 && this.hero->GetY() < 730)
	{
		return Stop();
	}

	return ScheduleSame(5);
}

func Trigger_Bird_Elevator_Stop()
{
	StartSequence("Bird_Elevator", 0, this.hero);
	return true;
}
