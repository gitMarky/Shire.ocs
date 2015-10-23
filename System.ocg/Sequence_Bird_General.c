#appendto Sequence


func BirdSetup()
{
	this.dust_particles =
	{
		Prototype = Particles_Dust(),
		Size = PV_KeyFrames(0, 0, 0, 100, 10, 1000, 0),
		Alpha = PV_KeyFrames(0, 0, 255, 750, 255, 1000, 0),
		R = 200,
		G = 125,
		B = 125,
	};
	this.flash_particles =
	{ 
		Prototype = Particles_Flash(),
		Size = 12,
	};	
}

func BirdSparks()
{
	if (this.bird)
	{
		// Create some particles
		this.bird->CreateParticle("Flash", 0, 0, 0, 0, 8, this.flash_particles);
		this.bird->CreateParticle("Dust", 0, 0, PV_Random(-10, 10), PV_Random(-10, 10), PV_Random(18, 36), this.dust_particles, 10);
	}
}