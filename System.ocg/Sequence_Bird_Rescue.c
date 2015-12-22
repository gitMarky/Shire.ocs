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
	this.bird->RemoveBackpack();
	this.bird->SetMeshMaterial("Clonk_Mage");
	this.staff = this.bird->CreateContents(WizardStaff);
	this.staff->SetMeshMaterial("Wizard_Staff_Mage");
	this.bird->SetShirePortrait("Mage");
	
	// hat
	var hat = this.bird->CreateContents(ClonkarabasHat);
	hat->SetMeshMaterial("mage_hat");
	this.bird->AttachMesh(hat, "skeleton_head", "Base", Trans_Mul(Trans_Translate(4600, 100, 0),
	                                                              Trans_Rotate(90, 0, 0, 1),
	                                                              Trans_Rotate(90, 0, 1, 0),
	                                                              Trans_Rotate(-30, 1, 0, 0),
	                                                              Trans_Scale(1500, 1500, 1500)));
	
	
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
	this.bird->FindContents(ClonkarabasHat)->FadeOut(19, true); // fade the hat faster, so that it does not drop
	this.staff->FadeOut(19, true); // fade the staff faster, so that it does not drop
	this.bird->FadeOut(20, true);
	BirdSparks();
	return Stop();
}
