#include Library_Dialogue
#appendto Library_Dialogue

public func Dlg_IolosFather(object player)
{
	if (true) // TODO: did not talk to guardsman yet
	{
		DlgText("Hallo!", player);
		DlgText("Geh weg!|Siehst Du Gruenschnabel nicht,|dass ich beschaeftigt bin?");
	}
	else if (true) //TODO: talked to guardsman
	{
		DlgText("Wissen Sie wo Iolo ist?", player);
		DlgText("Zu Iolo willst Du, hae?");
		DlgText("Der sitzt nur zu Hause 'rum,|anstatt zu arbeiten.");
		DlgText("Der ist genauso faul, wie Du aussiehst.");
		DlgText("IOLO!!!|Komm her, Du Nichtsnutz!");
		DlgText("Mach schnell, verfluchte Hacke!");
		DlgText("Diese Jugend von heute...|tz,tz,tz!");
	}
	else if (true) //TODO: asked about crowbar
	{
		DlgText("Hallo.|Sie haben nicht zufaellig ein Brecheisen oder so,|mit dem ich in den Laden kann?", player);
		DlgText("Nein, ich habe keins.");
	}
	else
	{
		DlgText("Du faengst an mich zu nerven, Kleiner.");
	}
	DlgReset();
}
