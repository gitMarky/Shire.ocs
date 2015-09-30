#include Library_Dialogue
#appendto Library_Dialogue

public func Dlg_Bauarbeiter(object player)
{
	if (true) //TODO: the actual condition
	{
		DlgText("Hi, wie geht es dir?", player);
		DlgText("Lass mich in Ruhe ich muss arbeiten.");
		DlgText("Woran arbeitest Du gerade?", player);
		DlgText("An diesem Haus hier. Im Auftrag von Iolos Vater.");
		DlgText("Wir sehen uns.", player);
		DlgReset();
	}
	else // this is set in Script103 in the scenario script
	{
		DlgText("Hast Du zufaellig ein Brecheisen da?", player);
		DlgText("Na, denk doch mal nach,|ein Bauarbeiter hat immer sein Handwerkszeug dabei.");
		DlgText("Kannst Du es mir mal leihen?", player);
		DlgText("Hier ist es.");
		if (DlgEvent())
		{
			CreateContents(_BRE, player);
		}
		DlgText("Danke.", player);
		DlgReset();
	}
}
