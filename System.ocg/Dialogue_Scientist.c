#include Library_Dialogue
#appendto Library_Dialogue

public func Dlg_Scientist(object player)
{
	if (true)
	{
		DlgText("Hallo!|Bist Du auch aus der richtigen Welt?", player);
		DlgText("Du meinst bestimmt Deine Welt.");
		DlgText("Ich meine die einzige richtige Welt!!!", player);
		DlgText("Dies hier ist doch alles ein Traum.", player);
		DlgText("Ob es ein Traum ist, musst Du selbst wissen.|Aber ich kenne die Welt, von der Du behauptest,|es sei die richtige.");
		DlgText("Ich kam auch von dort.|Und habe mich auch danach gesehnt dorthin zurueckzukehren.");
		DlgText("Ich habe eine Maschine gebaut, mit der man wieder zurueckkommt.|Ich habe mich jedoch dazu entschlossen, hier zu bleiben.");
		DlgText("Diese Welt ist friedfertig und schoen.");
		DlgText("Wenn Du willst, kannst Du die Maschine benutzen.");
		DlgText("Ja, aber natuerlich.|Ist es die dort?", player);
		DlgText("Um ehrlich zu sein:|Sie ist noch nicht fertig.");
		DlgText("Ich brauche etwas Tarydium.|Das einzige Vorkommen wird aber von einem Zyklopen bewacht.");
		DlgText("Geh in meine Werkstatt, dort findest Du Waffen.");
		if (DlgEvent())
		{
			cyclops_dangerous = true;
		}
	}
	else if (true)
	{
		DlgText("Bedenke aber, dass der Zyklop nur eine |verwundbare Stelle hat.");
	}
	else if (true)
	{
		DlgText("Ich habe den Zyklop besiegt und es gibt wirklich Tarydium.", player);
		DlgText("Sehr gut.|Du musst das Tarydium in das Dimensionsfahrzeug tun.");
		DlgText("Dann musst Du mit dem Fahrzeug durch einen Dimensionsspalt fliegen.");
		DlgText("Und wo kriege ich einen Dimensionsspalt her?", player);
		DlgText("Es gibt ein Zauberbuch, in dem ein Spruch|steht, der einen Spalt erzeugt.");
		DlgText("Dieses Buch liegt bei mir im Turm.");
		DlgText("Du musst aber erst die magische Barriere ausschalten.");
		DlgText("Sie verschwindet erst, wenn alle weissen Schalter aus sind.");
		DlgText("Die Schalter werden durch das Kontrollpult unten gesteuert.");
		DlgText("Du musst also den Hebel unten betaetigen,|bis alle Schalter aus sind.");
	}
	else
	{
		DlgText("Also nochmal in Kurzform:|Hebel ziehen,|Schalter aus,|Buch lesen,|Tarydium einwerfen,|in den Spalt fliegen.");
	}
}
