
func Initialize()
{
    SetGraphics("2", this, 0, 1);
	var effect = AddEffect("IntWarp", this, 1, 1, this);
	effect.scale = 1000;
	effect.precision = 100;
	effect.dir = -45;
	
	var pulse = AddEffect("IntPulse", this, 1, 1, this);
	pulse.target = effect;
	pulse.scale = 1000;
	pulse.range = 200;

    SetGraphics(nil, this, 1, 1);
	effect = AddEffect("IntWarp", this, 1, 1, this);
	effect.scale = 1000;
	effect.precision = 100;
	effect.dir = -45;
	effect.layer = 1;

	pulse = AddEffect("IntPulse", this, 1, 1, this);
	pulse.target = effect;
	pulse.scale = 1000;
	pulse.range = 100;
	pulse.offset = 300;
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

func SetRotation (int r, int precision, int layer, int scale)
{
    if (!scale) scale = 1000;
	
    var fsin=Sin(r, scale, precision);
    var fcos=Cos(r, scale, precision);
    // set matrix values
    SetObjDrawTransform(+fcos, +fsin, 0,
                        -fsin, +fcos, 0, layer);
}