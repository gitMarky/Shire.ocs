#appendto Library_Dialogue

public func Dlg_IolosFather(object player)
{
	var has_dialogue_iolo = player.dialogue_guardsman_elevator
	                    && !player.dialogue_iolo_arrow;  // talked to guardsman about the elevator

	var has_dialogue_crowbar = player.dialogue_pirat_get_quest == DIALOGUE_Pirat_QuestWaiting
	                       && !player.dialogue_carpenter_crowbar
	                       && !player.dialogue_iolos_father_angry;

	var has_final_dialogue = player.dialogue_iolos_father_angry;

	if (has_dialogue_iolo)
	{
		var in_sequence = GetActiveSequence()
		               && GetActiveSequence().seq_name == "Iolo_Comes";
		if (!in_sequence)
		{
			DlgText("$DlgIoloFatherA01$", player);
			DlgText("$DlgIoloFatherA02$");
			DlgText("$DlgIoloFatherA03$");
			DlgText("$DlgIoloFatherA04$");
			DlgText("$DlgIoloFatherA05$");
			DlgText("$DlgIoloFatherA06$");
			DlgText("$DlgIoloFatherA07$");
			if (DlgEvent())
			{
				StartSequence("Iolo_Comes", 0, this, player, false);
			}
		}
		else
		{
			DlgText("$DlgIoloFatherA08$", npc_iolo);
			DlgText("$DlgIoloFatherA09$");
			DlgText("$DlgIoloFatherA10$", player);
			DlgText("$DlgIoloFatherA11$", player);
			DlgText("$DlgIoloFatherA12$", player);
			DlgText("$DlgIoloFatherA13$", npc_iolo);		
			if (DlgEvent())
			{
				player.dialogue_iolo_arrow = true;
				StopSequence();
			}
		}
	}
	else if (has_dialogue_crowbar)
	{
		DlgText("$DlgIoloFatherB01$", player);
		DlgText("$DlgIoloFatherB02$");
		if (DlgEvent())
		{
			player.dialogue_iolos_father_angry = true;
		}
	}
	else if (has_final_dialogue)
	{
		DlgText("$DlgIoloFatherB03$");
	}
	else // default dialogue
	{
		DlgText("$DlgIoloFatherB04$", player);
		DlgText("$DlgIoloFatherB05$");
	}
}
