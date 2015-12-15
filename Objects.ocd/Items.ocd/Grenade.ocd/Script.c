#include BombArrow

func Initialize()
{
	_inherited(...);
	
	SetR();
	
	var scale_max = 2500;
	var scale_x = 1500;
	this.MeshTransformation = Trans_Mul(Trans_Rotate(90, 0, 0, 1),
	                                    Trans_Scale(scale_x, scale_max, scale_max));
	this.PictureTransformation = Trans_Mul(Trans_Rotate(30, 0, 1, 0),
	                                       Trans_Rotate(60, 0, 0, 1),
	                                       Trans_Scale(1000 * scale_x / scale_max, 1000, 1000));
}

public func IsGrenadeLauncherAmmo() { return true; }
public func MaxStackCount() { return 1; }

public func Fuse(bool unknown)
{
	ScheduleCall(this, "AddHitCheck", 5);
	AddEffect("IntDetonation", this, 1, 1, this);
}

public func AddHitCheck()
{
	AddEffect("HitCheck", this, 1, 1);
	AddEffect("InFlight", this, 1, 1, this);
}

local Name = "$Name$";
local Description = "$Description$";

func FxIntDetonationTimer(object target, proplist effect, int time)
{
	if (time > 8)
	{
		target->Hit();
	}
}