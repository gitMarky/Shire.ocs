#include Library_Dialogue
#appendto Library_Dialogue

public func Dlg_Merchant(object player)
{
	var has_dialogue_eyepatch = !player.dialogue_merchant_eyepatch;
	var has_dialogue_pullover = player.dialogue_merchant_eyepatch
	                        && !player.dialogue_merchant_pullover; 

	if (has_dialogue_eyepatch)
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
		if (DlgEvent())
		{
			player.dialogue_merchant_eyepatch = true;
			player->CreateObject(Pullover);
			player->SetMeshMaterial("Clonk_Player");
		}
	}
	else if (has_dialogue_pullover)
	{
		var has_pullover = player->FindContents(Pullover);
		if (has_pullover)
		{
			DlgText("Hier, da hast du meinen Pullover.", player);
			DlgText("Danke, dann bekommst Du auch eine Augenklappe.");
			DlgText("Danke für die Augenklappe.", player);
			if (DlgEvent())
			{
				if (has_pullover) has_pullover->RemoveObject();
				player->CreateContents(Eyepatch);
				player.dialogue_merchant_pullover = true;
				shop_low_top->SetGraphics("Pullover", DecoShop, 1, GFXOV_MODE_Base);
				shop->SetGraphics("Pullover", DecoShop, 4, GFXOV_MODE_Base); // workaround for bug #0001458
			}
		}
		else
		{
			DlgText("Hast du schon einen Pullover für mich?");
		    DlgText("Leider nein, ich behalte ihn noch ein bisschen...", player);
		}
	}
	else
	{
		DlgText("Danke nochmal für den Pulli.");
	}
}
