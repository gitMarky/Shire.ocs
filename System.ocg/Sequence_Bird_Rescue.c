#appendto Sequence

func Bird_Rescue_Start(object hero)
{
	this.hero = hero;
	BirdSetup();
	return ScheduleNext(1);
}

func Bird_Rescue_1()
{
	// enter mage!
	this.bird = CreateObject(Clonk, this.hero->GetX() + 30, 960, NO_OWNER);
	this.bird->SetDir(DIR_Left);
	this.bird->FadeIn(20);
	this.bird->Sound("Magic");	
	BirdSparks();
	return ScheduleNext(30);
}

func Bird_Rescue_2()
{
	MessageBoxAll("Der Zyklop wird auch Dich toeten,|ich hatte Dich doch gewarnt.", this.bird, true);
	return ScheduleNext(this.delay);
}

func Bird_Rescue_3()
{
	MessageBoxClearAll();
	this.bird->FadeOut(20, false);
	this.hero->FadeOut(20, false);
	BirdSparks();
	return ScheduleNext(20);
}

func Bird_Rescue_4()
{
	this.hero->SetPosition(2540, 1010);
	this.hero->FadeIn(20);
	this.hero->SetDir(DIR_Left);
	this.bird->SetPosition(2510,  960);
	this.bird->FadeIn(20);
	this.bird->Sound("Thunder?");
	this.bird->SetDir(DIR_Right);
	var staff = this.bird->CreateContents(WizardStaff);
	staff->SetMeshMaterial("Wizard_Staff_Mage");
	this.dialogue = this.bird->SetDialogueEx("Mage");	
	BirdSparks();
	CreateObject(Rock, this.hero->GetX(), 950)->Explode(15);
	return ScheduleNext(this.delay);
}

func Bird_Rescue_5()
{
	// dialogue
	MessageBoxClearAll();
	this.dialogue->Interact(this.hero);
	return ScheduleNext(1);
}

func Bird_Rescue_6() // dummy phase, the dialogue continues the sequence once it is closed
{
	return ScheduleSame(100);
}

func Bird_Rescue_7()
{
	DigFreeRect(1040, 705, 200, 30);
	DrawMaterialQuad("Brick-barrier", 600, 735, 1240, 735, 1240, 745, 600, 745);
	
	return ScheduleNext(1);
}

func Bird_Rescue_8()
{
	this.bird->FadeOut(20, true);
	BirdSparks();
	return Stop();
}
