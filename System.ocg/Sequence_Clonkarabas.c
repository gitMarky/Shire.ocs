#appendto Sequence

func Clonkarabas_Start(object hero)
{
	this.hero = hero;
	return ScheduleNext(1);
}

func Clonkarabas_1() // just wait
{
	return ScheduleSame(100);
}

func Clonkarabas_13()
{
	if (this.hero) // the 'hero' is clonkarabas in this case
	{
		// effects!	
		var crazy_glimmer = Particles_Glimmer();
		crazy_glimmer.B = 255;
		crazy_glimmer.R = PV_Linear(128,32);
		crazy_glimmer.G = PV_Random(0, 128, 2);

		var size = 20;
		var x = this.hero->GetX();
		var y = this.hero->GetY();
		CreateParticle("StarFlash", PV_Random(x - 5, x + 5), PV_Random(y - 5, y + 5), PV_Random(-size, +size), PV_Random(-2 * size, -size), PV_Random(20, 60), crazy_glimmer, size / 2);
		return ScheduleSame(1);
	
		return ScheduleSame(1);
	}
	return Stop();
}