#appendto Library_Dialogue

public func Dlg_Beggar(object player)
{
	var coin = player->FindContents(GoldCoin);
	DlgText("$DlgBeggar01$", player);
	DlgText("$DlgBeggar02$");
	DlgText("$DlgBeggar03$");
	if (!coin)
	{
		DlgText("$DlgBeggar04$", player);
	}
	else
	{
		DlgText("$DlgBeggar05$", player);
		if (DlgEvent())
		{
			coin->RemoveObject();
		}
		DlgText("$DlgBeggar06$");
	}
}
