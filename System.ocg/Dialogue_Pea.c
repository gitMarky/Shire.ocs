#include Library_Dialogue
#appendto Library_Dialogue

public func Dlg_Pea(object player)
{
	var has_dialogue_east = !player.dialogue_pea_east;
	var has_dialogue_tflint = player.dialogue_guardsman_asked_tflint  // talked to guardsman about t-flint
	                      && !player.dialogue_pea_asked_bread;
	var has_dialogue_bread = player.dialogue_pea_asked_bread; // talked about bread
	var has_dialogue_crowbar = player.dlg_pirat_get_quest == DIALOGUE_Pirat_QuestWaiting
	                       && !player.dialogue_carpenter_crowbar;

	if (has_dialogue_east)
	{
		DlgText("$DlgPeaA01$", player);
		DlgText("$DlgPeaA02$");
		DlgText("$DlgPeaA03$");
		DlgText("$DlgPeaA04$", player);
		DlgText("$DlgPeaA05$");
		DlgText("$DlgPeaA06$", player);
		DlgText("$DlgPeaA07$");
		DlgText("$DlgPeaA08$");
		DlgText("$DlgPeaA09$", player);
		DlgText("$DlgPeaA10$");
		DlgText("$DlgPeaA11$", player);
		if (DlgEvent())
		{
			player.dialogue_pea_east = true; // gives new dialogue in guardsman
			// TODO: create kolibri
		}
	}
	else if (has_dialogue_tflint)
	{
		DlgText("$DlgPeaB01$", player);
		DlgText("$DlgPeaB02$");
		DlgText("$DlgPeaB03$");
		DlgText("$DlgPeaB04$");
		DlgText("$DlgPeaB05$", player);
		DlgText("$DlgPeaB06$");
		DlgText("$DlgPeaB07$", player);
		if (DlgEvent())
		{
			player.dialogue_pea_asked_bread = true;
		}
	}
	else if (has_dialogue_bread)
	{
		var bread = player->FindContents(Bread);
		
		if (bread)
		{
			DlgText("$DlgPeaC01$", player);
			DlgText("$DlgPeaC02$");
			if (DlgEvent())
			{
				player.dialogue_pea_gave_bread = true;
				bread->RemoveObject();
				player->CreateContents(TFlint); // this should always fit into the players inventory, because after all he was holding bread before
			}
		}
		else
		{
			DlgText("$DlgPeaC03$", player);
			DlgText("$DlgPeaC04$");
		}
	}
	else if (has_dialogue_crowbar)
	{
		DlgText("$DlgPeaC05$", player);
		DlgText("$DlgPeaC06$");
	}
	else
	{
		DlgText("$DlgPeaC07$", player);
		DlgText("$DlgPeaC08$");
	}
}
