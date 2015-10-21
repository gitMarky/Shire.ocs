#include Library_Dialogue
#appendto Library_Dialogue

public func Dlg_DoorShop(object player)
{
	var needs_eyepatch = player.dlg_pirat_get_quest == DIALOGUE_Pirat_QuestWaiting;
	var has_eyepatch = player.dialogue_merchant_pullover;
	var can_enter = player.dialogue_shop_open && !has_eyepatch;

	if (can_enter)
	{
		//door_castle_top->SetEnabled(true);
		door_shop_top->Interact(player);
	}
	else if (has_eyepatch)
	{
		DlgText("Der Haendler ist gluecklich, |und ich habe meine Augenklappe|Da brauch ich nicht mehr rein.", player);
	}
	else if (needs_eyepatch)
	{
		var crowbar = player->FindContents(Crowbar);

		if (!crowbar)
		{
			DlgText("Ein Laden in dem man Kleidung kaufen kann.|Aber er hat geschlossen.", player);
			DlgText("Vielleicht bekomme ich die Tür mit einem Werkzeug auf?", player);
		}
		else
		{
			DlgText("Jetzt habe ich die Tuer aufgebrochen.|Na, der Zweck heiligt die Mittel.", player);
			if (DlgEvent())
			{
				crowbar->RemoveObject();
				player.dialogue_shop_open = true;
			}
		}
	}
	else
	{
		DlgText("Ich brauche jetzt keine neue Kleidung.|Ist doch nur ein Traum!", player);
	}
}
