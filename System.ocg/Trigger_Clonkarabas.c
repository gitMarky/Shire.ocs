#appendto BackgroundSequence

func Trigger_Clonkarabas_Init()
{
	this.dust_particles =
	{
		Prototype = Particles_Dust(),
		Size = PV_KeyFrames(0, 0, 0, 100, 10, 1000, 0),
		Alpha = PV_KeyFrames(0, 0, 255, 750, 255, 1000, 0),
		R = 80,
		G = 80,
		B = 125,
	};
	this.flash_particles =
	{ 
		Prototype = Particles_Flash(),
		Size = 12,
	};	
}

func Trigger_Clonkarabas_JoinPlayer(int player)
{
	if (!this.hero)
	{
		this.hero = GetHiRank(player);
	}
}

func ClonkarabasSparks()
{
	if (this.clonkarabas)
	{
		// Create some particles
		this.clonkarabas->CreateParticle("Flash", 0, 0, 0, 0, 8, this.flash_particles);
		this.clonkarabas->CreateParticle("Dust", 0, 0, PV_Random(-10, 10), PV_Random(-10, 10), PV_Random(18, 36), this.dust_particles, 10);
	}
}

func Trigger_Clonkarabas_Start()
{
	return ScheduleNext(30, "Wait");
}

func Trigger_Clonkarabas_Wait()
{
	if (this.hero
	 && this.hero->GetX() < 1070
	 && this.hero->GetY() < 730)
	{
		this.clonkarabas = CreateObject(Clonk, 1000, 725, NO_OWNER);
		this.clonkarabas->SetDir(DIR_Right);
		this.clonkarabas->FadeIn(20);
		ClonkarabasSparks();
		this.sequence = StartSequence("Clonkarabas", 0, this.hero);
		return ScheduleNext(30, "Appear");
	}
	return ScheduleSame(5);
}

func Trigger_Clonkarabas_Appear()
{
	this.dialogue = this.clonkarabas->SetDialogueEx("Clonkarabas");
	this.dialogue->Interact(this.hero);
	return ScheduleNext(1, "WaitDefeat");
}

func Trigger_Clonkarabas_WaitDefeat()
{
	if (GetEffect("Enchanted", this.clonkarabas))
	{
		// TODO: defeat him, maybe a sequence?
		// TODO: remove the barriers
	}
	return ScheduleSame(5);
}