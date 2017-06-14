#appendto Library_Dialogue

public func Dlg_Scientist(object player)
{
	var has_initial_dialogue = !player.dialogue_scientist_intro;
	var cyclops_alive = enemy_cyclops->GetAlive();
	var has_dimension_dialogue = !player.scientist_dimension;

	if (has_initial_dialogue)
	{
		DlgText("$DlgScientist01$", player);
		DlgText("$DlgScientist02$");
		DlgText("$DlgScientist03$", player);
		DlgText("$DlgScientist04$", player);
		DlgText("$DlgScientist05$");
		DlgText("$DlgScientist06$");
		DlgText("$DlgScientist07$");
		DlgText("$DlgScientist08$");
		DlgText("$DlgScientist09$");
		DlgText("$DlgScientist10$", player);
		DlgText("$DlgScientist11$");
		DlgText("$DlgScientist12$");
		DlgText("$DlgScientist13$");
		if (DlgEvent())
		{
			player.dialogue_scientist_intro = true;
			cyclops_dangerous = true;

			// this is a little more comfortable than walking back and forth
			var chest = CreateObject(Chest);
			AddEffect("IntRespawnGrenades", chest, 1, 300);
			chest->SetPosition(npc_ndo->GetX() + 20, npc_ndo->GetY());
		}
	}
	else if (cyclops_alive)
	{
		DlgText("$DlgScientist14$");
	}
	else if (has_dimension_dialogue)
	{
		DlgText("$DlgScientist15$", player);
		DlgText("$DlgScientist16$");
		DlgText("$DlgScientist17$");
		DlgText("$DlgScientist18$", player);
		DlgText("$DlgScientist19$");
		DlgText("$DlgScientist20$");
		if (DlgEvent())
		{
			player.scientist_dimension = true;
		}
	}
	else
	{
		DlgText("$DlgScientist21$");
	}
}
