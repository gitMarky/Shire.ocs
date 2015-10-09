#include Library_Dialogue
#appendto Library_Dialogue

public func Dlg_IolosFather(object player)
{
	var has_dialogue_iolo = player.dialogue_guardsman_elevator
	                    && !player.dialogue_iolo_arrow;  // talked to guardsman about the elevator

	if (has_dialogue_iolo)
	{
		DlgText("Wissen Sie wo Iolo ist?", player);
		DlgText("Zu Iolo willst Du, hae?");
		DlgText("Der sitzt nur zu Hause 'rum,|anstatt zu arbeiten.");
		DlgText("Der ist genauso faul, wie Du aussiehst.");
		DlgText("IOLO!!!|Komm her, Du Nichtsnutz!");
		DlgText("Mach schnell, verfluchte Hacke!");
		DlgText("Diese Jugend von heute...|tz,tz,tz!");
		if (DlgEvent())
		{
			// TODO: sequence where iolo comes near
			npc_iolo->SetPosition(npc_iolos_father->GetX() - 20, npc_iolos_father->GetY());
		}
		DlgText("Was ist denn los, Vater?", npc_iolo);
		DlgText("Hier diese Type will was von Dir!");
		DlgText("Ich wollte nur fragen, ob Du vielleicht so|nett waerest, und mit einem Sprengpfeil...", player);
		DlgText("...den alten Fahrstuhl freisprengst.", player);
		DlgText("Damit ich nach Osten kann.|Ich will ja eigentlich nur so schnell wie moeglich|aus diesem Traum raus.", player);
		DlgText("Klar bin ich dabei!|Endlich passiert mal was in diesem Kaff.|Endlich Abenteuer.|Nur Pfeile hab ich nicht.", npc_iolo);		
		if (DlgEvent())
		{
			player.dialogue_iolo_arrow = true;
		}
	}
	else if (false) //TODO: asked about crowbar
	{
		DlgText("Hallo.|Sie haben nicht zufaellig ein Brecheisen oder so,|mit dem ich in den Laden kann?", player);
		DlgText("Nein, ich habe keins.");
	}
	else if (false)
	{
		DlgText("Du faengst an mich zu nerven, Kleiner.");
	}
	else // default dialogue
	{
		DlgText("Hallo!", player);
		DlgText("Geh weg!|Siehst Du Gruenschnabel nicht,|dass ich beschaeftigt bin?");
	}
}
