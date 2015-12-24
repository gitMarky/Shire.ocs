#include Library_Dialogue
#appendto Library_Dialogue

public func Dlg_Quimby(object player)
{
	var bottle_of_smett = player->FindContents(sMett);

	if (!player.dialogue_quimby_asked_smett)
	{
		DlgText("$DlgQuimby01$", player);
		DlgText("$DlgQuimby02$");
		DlgText("$DlgQuimby03$");
		DlgText("$DlgQuimby04$", player);
		DlgText("$DlgQuimby05$");
		DlgText("$DlgQuimby06$", player);
		DlgText("$DlgQuimby07$");
		DlgText("$DlgQuimby08$");
		DlgText("$DlgQuimby09$", player);
		if (DlgEvent())
		{
			player.dialogue_quimby_asked_smett = true;
		}
	}
	else if (!bottle_of_smett)
	{
		DlgText("$DlgQuimby10$");
		DlgText("$DlgQuimby11$", player);
	}
	else if (!player.dialogue_quimby_gave_smett)
	{
		DlgText("$DlgQuimby12$", player);
		DlgText("$DlgQuimby13$");
		DlgText("$DlgQuimby14$");
		DlgText("$DlgQuimby15$");
		if (DlgEvent())
		{
			bottle_of_smett->RemoveObject();
			player->CreateContents(WizardStaff);
			player.dialogue_quimby_gave_smett = true;
		}
		DlgText("$DlgQuimby16$", player);
	}
	else
	{
		DlgText("$DlgQuimby17$");
		DlgText("$DlgQuimby18$", player);
	}
}
