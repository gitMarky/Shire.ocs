#include Library_Dialogue
#appendto Library_Dialogue

public func Dlg_Iolo(object player)
{
	var has_dialogue_arrow = player.dialogue_iolo_arrow
	                     && !player.dialogue_iolo_has_arrow;
	                     
	var has_dialogue_elevator = GetActiveSequence()
		                     && GetActiveSequence().seq_name == "Iolo_Elevator";
		                     
	var has_dialogue_iolo = player.dialogue_guardsman_elevator // same as in Iolo's father dialogue
	                    && !player.dialogue_iolo_arrow;  // talked to guardsman about the elevator

	
	                     
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
	else if (has_dialogue_iolo)
	{
		var in_sequence = GetActiveSequence()
		               && GetActiveSequence().seq_name == "Iolo_Comes";
		if (!in_sequence)
		{
			DlgText("Hey, was machst Du hier?");
			// from father dialoge
			DlgText("Ich wollte nur fragen, ob Du vielleicht so|nett waerest, und mit einem Sprengpfeil...", player);
			DlgText("...den alten Fahrstuhl freisprengst.", player);
			DlgText("Damit ich nach Osten kann.|Ich will ja eigentlich nur so schnell wie moeglich|aus diesem Traum raus.", player);
			DlgText("Klar bin ich dabei!|Endlich passiert mal was in diesem Kaff.|Endlich Abenteuer.|Nur Pfeile hab ich nicht.", npc_iolo);
			// end of father dialoge
			DlgText("Komm mit!");
			if (DlgEvent())
			{
				StartSequence("Iolo_Comes", 0, this, player, true);
			}
		}
		else
		{
			DlgText("Also, wenn du mir noch ein paar Pfeile besorgst, dann kann es losgehen!");
			if (DlgEvent())
			{
				player.dialogue_iolo_arrow = true;
				StopSequence();
			}
		}
	}
	else
	{
		DlgText("Hey, was machst Du hier?");
		DlgText("Ich sehe mich nur um.", player);
		DlgText("Geh raus aus meinem Zimmer!");
	}
}
