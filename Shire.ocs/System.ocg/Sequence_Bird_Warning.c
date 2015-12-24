#appendto Sequence

func Bird_Warning_Start(object hero)
{
	this.hero = hero;
	BirdSetup();
	return ScheduleNext(1);
}

func Bird_Warning_1()
{
	this.bird = CreateObject(Bird, this.hero->GetX(), 970, NO_OWNER);
	this.bird->Sound("Raven?");
	this.bird->SetDir(1);
	this.bird->FadeIn(20);
	BirdSparks();
	return ScheduleNext(30);
}

func Bird_Warning_2()
{
	MessageBoxAll("$SeqBirdWarning01$", this.hero, true);
	return ScheduleNext(this.delay);
}

func Bird_Warning_3()
{
	MessageBoxAll("$SeqBirdWarning02$", this.hero, true);
	return ScheduleNext(this.delay);
}

func Bird_Warning_4()
{
	MessageBoxClearAll();
	this.bird->FadeOut(20, true);
	BirdSparks();

	return ScheduleNext(20);
}

func Bird_Warning_5()
{
	return Stop();
}