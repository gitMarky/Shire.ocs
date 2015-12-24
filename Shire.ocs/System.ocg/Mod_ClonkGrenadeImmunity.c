#appendto Clonk

public func QueryCatchBlow(object damager)
{
	// immune to grenades
	if (damager->GetID() == Grenade)
	{
		return true;
	}
	else
	{
		return _inherited(damager);
	}
}