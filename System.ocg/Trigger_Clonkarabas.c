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
		AddEffect("CanBeEnchanted", this.clonkarabas, 1);
		
		this.staff = this.clonkarabas->CreateContents(WizardStaff);
		this.staff->SetMeshMaterial("Wizard_Staff_Clonkarabas");
		this.staff->Disable();
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
	if (!GetActiveSequence() && GetEffect("Enchanted", this.clonkarabas))
	{
		this.staff->FadeOut(48, true);
		this.clonkarabas->FadeOut(50, true);
		StartSequence("Clonkarabas", 12, this.clonkarabas);
		return Stop();
	}
	else // clonkarabas shoots at clonk
	{
		var dx = this.hero->GetX() - this.clonkarabas->GetX();
		var dy = this.hero->GetY() - this.clonkarabas->GetY();

		if (ObjectDistance(this.hero, this.clonkarabas) < 300)
		{
			if (!this.clonkarabas->IsAiming())
			{
				this.staff->ControlUseStart(this.clonkarabas, dx, dy);
			}
			else
			{
				this.staff->ControlUseHolding(this.clonkarabas, dx, dy);
			}
			
			var reach = 90;
			
			// effects
			if (ObjectDistance(this.hero, this.clonkarabas) < reach)
			{
				var angle = Angle(0, 0, dx, dy);
				var sx = +Sin(angle, 15);
				var sy = -Cos(angle, 15);
				sy -= 3;

				var fuzzy = 10;
				var velocity = 2 * reach / 3; // should take 20 frames to reach the end
				var vx = +Sin(angle, velocity);
				var vy = -Cos(angle, velocity);
				CreateParticle("Smoke", this.clonkarabas->GetX() + sx, this.clonkarabas->GetY() + sy, PV_Random(vx - fuzzy, vx + fuzzy), PV_Random(vy - fuzzy, vy + fuzzy), PV_Random(15, 20), Particles_Smoke(), 10);
			}
			
			// fling the clonk
			if (ObjectDistance(this.hero, this.clonkarabas) < (reach-fuzzy) && this.hero->GetAction() != "Tumble")
			{
				if (this.hero->GetAction() == "Walk")
				{
					this.hero->MovePosition(0, -1);
				}
				this.hero->Fling(vx, vy, 10);
			}
		}
		else if (this.clonkarabas->IsAiming())
		{
			this.staff->ControlUseStop(this.clonkarabas, dx, dy);
		}

		return ScheduleSame(2);
	}
}