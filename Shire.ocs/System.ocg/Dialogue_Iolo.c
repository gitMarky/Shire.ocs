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
		DlgText("$DlgIoloA01$");
		if (arrows)
		{
			DlgText("$DlgIoloA02$", player);
			DlgText("$DlgIoloA03$");
			if (DlgEvent())
			{
				arrows->RemoveObject();
				player.dialogue_iolo_has_arrow = true;
				StartSequence("Iolo_Elevator", 0, this, player);
			}
		}
		else
		{
			DlgText("$DlgIoloA04$", player);
		}
	}
	else if (has_dialogue_elevator)
	{
		DlgText("$DlgIoloB01$");
		DlgText("$DlgIoloB02$", player);
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
			DlgText("$DlgIoloC01$");
			// from father dialoge
			DlgText("$DlgIoloFatherA10$", player);
			DlgText("$DlgIoloFatherA11$", player);
			DlgText("$DlgIoloFatherA12$", player);
			DlgText("$DlgIoloFatherA13$");
			// end of father dialoge
			DlgText("$DlgIoloC02$");
			if (DlgEvent())
			{
				StartSequence("Iolo_Comes", 0, this, player, true);
			}
		}
		else
		{
			DlgText("$DlgIoloC03$");
			if (DlgEvent())
			{
				player.dialogue_iolo_arrow = true;
				StopSequence();
			}
		}
	}
	else
	{
		DlgText("$DlgIoloD01$");
		DlgText("$DlgIoloD02$", player);
		DlgText("$DlgIoloD03$");
	}
}
