#include Library_Dialogue
#appendto Library_Dialogue

public func Dlg_Guardsman(object player)
{
	if (!player.dialogue_pea_east)
	{
		DlgText("Hallo.", player);
		DlgText("Hallo. Was willst Du?|Zivilisten haben hier nichts zu suchen.");
		DlgText("Tja, ich weiss nicht genau, was ich suche, aber ich...", player);
		DlgText("Wenn Du nicht weisst, was Du suchst solltest|Du wiederkommen, wenn Du es weisst. ");
	}
	else if (true)
	{
		DlgText("Hallo.", player);
		DlgText("Hallo. Was willst Du?|Zivilisten haben hier nichts zu suchen.");
		DlgText("Ich suche hier aber etwas.", player);
		DlgText("Und zwar suche ich eine Moeglichkeit,|nach Osten zu gelangen.", player);
		DlgText("Mir wurde gesagt, im Osten |vielleicht weiter zu kommen.", player);
		DlgText("Dir wurde bestimmt auch gesagt,|dass man schon lange nicht mehr auf der |andere Seite des Berges war?");
		DlgText("Frueher waren wir oft im Osten,|aber dann wurde der Fahrstuhl verschuettet,|und nun klemmt er und wir koennen nicht mehr hoch.");
		DlgText("Er klemmt fest, sagst Du?", player);
		DlgText("Jawohl!");
		DlgText("Dann muss man ihn freisprengen.", player);
		DlgText("Mmmm... Das ist natuerlich richtig.|Mit einem Sprengpfeil, zum Beispiel.");
		DlgText("Es gibt im Dorf nur einen einzigen Bogenschuetzen,|Iolo ist sein Name.");
		if (DlgEvent())
		{
			player.dialogue_guardsman_elevator = true; // gives new dialogue in iolo's father
		}
	}
	else if (true)
	{
		DlgText("Hallo, nochmal.|Ich wuerde gerne einen Sprengpfeil|aus der Burg holen.", player);
		DlgText("Aber sie ist abgeschlossen.", player);
		DlgText("Das wird sie auch bleiben, ich habe naemlich keine Waffen,|mit denen ich eine offene Burg verteidigen koennte.");
		DlgText("Was waere denn, wenn wir angegriffen werden?");
		DlgText("Wir waeren schutzlos ausgeliefert| und die Gegner koennten einfach in die Burg hineinspazieren.");
		DlgText("Du solltest mir also erstmal einen T-Flint bringen.");
	}
	else if (true)
	{
		DlgText("Hi, Waechter!|Hier ist Dein T-Flint.", player);
		DlgText("Sehr gut! Jetzt kannst Du in die Burg.");
		DlgText("Und wenn wir angegriffen werden,|werden unsere Gegner T-Flints zu spueren bekommen.");
	}
	else
	{
		DlgText("Haben Sie zufaellig ein Brecheisen,|mit dem ich in den Laden komme?", player);
		DlgText("Nein, ich besitze kein Brecheisen.");
	}
	DlgReset();
}
