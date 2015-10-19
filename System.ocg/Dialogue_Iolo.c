#include Library_Dialogue
#appendto Library_Dialogue

public func Dlg_Iolo(object player)
{
	var has_dialogue_arrow = player.dialogue_iolo_arrow
	                     && !player.dialogue_iolo_has_arrow;
	                     
	var has_dialogue_elevator = GetActiveSequence()
		                     && GetActiveSequence().seq_name == "Iolo_Elevator";
	
	                     
	if (has_dialogue_arrow)
	{
		var arrows = player->FindContents(BombArrow);
		DlgText("Hast Du schon einen Sprengpfeil?");
		if (arrows)
		{
			DlgText("Ja, hier.", player);
			DlgText("Ok, dann komm mit!");
			if (DlgEvent())
			{
				arrows->RemoveObject();
				player.dialogue_iolo_has_arrow = true;
				StartSequence("Iolo_Elevator", 0, this, player);
			}
		}
		else
		{
			DlgText("Nein, leider noch nicht.", player);
		}
	}
	else if (has_dialogue_elevator)
	{
		DlgText("So, jetzt kannst Du den Aufzug benutzen.");
		DlgText("Danke, Iolo!", player);
		if (DlgEvent())
		{
			StopSequence();
		}
	}
	else
	{
		DlgText("Hey, was machst Du hier?");
		DlgText("Ich sehe mich nur um.", player);
		DlgText("Geh raus aus meinem Zimmer!");
	}
}
