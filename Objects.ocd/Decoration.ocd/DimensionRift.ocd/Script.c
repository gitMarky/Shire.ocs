
func Initialize()
{
	var priority_warp = 4;
	var priority_pulse = 2;
	var priority_growth = 3;
    SetGraphics("2", this, 0, 1);
	var effect = AddEffect("IntWarp", this, priority_warp, 1, this);
	effect.scale = 1000;
	effect.precision = 100;
	effect.dir = -90;
	
	var pulse = AddEffect("IntPulse", this, priority_pulse, 1, this);
	pulse.target = effect;
	pulse.scale = 1000;
	pulse.range = 200;
	
	var growth = AddEffect("IntGrowth", this, priority_growth, 1, this);
	growth.target = effect;
	growth.speed = 40;

    SetGraphics(nil, this, 1, 1);
	effect = AddEffect("IntWarp", this, priority_warp, 1, this);
	effect.scale = 1000;
	effect.precision = 100;
	effect.dir = -110;
	effect.layer = 1;

	pulse = AddEffect("IntPulse", this, priority_pulse, 1, this);
	pulse.target = effect;
	pulse.scale = 1000;
	pulse.range = 100;
	pulse.offset = 300;

	var growth = AddEffect("IntGrowth", this, priority_growth, 1, this);
	growth.target = effect;
	growth.speed = 40;
	
	this.Visibility = VIS_None;
	ScheduleCall(this, "Display", 1);
}

func ShrinkRift()
{
	for (var i = 0, effect = nil; effect = GetEffect("IntWarp", this, i); i++)
	{
		var growth = AddEffect("IntShrink", this, 5, 1, this);
		growth.target = effect;
		growth.speed = 15;
	}
}

func Display()
{
	this.Visibility = VIS_All;
}

func FxIntWarpTimer(object target, proplist effect, int timer)
{
	effect.rot += effect.dir;

	var r_max = 360 * effect.precision;

	while (effect.rot < 0) effect.rot += r_max;
	while (effect.rot > r_max) effect.rot -= r_max;


	SetRotation(effect.rot, effect.precision, effect.layer, effect.scale);
}

func FxIntPulseTimer(object target, proplist effect, int timer)
{
	effect.target.scale = effect.scale + Sin(effect.offset + timer, effect.range);
}

func FxIntGrowthTimer(object target, proplist effect, int timer)
{
	if (effect.progress == 1000)
	{
		return FX_Execute_Kill;
	}
	else
	{
		effect.progress = Min(1000, effect.progress + effect.speed);
		effect.target.scale = effect.progress * effect.target.scale / 1000;
	}
}

func FxIntShrinkTimer(object target, proplist effect, int timer)
{
	if (effect.progress == 1000)
	{
		return FX_Execute_Kill;
	}
	else
	{
		effect.progress = Min(1000, effect.progress + effect.speed);
		effect.target.scale = (1000 - effect.progress) * effect.target.scale / 1000;
	}
}

func SetRotation (int r, int precision, int layer, int scale)
{
    if (!scale) scale = 1000;
	
    var fsin=Sin(r, scale, precision);
    var fcos=Cos(r, scale, precision);
    // set matrix values
    SetObjDrawTransform(+fcos, +fsin, 0,
                        -fsin, +fcos, 0, layer);
}