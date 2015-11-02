/**
 Bed 
 @author Randrian
 */

local attached_mesh;
local current_animation;

/* Initialize */
protected func Initialize()
{
	this.MeshTransformation = Trans_Rotate(20, 0, 1, 0);
}

private func IsOccupied()
{
	var obj;
	if (obj = FindObject(Find_Container(this), Find_Func("IsClonk")))
	{
		if (!obj->GetAlive())
			return -1;
		return 1;
	}
	return 0;
}

public func IsFree() { return !IsOccupied(); }

protected func ActivateEntrance(object clonk)
{
	// Entry query
	if (!clonk->Contained() )
    if (clonk->GetOCF() & OCF_CrewMember)
		return OnEntrance(clonk);
	// Exit query
	if (clonk->Contained() == this )
		return OnExit(clonk);
	return 0; 
}

private func OnEntrance(object clonk)
{
    // Already occupied
    if (IsOccupied()) return CheckChallenge(clonk);

    // Enter
    clonk->Enter(this);
    if (attached_mesh)
        DetachMesh(attached_mesh);
    attached_mesh = AttachMesh(clonk, "Clonk", "Master", Trans_Scale(1100));
    current_animation = clonk->PlayAnimation("Sleep", CLONK_ANIM_SLOT_Death, Anim_Const(clonk->GetAnimationLength("Sleep")), Anim_Const(1000));
    return 1;
}

private func OnExit(object clonk)
{
	if (attached_mesh)
	{
		DetachMesh(attached_mesh);    
		clonk->StopAnimation(current_animation);
		attached_mesh = nil;
		current_animation = nil;
	}
	clonk->Exit(0,+15);
}

func Zzz()
{
	//var iTime = GetActTime();
	//CreateParticle("Zzz",8*(1-2*GetDir()),-3,2+(iTime%50)*3/25+RandomX(-1,+1),-5,60,
    //             RGBa(255,255,255,128));
}
  
private func CheckChallenge(object clonk)
{
	// Ein feindlicher Clonk von au�en fordert den Insassen
	var enemy = FindObject(Find_OCF(OCF_Alive), Find_Container(this));
	if (enemy)
	{
		OnExit(enemy);
	}
	return false;
}

local ActMap = {
Attach = {
    Prototype = Action,
    Procedure = DFA_ATTACH,
    Delay=0,
},
};

local Name = "$Name$";
local Description = "$Description$";