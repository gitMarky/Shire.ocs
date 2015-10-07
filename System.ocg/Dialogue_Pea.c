#include Library_Dialogue
#appendto Library_Dialogue

public func Dlg_Pea(object player)
{
	if (true) // TODO: not talked to guardsman yet
	{
		DlgText("Hi, wie geht es dir?", player);
		DlgText("Gut! Danke!|Ich bin Pea, der Foerster.");
		DlgText("Du bist aber nicht von hier.");
		DlgText("Ja, das stimmt, ich moechte so schnell wie moeglich nach Hause.|Kannst Du mir helfen?", player);
		DlgText("Wo ist denn Dein Zuhause?");
		DlgText("Kennst Du die Erde?", player);
		DlgText("Nein, noch nie gehoert.");
		DlgText("Liegt es im Osten?");
		DlgText("Wieso fragst Du?", player);
		DlgText("Seit langer Zeit, weiss niemand mehr, was im Osten liegt.|Vielleicht solltest Du mal nach Osten gehen.");
		DlgText("Ja, das werde ich tun.", player);
		if (DlgEvent())
		{
			player.dialogue_pea_east = true; // gives new dialogue in guardsman
			// TODO: create kolibri
		}
	}
	else if (true) //TODO: talked to guardsman about t-flint
	{
		DlgText("Hi, Pea!|Weisst Du, wo es hier T-Flints gibt?", player);
		DlgText("Na hoehr mal, ich bin doch Foerster.|Da sind Flints aller Art mein Spezialgebiet.");
		DlgText("Schau Dir doch mal die Baeume an.");
		DlgText("Und letztens ist mir beim Saegen ein T-Flint vor die Fuesse gefallen.");
		DlgText("Kann ich ihn haben?", player);
		DlgText("Du musst mir nur einen Gefallen tun.|Bringe mir etwas Brot.");
		DlgText("OK.", player);
	}
	else if (true) //TODO: talked about break
	{
		DlgText("Hier ist das Brot.", player);
		DlgText("Hier ist der T-Flint.");
	}
	else if (true) //TODO: some idly stuff
	{
		DlgText("Hi, Pea!", player);
		DlgText("Hi, Du!");
	}
	else // TODO: asking for crowbar
	{
		DlgText("Hi, Pea!|Hast Du ein Brecheisen,|mit dem ich in den Laden komme?", player);
		DlgText("Ich bin Foerster, kein Einbrecher.");
	}
	DlgReset();
}
