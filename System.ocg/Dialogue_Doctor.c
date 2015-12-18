#include Library_Dialogue
#appendto Library_Dialogue

public func Dlg_Doctor(object player)
{
	DlgText("$DlgDoctor01$");
	DlgText("$DlgDoctor02$", player);
	DlgText("$DlgDoctor03$");
	DlgText("$DlgDoctor04$");
	DlgText("$DlgDoctor05$");
	DlgText("$DlgDoctor06$", player);
	DlgText("$DlgDoctor07$", player);
	DlgText("$DlgDoctor08$", player);
	if (DlgEvent())
	{
		GameOver();		
	}
}
