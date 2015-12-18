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
		DlgText("$DlgDoorShop01$", player);
	}
	else if (needs_eyepatch)
	{
		var crowbar = player->FindContents(Crowbar);

		if (!crowbar)
		{
			DlgText("$DlgDoorShop02$", player);
			DlgText("$DlgDoorShop03$", player);
		}
		else
		{
			DlgText("$DlgDoorShop04$", player);
			if (DlgEvent())
			{
				crowbar->RemoveObject();
				player.dialogue_shop_open = true;
			}
		}
	}
	else
	{
		DlgText("$DlgDoorShop05$", player);
	}
}
