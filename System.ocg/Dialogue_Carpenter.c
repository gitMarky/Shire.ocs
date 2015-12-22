#include Library_Dialogue
#appendto Library_Dialogue

public func Dlg_Carpenter(object player)
{
	var has_dialogue_crowbar = player.dialogue_pirat_get_quest == DIALOGUE_Pirat_QuestWaiting
	                       && !player.dialogue_carpenter_crowbar;


	if (has_dialogue_crowbar)
	{
		DlgText("$DlgCarpenter01$", player);
		DlgText("$DlgCarpenter02$");
		DlgText("$DlgCarpenter03$", player);
		DlgText("$DlgCarpenter04$");
		if (DlgEvent())
		{
			player->CreateContents(Crowbar);
			player.dialogue_carpenter_crowbar = true;
		}
		DlgText("$DlgCarpenter05$", player);
	}
	else
	{
		DlgText("$DlgCarpenter06$", player);
		DlgText("$DlgCarpenter07$");
		DlgText("$DlgCarpenter08$", player);
		DlgText("$DlgCarpenter09$");
		DlgText("$DlgCarpenter10$", player);
	}
}
