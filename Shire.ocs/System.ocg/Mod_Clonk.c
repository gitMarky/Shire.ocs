#appendto Clonk

/** Dummy function that replaces the death animation in the player's clonk */
func DoNothing(){}

func GrabShireInfo(object clonk)
{
	for (var property in clonk->GetProperties())
	{
		if (TakeString(property, 0, 8) == "dialogue")
		{
			this[property] = clonk[property];
		}
	}
}