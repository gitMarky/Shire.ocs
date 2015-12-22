#appendto BackgroundSequence


func Intro_Start(object hero, object dialogue)
{
	this.hero = hero;
	this.dialogue = dialogue;
//	this.hero->SetLightRange(0, 0);
//	SetAmbientBrightness(0);
	
//	this.dialogue = this.hero->SetDialogueEx("Intro");
//	this.dialogue->Interact(this.hero);

	return ScheduleNext(1);
}


func Intro_1()
{
	if (this.dialogue) this.dialogue->RemoveObject();
	return ScheduleNext(1);
}


func Intro_2()
{
	if (this.intro_fade < 100)
	{
		this.intro_fade++;
		SetAmbientBrightness(this.intro_fade);
		return ScheduleSame(2);
	}

	SetAmbientBrightness(100);
	this.hero->SetLightRange(300, 50);
	return Stop();
}