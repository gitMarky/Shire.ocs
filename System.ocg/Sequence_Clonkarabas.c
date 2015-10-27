#appendto Sequence

func Clonkarabas_Start(object hero)
{
	this.hero = hero;
	return ScheduleNext(1);
}

func Clonkarabas_1() // just wait
{
	return ScheduleSame(100);
}
