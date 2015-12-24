#appendto Club

// giant club for the cyclops
func DoStrike(clonk, angle)
{
	var reach = 15;
	var range = 25;
	// hit all objects in the direction of the Clonk - the angle is only important for the direction of the flinging
	var x = Sin(angle, range);
	var y = -Cos(angle, range);
	var found = false;
	for (var obj in FindObjects(Find_Distance(reach + range, 0, 0), Find_Or(Find_OCF(OCF_Alive), Find_Category(C4D_Object), Find_Category(C4D_Vehicle)), Find_Exclude(clonk), Find_NoContainer(), Find_Layer(0), Sort_Distance()))
	{
		if (obj->Stuck()) continue;
		
		// don't hit objects behind the Clonk
		if (x < 0)
		{
			if (obj->GetX() > GetX()) continue;
		}
		else if (obj->GetX() < GetX()) continue;
		
		
		// vehicles are only hit if they are pseudo vehicles. Bad system - has to be changed in the future
		if (obj->GetCategory() & C4D_Vehicle)
			if (!GetEffect("HitCheck", obj)) continue;
		
		var en = Format("CannotBeHitTwiceBy%d", this->ObjectNumber());
		if (GetEffect(en, obj)) continue;
		
		if (obj->GetOCF() & OCF_Alive)
		{
			ApplyWeaponBash(obj, 400, angle, clonk);
			if (cyclops_dangerous)
			{
				var damage=15*1000;
				obj->DoEnergy(-damage, true, FX_Call_EngGetPunched, clonk->GetOwner());
			}
			else
			{
				obj.hurt_by_cyclops = true;
			}
		}
		else
		{
			var div=100;
			if(obj->GetContact(-1)) div*=10;
			
			// the better you hit, the more power you have
			var precision = BoundBy(Distance(obj->GetX(), obj->GetY(), GetX() + x, GetY() + y), 1, reach);
			
			// mass/size factor
			var fac1 = 10000/Max(2, obj->GetMass());
			var fac2 = BoundBy(10-Abs(obj->GetDefCoreVal("Width", "DefCore")-obj->GetDefCoreVal("Height", "DefCore")), 1, 10);
			var speed = (3000 * fac1 * fac2) / 2 / 1000 / precision;
			obj->SetXDir((obj->GetXDir(100) + Sin(angle, speed)) / 2, div);
			obj->SetYDir((obj->GetYDir(100) - Cos(angle, speed)) / 2, div);
		}
		AddEffect(en, obj, 1, 15, nil);
		found=true;
		break;
	}
	
	if (found)
		RemoveEffect("DuringClubShoot", clonk);
}
