#appendto Sequence


func Bird_Elevator_Start(object hero)
{
	this.hero = hero;
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
	MessageBoxAll("$SeqBirdElevator01$", this.bird, true);
	return ScheduleNext(this.delay);
}

func Bird_Elevator_2()
{
	this.bird->Sound("Raven?");
	MessageBoxAll("$SeqBirdElevator02$", this.bird, true);
	return ScheduleNext(this.delay);
}
 
func Bird_Elevator_3()
{
	BirdSparks();
	this.bird->FadeOut(20, true);
	MessageBoxAll("$SeqBirdElevator03$", this.hero, true);
	return ScheduleNext(this.delay);
}

func Bird_Elevator_4()
{
	MessageBoxAll("$SeqBirdElevator04$", this.hero, true);
	return ScheduleNext(this.delay * 2); // the message takes some time
}

func Bird_Elevator_5()
{
	Stop();
	return true;
}