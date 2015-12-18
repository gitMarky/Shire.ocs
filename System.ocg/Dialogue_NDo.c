#include Library_Dialogue
#appendto Library_Dialogue

public func Dlg_NDo(object player)
{
	if (!player.dialogue_ndo_completed)
	{
		DlgText("$DlgNdo01$", player);
		DlgText("$DlgNdo02$");
		DlgText("$DlgNdo03$", player);
		DlgText("$DlgNdo04$");
		DlgText("$DlgNdo05$", player);
		DlgText("$DlgNdo06$");
		DlgText("$DlgNdo07$");
		DlgText("$DlgNdo08$", player);
		DlgText("$DlgNdo09$");
		DlgText("$DlgNdo10$", player);
		DlgText("$DlgNdo11$", player);
		if (DlgEvent())
		{
			player.dialogue_ndo_completed = true;
		}
	}
	else if (!player.scientist_intro)
	{
		DlgText("$DlgNdo09$");
	}
	else
	{
		DlgText("$DlgNdo12$");
	}
}
