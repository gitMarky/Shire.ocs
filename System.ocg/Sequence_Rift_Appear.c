#appendto Sequence


func Rift_Appear_Init()
{
	this.camera = CreateObject(Dummy);
}

func Rift_Appear_Start(object dialogue, object hero)
{
	this.dialogue = dialogue;
	this.hero = hero;

	this.camera->SetPosition(500, 250);
	SetViewTarget(this.camera);

	return ScheduleNext(50);
}

func Rift_Appear_1()
{
	return ScheduleNext(50);
}

func Rift_Appear_2()
{
	dimension_rift = CreateObject(DimensionRift, 500, 250);
	return ScheduleNext(300);
}

func Rift_Appear_3()
{
	return Stop();
}

func Rift_Appear_Stop()
{
	SetViewTarget(this.hero);
	return true;
}
