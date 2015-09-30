#include Library_Dialogue
#appendto Library_Dialogue

public func Dlg_Merchant(object player)
{
	if (true)//TODO: actual condition - the pullover is in the merchant's cupboard
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
	}
	else if (true) //TODO: actual condition - heard about the pullover, but not in the cupboard yet
	{
		DlgText("Gerne.|Tue den Pulli nur in den Schrank,|dann bekommst Du auch eine Augenklappe.");
	}
	else
	{
		DlgText("Danke nochmal fuer den Pulli.");
	}
	DlgReset();
}
