#appendto GrenadeLauncher

// Callback from the clonk, when he actually has stopped aiming
public func FinishedAiming(object clonk, int angle)
{
	if(!loaded) return;

	if (ObjectDistance(enemy_cyclops, clonk) > 180)
	{
		Dialogue->MessageBox("Hier ist nichts, was ich bek�mpfen muss.", clonk, clonk, clonk->GetOwner(), true);
		return;
	}

	return _inherited(clonk, angle);
}