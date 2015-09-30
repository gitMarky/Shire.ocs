#include Library_Dialogue
#appendto Library_Dialogue

public func Dlg_Bettler(object player)
{
	DlgText("Hallo.", player);
	DlgText("Hallo, Du.");
	DlgText("Hast Du nicht eine Goldmuenze fuer einen armen Kriegsveteranen?");
	DlgText("Nein, leider nicht.", player);
	DlgText("Hier eine Goldmuenze.", player);
	DlgText("Gott segne Dich.");
}

public func Dlg_Drin(object player)
{
	DlgText("Hi, wie geht es dir?", player);
	DlgText("Schlecht...Hick....Bssssss. ");
	DlgText("Kannst Du mir vielleicht helfen?", player);
	DlgText("Geh wech...Hick...Hick...");
}

public func Dlg_Haendler(object player)
{
	DlgText("Hallo. Wie siehts aus?", player);
	DlgText("Schlecht.|Ich glaube ich werde den Laden schliessen muessen.");
	DlgText("Aber warum denn?", player);
	DlgText("Ganz einfach.|Du siehst doch mein Schild draussen,oder?");
	DlgText("Ja, und?", player);
	DlgText("Und Du siehst auch mein Schaufenster?");
	DlgText("Ja.", player);
	DlgText("Und wie Du auch siehst, werbe ich|mit einem schoenen roten Pulli,|aber alle roten Pullis sind ausverkauft.");
	DlgText("Der rote Pulli war immer mein Aushaengeschild,|mein Markenzeichen.");
	DlgText("Und gerade als mein Laden gut lief,|wurde das Land von einer roten Pulli-Krise heimgesucht.");
	DlgText("Daran war nur der Krieg gegen die Buschvoelker schuld.|Und ich kann die Erwartungen der Kaeufer nicht mehr erfuellen...");
	DlgText("Das ist mein Ruin.|Buuuuuhhhhuuuuu!");
	DlgText("Wenn Du moechtest, kannst Du meinen Pulli haben.", player);
	DlgText("WIRKLICH??? Das ist aber nett von Dir.|Wie kann ich Dir jemals danken?");
	DlgText("Gib mir nur eine Augenklappe.", player);
	DlgText("Gerne.|Tue den Pulli nur in den Schrank,|dann bekommst Du auch eine Augenklappe.");
	DlgText("Danke nochmal fuer den Pulli.");
}

public func Dlg_IolosVater(object player)
{
	DlgText("Hallo!", player);
	DlgText("Geh weg!|Siehst Du Gruenschnabel nicht,|dass ich beschaeftigt bin?");
	DlgText("Wissen Sie wo Iolo ist?", player);
	DlgText("Zu Iolo willst Du, hae?");
	DlgText("Der sitzt nur zu Hause 'rum,|anstatt zu arbeiten.");
	DlgText("Der ist genauso faul, wie Du aussiehst.");
	DlgText("IOLO!!!|Komm her, Du Nichtsnutz!");
	DlgText("Mach schnell, verfluchte Hacke!");
	DlgText("Diese Jugend von heute...|tz,tz,tz!");
	DlgText("Hallo.|Sie haben nicht zufaellig ein Brecheisen oder so,|mit dem ich in den Laden kann?", player);
	DlgText("Nein, ich habe keins.");
	DlgText("Du faengst an mich zu nerven, Kleiner.");
}

public func Dlg_Mhoram(object player)
{
	DlgText("Hallo!|Wissen Sie, wie ich wieder in meine Welt komme?", player);
	DlgText("Ich weiss viel, mein Junge.");
	DlgText("Aber etwas von 'Deiner Welt' habe ich noch nicht gehoert,|mein Junge.");
	DlgText("Ich meine die Welt, von wo ich komme.", player);
	DlgText("Ich wurde von einem Auto ueberfahren,|und merkwuerdigerweise war ich dann hier.", player);
	DlgText("Mmmmm...|Merkwuerdig, sagst Du, mein Junge?");
	DlgText("UEber merkwuerdige Sachen weiss vielleicht |der Magier bescheid, mein Junge.");
	DlgText("Was fuer ein Magier?|Rede, Alter!", player);
	DlgText("Viele behaupten, es gibt ihn garnicht.|Aber ich weiss, dass es ihn gibt.");
	DlgText("Er ist unsichtbar und erscheint nur, wenn jemand in Not ist, mein Junge.");
	DlgText("Aber ich bin in Not, wo ist er?", player);
	DlgText("Wirkliche Not tut Not, mein Junge.");
	DlgText("Im Dorf sagte man mir,| ich sollte vielleicht nach Osten gehen.", player);
	DlgText("So gehe.");
	DlgText("Du solltest ueber den Berg gehen, wenn Du zurueck willst.");
}

public func Dlg_NDo(object player)
{
	DlgText("Hallo.|Bist Du ein Buschmann?", player);
	DlgText("Uhg, warum Fremder wissen wollen?");
	DlgText("Na, ich habe was ueber einen Krieg gegen euch gehoehrt.", player);
	DlgText("Fremder auch wissen von grosses Gefahr?");
	DlgText("Meinst Du den Grund, weswegen viele von euch gestorben sind?", player);
	DlgText("Ugh, es ist schrecklich Gefahr. Hat viele getoetet.");
	DlgText("Grosses Gefahr.|Grosses Clonk, mit nur ein Augen.");
	DlgText("Ist diese Gefahr hier im Wald?", player);
	DlgText("Fremder nicht gehen weiter sollte.|Er in Not geraten wird.");
	DlgText("Ich muss aber weiter.|Ich muss alles erforschen.|Ich muss nach Hause.", player);
	DlgText("Und ich muss vielleicht sogar in Not geraten.", player);
	DlgText("Fremder nicht gehen weiter sollte.|Er in Not geraten wird.");
}

public func Dlg_Pea(object player)
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
	DlgText("Hi, Pea!|Weisst Du, wo es hier T-Flints gibt?", player);
	DlgText("Na hoehr mal, ich bin doch Foerster.|Da sind Flints aller Art mein Spezialgebiet.");
	DlgText("Schau Dir doch mal die Baeume an.");
	DlgText("Und letztens ist mir beim Saegen ein T-Flint vor die Fuesse gefallen.");
	DlgText("Kann ich ihn haben?", player);
	DlgText("Du musst mir nur einen Gefallen tun.|Bringe mir etwas Brot.");
	DlgText("OK.", player);
	DlgText("Hier ist das Brot.", player);
	DlgText("Hier ist der T-Flint.");
	DlgText("Hi, Pea!", player);
	DlgText("Hi, Du!");
	DlgText("Hi, Pea!|Hast Du ein Brecheisen,|mit dem ich in den Laden komme?", player);
	DlgText("Ich bin Foerster, kein Einbrecher.");
}

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

public func Dlg_Wachtmeister(object player)
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

public func Dlg_Wissenschaftler(object player)
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