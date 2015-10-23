#appendto Sequence


func Bird_Elevator_Start(object hero)
{
	this.hero = hero;
	this.delay = 80;
	BirdSetup();

	return ScheduleNext(1);
}


func Bird_Elevator_1()
{
	this.bird = CreateObject(Bird, this.hero->GetX(), 680, NO_OWNER);
	this.bird->Sound("Raven?");
	this.bird->SetDir(1);
	this.bird->FadeIn(20);
	BirdSparks();
	MessageBoxAll("Kraeh, kraeh,|Du solltest nicht nach Osten gehn'.", this.bird, true);
	return ScheduleNext(this.delay);
}

func Bird_Elevator_2()
{
	this.bird->Sound("Raven?");
	MessageBoxAll("Du wirst in Not geraten, kraeh, kraeh...", this.bird, true);
	return ScheduleNext(this.delay);
}
 
func Bird_Elevator_3()
{
	BirdSparks();
	this.bird->FadeOut(20, true);
	MessageBoxAll("Hat da gerade ein Vogel gesprochen?", this.hero, true);
	return ScheduleNext(this.delay);
}

func Bird_Elevator_4()
{
	MessageBoxAll("Das muss ich mir eingebildet haben.", this.hero, true);
	return ScheduleNext(this.delay * 2); // the message takes some time
}

func Bird_Elevator_5()
{
	Stop();
	return true;
}