#appendto Sequence

static const g_DimensionRift_X = 900;
static const g_DimensionRift_Y = 250;

func Rift_Appear_Init()
{
	this.camera = CreateObject(Dummy);
}

func RiftSparks(int radius)
{
	var flash_particles =
	{ 
		Prototype = Particles_Flash(),
		Size = radius,
	};
	
	var alpha = 120;
	
	
	var cSmokeR = PV_KeyFrames(0, 0, 227, 500, 191, 1000, 50);
	var cSmokeG = PV_KeyFrames(0, 0, 170, 500, 200, 1000, 50);
	var cSmokeB = PV_KeyFrames(0, 0, 255, 500, 255, 1000, 50);
	
	if (!Random(2)) // invert order of colors
	{
		cSmokeR = PV_KeyFrames(0, 0, 191, 500, 227, 1000, 50);
		cSmokeG = PV_KeyFrames(0, 0, 200, 500, 170, 1000, 50);
		cSmokeB = PV_KeyFrames(0, 0, 255, 500, 255, 1000, 50);
	}

	var dust_particles =
	{
		Prototype = Particles_Dust(),
		Size = PV_KeyFrames(0, 0, 0, 100, radius, 1000, 0),
		Alpha = PV_KeyFrames(0, 0, alpha, 750, alpha, 1000, 0),
		R = cSmokeR,
		G = cSmokeG,
		B = cSmokeB,
	};

	// Create some particles
	CreateParticle("Dust",  g_DimensionRift_X, g_DimensionRift_Y, PV_Random(-radius / 2, radius / 2), PV_Random(-radius / 2, radius / 2), PV_Random(18, 36), dust_particles, radius);
	CreateParticle("Flash", g_DimensionRift_X, g_DimensionRift_Y, 0, 0, 30, flash_particles);
}


func Rift_Appear_Start(object dialogue, object hero)
{
	this.dialogue = dialogue;
	this.hero = hero;

	this.camera->SetPosition(g_DimensionRift_X, g_DimensionRift_Y);
	SetViewTarget(this.camera);

	return ScheduleNext(70);
}

func Rift_Appear_1()
{
	RiftSparks(25);
	return ScheduleNext(60);
}

func Rift_Appear_2()
{
	RiftSparks(50);
	return ScheduleNext(40);
}

func Rift_Appear_3()
{
	RiftSparks(100);
	return ScheduleNext(20);
}

func Rift_Appear_4()
{
	RiftSparks(150);
	return ScheduleNext(20);
}

func Rift_Appear_5()
{
	dimension_rift = CreateObject(DimensionRift, g_DimensionRift_X, g_DimensionRift_Y);
	return ScheduleNext(400);
}

func Rift_Appear_6()
{
	return Stop();
}

func Rift_Appear_Stop()
{
	SetViewTarget(this.hero);
	return true;
}
