#include Library_Dialogue
#appendto Library_Dialogue

public func Dlg_Scientist(object player)
{
	var has_initial_dialogue = !player.scientist_intro;
	var cyclops_alive = enemy_cyclops->GetAlive();
	var has_dimension_dialogue = !player.scientist_dimension;

	if (has_initial_dialogue)
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
			player.scientist_intro = true;
			cyclops_dangerous = true;

			// this is a little more comfortable than walking back and forth
			var chest = CreateObject(Chest);
			AddEffect("IntRespawnGrenades", chest, 1, 300);
			chest->SetPosition(npc_ndo->GetX() + 20, npc_ndo->GetY());
		}
	}
	else if (cyclops_alive)
	{
		DlgText("Bedenke aber, dass der Zyklop nur eine |verwundbare Stelle hat.");
	}
	else if (has_dimension_dialogue)
	{
		DlgText("Ich habe den Zyklop besiegt und es gibt wirklich Tarydium.", player);
		DlgText("Sehr gut.|Du musst das Tarydium in das Dimensionsfahrzeug tun.");
		DlgText("Dann musst Du mit dem Fahrzeug durch einen Dimensionsspalt fliegen.");
		DlgText("Und wo kriege ich einen Dimensionsspalt her?", player);
		DlgText("Es gibt ein Zauberbuch, in dem ein Spruch|steht, der einen Spalt erzeugt.");
		DlgText("Dieses Buch liegt bei mir im Turm.");
		if (DlgEvent())
		{
			player.scientist_dimension = true;
		}
	}
	else
	{
		DlgText("Also nochmal in Kurzform:|Buch lesen,|Tarydium einwerfen,|in den Spalt fliegen.");
	}
}
