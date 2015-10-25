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
		return ScheduleNext(30, "WaitMage");	
	}
	return ScheduleSame(5);
}

func Trigger_Bird_Cyclops_WaitMage()
{
	var sequence = GetActiveSequence();
	
	if (sequence && sequence.seq_name == "Bird_Rescue")
	{
		return ScheduleSame(5);
	}
	return ScheduleNext(5, "BoundaryWait");
}

func Trigger_Bird_Cyclops_BoundaryWait()
{
	if (this.hero
 	 && this.hero->GetX() > 2600)
 	{
 		return ScheduleNext(1, "BoundaryReturn");
 	}
 	return ScheduleSame(5);
}

func Trigger_Bird_Cyclops_BoundaryReturn()
{
	if (this.hero
	 && this.hero->GetX() > 2550)
	{
		//this.hero->SetDir(DIR_Left);
		//this.hero->SetComDir(COMD_Left);
		if (this.hero->GetCommand() != "MoveTo")
		{
			this.hero->SetCommand("MoveTo", nil, 2545, this.hero->GetY());
		}
		Dialogue->MessageBoxAll("Der Magier hat recht,|der Zyklop wird mich umbringen!", this.hero, true);
		return ScheduleSame(1);
	}

	this.hero->SetComDir(COMD_Stop);
	return ScheduleNext(1, "BoundaryWait");
}
