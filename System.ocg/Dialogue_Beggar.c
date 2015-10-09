#include Library_Dialogue
#appendto Library_Dialogue

public func Dlg_Beggar(object player)
{
	var coin = player->FindContents(GoldCoin);
	DlgText("Hallo.", player);
	DlgText("Hallo, Du.");
	DlgText("Hast Du nicht eine Goldmuenze fuer einen armen Kriegsveteranen?");
	if (!coin)
	{
		DlgText("Nein, leider nicht.", player);
	}
	else
	{
		DlgText("Hier eine Goldmuenze.", player);
		if (DlgEvent())
		{
			coin->RemoveObject();
		}
		DlgText("Gott segne Dich.");
	}
}
