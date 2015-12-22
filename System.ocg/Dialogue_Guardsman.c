#include Library_Dialogue
#appendto Library_Dialogue

public func Dlg_Guardsman(object player)
{
	var has_dialogue_elevator = player.dialogue_pea_east // pea told player to go east
	                        && !player.dialogue_guardsman_elevator; // did not tell the player about the elevator yet
	var has_dialogue_need_arrow = player.dialogue_iolo_arrow // iolo needs an arrow
	                          && !player.dialogue_guardsman_asked_tflint; // did not ask about the t-flint yet.
	var has_dialogue_give_flint = player.dialogue_guardsman_asked_tflint // guardsman asked to give him the flint
	                          && !player.dialogue_guardsman_gave_tflint; // did not give the t-flint to the guardsman yet.
	var has_dialogue_go_east = player.dialogue_guardsman_gave_tflint;
	var has_dialogue_crowbar = player.dialogue_pirat_get_quest == DIALOGUE_Pirat_QuestWaiting
	                       && !player.dialogue_carpenter_crowbar;


	if (has_dialogue_elevator)
	{
		DlgText("$DlgGuardsmanA01$", player);
		DlgText("$DlgGuardsmanA02$");
		DlgText("$DlgGuardsmanA03$", player);
		DlgText("$DlgGuardsmanA04$", player);
		DlgText("$DlgGuardsmanA05$", player);
		DlgText("$DlgGuardsmanA06$");
		DlgText("$DlgGuardsmanA07$");
		DlgText("$DlgGuardsmanA08$", player);
		DlgText("$DlgGuardsmanA09$");
		DlgText("$DlgGuardsmanA10$", player);
		DlgText("$DlgGuardsmanA11$");
		DlgText("$DlgGuardsmanA12$");
		if (DlgEvent())
		{
			player.dialogue_guardsman_elevator = true; // gives new dialogue in iolo's father
		}
	}
	else if (has_dialogue_need_arrow)
	{
		DlgText("$DlgGuardsmanB01$", player);
		DlgText("$DlgGuardsmanB02$", player);
		DlgText("$DlgGuardsmanB03$");
		DlgText("$DlgGuardsmanB04$");
		DlgText("$DlgGuardsmanB05$");
		DlgText("$DlgGuardsmanB06$");
		if (DlgEvent())
		{
			player.dialogue_guardsman_asked_tflint = true;
		}
	}
	else if (has_dialogue_give_flint)
	{
		var tflint = player->FindContents(TFlint);
		if (tflint)
		{
			DlgText("$DlgGuardsmanC01$", player);
			DlgText("$DlgGuardsmanC02$");
			DlgText("$DlgGuardsmanC03$");
			if (DlgEvent())
			{
				tflint->RemoveObject();
				player.dialogue_guardsman_gave_tflint = true;
			}
		}
		else
		{
			DlgText("$DlgGuardsmanC04$", player);
			DlgText("$DlgGuardsmanC05$");
		}
	}
	else if (has_dialogue_crowbar)
	{
		DlgText("$DlgGuardsmanD01$", player);
		DlgText("$DlgGuardsmanD02$");
	}
	else // default dialogue
	{
		DlgText("$DlgGuardsmanE01$", player);
		if (has_dialogue_go_east) DlgText("$DlgGuardsmanE02$");
		                     else DlgText("$DlgGuardsmanE03$");
		DlgText("$DlgGuardsmanE04$", player);
		DlgText("$DlgGuardsmanE05$");
	}
}
