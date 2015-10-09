#include Library_Dialogue
#appendto Library_Dialogue

public func Dlg_Iolo(object player)
{
	var has_dialogue_arrow = player.dialogue_iolo_arrow
	                     && !player.dialogue_iolo_has_arrow;
	                     
	if (has_dialogue_arrow)
	{
		var arrows = player->FindContents(BombArrow);
		DlgText("Hast Du schon einen Sprengpfeil?");
		if (arrows)
		{
			DlgText("Ja, hier.", player);
			arrows->RemoveObject();
			player.dialogue_iolo_has_arrow = true;
			// TODO: sequence for shooting the elevator
		}
		else
		{
			DlgText("Nein, leider noch nicht.", player);
		}
	}
	else
	{
		DlgText("Hey, was machst Du hier?");
		DlgText("Ich sehe mich nur um.", player);
		DlgText("Geh raus aus meinem Zimmer!");
	}
}
