#include Library_Dialogue
#appendto Library_Dialogue

public func Dlg_Doctor(object player)
{
	DlgText("Hallo? Sind Sie wieder bei Bewusstsein?");
	DlgText("Wo bin ich?", player);
	DlgText("Sie leben.");
	DlgText("Sie haben Glueck gehabt.|Es grenzt fast an ein Wunder,|dass Sie den Unfall unbeschadet ueberstanden haben.");
	DlgText("Sie waren etwa 10 Minuten bewusstlos.");
	DlgText("Was? Nur 10 Minuten?", player);
	DlgText("Ich... hatte...einen merkwuerdigen...Traum.", player);
	DlgText("Wo ist denn mein roter Pullover?", player);
	if (DlgEvent())
	{
		GameOver();		
	}
}
