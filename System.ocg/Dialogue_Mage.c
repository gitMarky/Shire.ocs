#include Library_Dialogue
#appendto Library_Dialogue

public func Dlg_Mage(object player)
{
	var knows_mhoram = player.dialogue_mhoram_completed;
	
	if (knows_mhoram)
	{
		DlgText("$DlgMage01$", player);
		DlgText("$DlgMage02$", player);
	}
	else
	{
		DlgText("$DlgMage03$", player);
		DlgText("$DlgMage04$", player);
	}

	DlgText("$DlgMage05$");
	DlgText("$DlgMage06$", player);

	if (knows_mhoram)
	{
		DlgText("$DlgMage07$", player);
	}
	else
	{		
		DlgText("$DlgMage08$", player);
	}

	DlgText("$DlgMage09$");
	DlgText("$DlgMage10$");
	DlgText("$DlgMage11$", player);
	DlgText("$DlgMage12$");
	DlgText("$DlgMage13$");
	DlgText("$DlgMage14$");
	if (DlgEvent())
	{
		GetActiveSequence()->ScheduleNext(40);
	}
}
