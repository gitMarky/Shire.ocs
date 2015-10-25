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
	MessageBoxAll("Schon wieder dieser Vogel.", this.hero, true);
	return ScheduleNext(this.delay);
}

func Bird_Warning_3()
{
	MessageBoxAll("Sieht aus als wuerde er versuchen, mich zu warnen.", this.hero, true);
	return ScheduleNext(this.delay);
}

func Bird_Warning_4()
{
	MessageBoxAll("", this.hero, true);
	this.bird->FadeOut(20, true);
	BirdSparks();

	// Cyclops
	enemy_cyclops = CreateObject(Clonk, 3850, 1280, 0);
	enemy_cyclops->SetCon(400);
	enemy_cyclops->SetObjectLayer(enemy_cyclops);
	enemy_cyclops->SetDir(DIR_Left);
	return ScheduleNext(20);
}

func Bird_Warning_5()
{
	return Stop();
}