#include Library_Dialogue
#appendto Library_Dialogue

public func Dlg_Quimby(object player)
{
	DlgText("Hallo.", player);
	DlgText("Hallo, Du.");
	DlgText("Du siehst so aus, als koenntest Du|einem alten Mann, wie mir helfen.");
	DlgText("Eigentlich will ICH ja nach Hause,| aber was kann ich denn fuer Dich tun?", player);
	DlgText("Du koenntest mir eine Flasche voll mit sMett bringen.");
	DlgText("sMett??? Wo kriege ich sowas denn her???", player);
	DlgText("Wenn ich das wuesste wuerde ich Dich nicht schicken.");
	DlgText("Aber Du bekommst auch eine BELOHNUNG, wenn Du mir hilfst.");
	DlgText("Okay, ich versuche eine Flasche aufzutreiben.", player);
	DlgText("Hast Du eine Flasche?");
	DlgText("Nee, noch nicht.", player);
	DlgText("Hier ist eine Flasche sMett.", player);
	DlgText("Ohhhh, vielen Dank!!!");
	DlgText("Ich hatte Dir ja eine Belohnung versprochen...");
	DlgText("Hier nimm diesen Zauberstab, den ich gefunden habe.");
	DlgText("Danke.", player);
}

public func Dlg_Guardsman(object player)
{
	DlgText("Hallo.", player);
	DlgText("Hallo. Was willst Du?|Zivilisten haben hier nichts zu suchen.");
	DlgText("Tja, ich weiss nicht genau, was ich suche, aber ich...", player);
	DlgText("Wenn Du nicht weisst, was Du suchst solltest|Du wiederkommen, wenn Du es weisst. ");
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
	DlgText("Hallo, nochmal.|Ich wuerde gerne einen Sprengpfeil|aus der Burg holen.", player);
	DlgText("Aber sie ist abgeschlossen.", player);
	DlgText("Das wird sie auch bleiben, ich habe naemlich keine Waffen,|mit denen ich eine offene Burg verteidigen koennte.");
	DlgText("Was waere denn, wenn wir angegriffen werden?");
	DlgText("Wir waeren schutzlos ausgeliefert| und die Gegner koennten einfach in die Burg hineinspazieren.");
	DlgText("Du solltest mir also erstmal einen T-Flint bringen.");
	DlgText("Hi, Waechter!|Hier ist Dein T-Flint.", player);
	DlgText("Sehr gut! Jetzt kannst Du in die Burg.");
	DlgText("Und wenn wir angegriffen werden,|werden unsere Gegner T-Flints zu spueren bekommen.");
	DlgText("Haben Sie zufaellig ein Brecheisen,|mit dem ich in den Laden komme?", player);
	DlgText("Nein, ich besitze kein Brecheisen.");
}

public func Dlg_Scientist(object player)
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
	DlgText("Bedenke aber, dass der Zyklop nur eine |verwundbare Stelle hat.");
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
	DlgText("Also nochmal in Kurzform:|Hebel ziehen,|Schalter aus,|Buch lesen,|Tarydium einwerfen,|in den Spalt fliegen.");
}