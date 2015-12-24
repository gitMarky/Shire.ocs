
local animation_set;

local MuskUp; local MuskFront; local MuskDown; local MuskOffset;
local disabled;

func Initialize()
{
	//Tweaking options
	MuskUp = 12;
	MuskFront = 13;
	MuskDown = 16;
	MuskOffset = -8;

	animation_set = {
		AimMode         = AIM_Position, // The aiming animation is done by adjusting the animation position to fit the angle
		AnimationAim   = "MusketAimArms",
		AnimationLoad  = "MusketLoadArms",
		LoadTime       = 80,
		AnimationShoot = nil,
		ShootTime      = 20,
		WalkBack        =  0,
	};
	
	this.MeshTransformation = Trans_Rotate(90, 0, 0, 1);
}

public func GetAnimationSet() { return animation_set; }

local aiming;

public func GetCarryMode(clonk) { if(aiming >= 0) return CARRY_HandBack; }
public func GetCarryBone() { return "Javelin"; }
public func GetCarrySpecial(clonk) { if(aiming > 0) return "pos_hand2"; }
public func GetCarryTransform() { return Trans_Mul(Trans_Rotate(90, 0, 0, 1), Trans_Translate(0, -4000 * aiming, 0)); }

public func RejectUse(object clonk)
{
	return !clonk->HasHandAction();
}

public func ControlUseStart(object clonk, int x, int y)
{
	aiming = 1;

	clonk->StartAim(this);

	ControlUseHolding(clonk, x, y);
	
	return 1;
}

public func HoldingEnabled() { return true; }

public func Disable(){ disabled = true; }

func ControlUseHolding(object clonk, ix, iy)
{
	var angle = Angle(0,0,ix,iy);
	angle = Normalize(angle,-180);

	clonk->SetAimPosition(angle);

	return true;
}

protected func ControlUseStop(object clonk, ix, iy)
{
	if(aiming)
		clonk->StopAim();
	return true;
}

// Callback from the clonk, when he actually has stopped aiming
public func FinishedAiming(object clonk, int angle)
{
	FireWeapon(clonk, angle);
//	clonk->CancelAiming(this);
	clonk->StartShoot(this);
	return true;
}

public func ControlUseCancel(object clonk, int x, int y)
{
	clonk->CancelAiming(this);
	return true;
}

public func Reset(clonk)
{
	aiming = 0;
}


private func FireWeapon(object clonk, int angle)
{
	if (disabled) return;

	// calculate offset for shot and effects
	var IX=Sin(180-angle, MuskFront);
	var IY=Cos(180-angle, MuskUp) + MuskOffset;
	if(Abs(Normalize(angle,-180)) > 90)
		IY=Cos(180-angle, MuskDown) + MuskOffset;
	
	// enchantment effect 
	var dx = Sin(angle, 110);
	var dy =-Cos(angle, 110);
	
	var can_enchant = false;
	for (var target in FindObjects(Find_OnLine(IX, IY, IX + dx, IY + dy), Find_ID(Clonk), Find_AnyLayer()))
	{
		var effect = GetEffect("CanBeEnchanted", target);
		if (effect)
		{
			can_enchant = true;
			AddEffect("Enchanted", target, 1);
			RemoveEffect(nil, nil, effect);
			break;
		}
	}
	
	if (!can_enchant)
	{
		Dialogue->MessageBox("Hier ist nichts, was ich verzaubern koennte.", clonk, clonk, clonk->GetOwner(), true);
	}
	else
	{
		Dialogue->MessageBox("Nimm dies, Clonkarabas!!!", clonk, clonk, clonk->GetOwner(), true);
		this->FadeOut(10, true);
	}

	// effects!	
	var crazy_glimmer = Particles_Glimmer();
	crazy_glimmer.B = 255;
	crazy_glimmer.R = PV_Linear(128,32);
	crazy_glimmer.G = PV_Random(0, 128, 2);

	var size = 10;
	var x = Sin(angle, size * 10);
	var y = -Cos(angle, size * 10);
	CreateParticle("StarFlash", IX, IY, PV_Random(x - size, x + size), PV_Random(y - size, y + size), PV_Random(20, 60), crazy_glimmer, size * 10);
	
	var crazy_flash = Particles_Flash();
	crazy_flash.Size = PV_KeyFrames(0, 0, 0, 100 / 4, 160 / 4, 1000 / 4, 0);
	//crazy_flash.B = 255;
	//crazy_flash.G = PV_Linear(128,32);
	//crazy_flash.R = PV_Random(0, 128, 2);
	
	CreateParticle("Flash", IX, IY, 0, 0, 8, crazy_flash);
}

protected func Hit()
{
	Sound("WoodHit?");
}


local Collectible = 1;
local Name = "$Name$";
local Description = "$Description$";
local Rebuy = true;
