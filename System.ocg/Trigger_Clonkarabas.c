#appendto BackgroundSequence

func Trigger_Clonkarabas_Init()
{
	this.cSmokeR = PV_KeyFrames(0, 0, 100, 500, 10, 1000, 5);
	this.cSmokeG = PV_Linear(0, 5);
	this.cSmokeB = PV_Linear(0, 5);
	this.dust_particles =
	{
		Prototype = Particles_Dust(),
		Size = PV_KeyFrames(0, 0, 0, 100, 10, 1000, 0),
		Alpha = PV_KeyFrames(0, 0, 255, 750, 255, 1000, 0),
		R = this.cSmokeR,
		G = this.cSmokeG,
		B = this.cSmokeB,
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
		this.clonkarabas->SetObjectLayer(this.clonkarabas);
		AddEffect("CanBeEnchanted", this.clonkarabas, 1);
		
		// staff
		this.staff = this.clonkarabas->CreateContents(WizardStaff);
		this.staff->SetMeshMaterial("Wizard_Staff_Clonkarabas");
		this.staff->Disable();
		
		// hat
		var hat = npc_pirate->CreateContents(ClonkarabasHat);
		this.clonkarabas->AttachMesh(hat, "skeleton_head", "Base", Trans_Mul(Trans_Translate(4500, -500, 0),
		                                                                     Trans_Rotate(90, 0, 0, 1),
		                                                                     Trans_Rotate(90, 0, 1, 0),
		                                                                     Trans_Rotate(-30, 1, 0, 0),
		                                                                     Trans_Scale(1500, 1500, 1500)));

		
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
		this.clonkarabas->FindContents(ClonkarabasHat)->FadeOut(48, true);
		this.staff->FadeOut(48, true);
		this.clonkarabas->FadeOut(50, true);
		StartSequence("Clonkarabas", 12, this.clonkarabas);
		return Stop();
	}
	else if (!GetActiveSequence()) // clonkarabas shoots at clonk
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
			var spray_max = 20;
			
			// effects
			if (ObjectDistance(this.hero, this.clonkarabas) < reach)
			{
				this.spraying = Min(spray_max, this.spraying + 1);
				var angle = Angle(0, 0, dx, dy);
				var sx = +Sin(angle, 15);
				var sy = -Cos(angle, 15);
				sy -= 3;

				var fuzzy = 10;
				var velocity = reach; // should take 20 frames to reach the end
				var vx = +Sin(angle, velocity);
				var vy = -Cos(angle, velocity);

				var smoke = Particles_Smoke();
				smoke.R = this.cSmokeR;
				smoke.G = this.cSmokeG;
				smoke.B = this.cSmokeB;
	
				CreateParticle("Smoke", this.clonkarabas->GetX() + sx, this.clonkarabas->GetY() + sy, PV_Random(vx - fuzzy, vx + fuzzy), PV_Random(vy - fuzzy, vy + fuzzy), PV_Random(15, 20), smoke, 3);
				CreateParticle("Smoke", this.clonkarabas->GetX() + sx, this.clonkarabas->GetY() + sy, PV_Random(vx/2 - fuzzy, vx/2 + fuzzy), PV_Random(vy/2 - fuzzy, vy/2 + fuzzy), PV_Random(15, 20), smoke, 3);
			}
			else
			{
				this.spraying = 0;
			}
			
			// fling the clonk
			if (ObjectDistance(this.hero, this.clonkarabas) < (spray_max + this.spraying)*(reach-fuzzy)/(2*spray_max) && this.hero->GetAction() != "Tumble")
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
	}
	return ScheduleSame(2);
}