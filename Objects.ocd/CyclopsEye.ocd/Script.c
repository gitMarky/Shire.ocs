
private func Initialize()
{
	this.inventory = FindObjects(Find_Container(enemy_cyclops), Find_Layer(enemy_cyclops));
}

// can be hit by all projectiles
public func IsProjectileTarget(){ return true; }

public func Damage(int change, int cause)
{
	if (!enemy_cyclops)
	{
		return RemoveObject();
	}
	
	if (!GetEffect("IntDamageFlash", enemy_cyclops)) AddEffect("IntDamageFlash", enemy_cyclops->FindContents(Club), 1, 1, this);
	enemy_cyclops->DoEnergy(-change);
	
	if (!(enemy_cyclops->GetAlive()))
	{
		SetPosition();

		var tarydium = FindObject(Find_ID(Tarydium));
		CreateObject(Dummy, tarydium->GetX(), tarydium->GetY())->Explode(8);
		
		if (this.inventory)
		{
			for (var item in this.inventory)
			{
				if (item) //item->Enter(enemy_cyclops);//item->RemoveObject();
					ScheduleCall(item, item.Enter, 1, nil, enemy_cyclops);
			}
		}

		enemy_cyclops->Sound("MonsterDie");
		RemoveObject();
	}
	else
	{
		enemy_cyclops->Sound("MonsterGrowl?");
	}
}

private func FxIntDamageFlashTimer(object target, proplist effect, int timer)
{
	var middle = 5;
	if (!enemy_cyclops || timer > 4 * middle)
	{
		return FX_Execute_Kill;
	}

	var y2 = GetProgress(timer, middle); // phase 31 to 50: 10 to 0
	      
    var y1 = middle - y2;
    
    var r, g, b;
    r = 255;
    g = b = (y1 * 255 + y2 * 150) / middle;
    
    var modulation = RGB(r, g, b);
    var head = enemy_cyclops->FindContents(CyclopsHead);
    enemy_cyclops->SetClrModulation(modulation);
    if (head) head->SetClrModulation(modulation);
}

private func GetProgress(int timer, int middle)
{
      return Min(timer, middle)              // phase  0 to 10:  0 to 10
	       - Min(Max(0, timer - middle), middle)     // phase 11 to 20: 10 to 0
	       + Min(Max(0, timer - 2 * middle), middle) // phase 21 to 30:  0 to 10
	       - Min(Max(0, timer - 3 * middle), middle);
}