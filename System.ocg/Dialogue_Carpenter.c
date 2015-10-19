#include Library_Dialogue
#appendto Library_Dialogue

public func Dlg_Carpenter(object player)
{
	var has_dialogue_crowbar = player.dlg_pirat_get_quest == DIALOGUE_Pirat_QuestWaiting
	                       && !player.dialogue_carpenter_crowbar;


	if (has_dialogue_crowbar)
	{
		DlgText("Hast Du zufaellig ein Brecheisen da?", player);
		DlgText("Na, denk doch mal nach,|ein Bauarbeiter hat immer sein Handwerkszeug dabei.");
		DlgText("Kannst Du es mir mal leihen?", player);
		DlgText("Hier ist es.");
		if (DlgEvent())
		{
			player->CreateContents(Crowbar);
			player.dialogue_carpenter_crowbar = true;
		}
		DlgText("Danke.", player);
	}
	else
	{
		DlgText("Hi, wie geht es dir?", player);
		DlgText("Lass mich in Ruhe ich muss arbeiten.");
		DlgText("Woran arbeitest Du gerade?", player);
		DlgText("An diesem Haus hier. Im Auftrag von Iolos Vater.");
		DlgText("Wir sehen uns.", player);
	}
}
