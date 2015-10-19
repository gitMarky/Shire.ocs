#include Library_Dialogue
#appendto Library_Dialogue

public func Dlg_Pea(object player)
{
	var has_dialogue_east = !player.dialogue_pea_east;
	var has_dialogue_tflint = player.dialogue_guardsman_asked_tflint  // talked to guardsman about t-flint
	                      && !player.dialogue_pea_asked_bread;
	var has_dialogue_bread = player.dialogue_pea_asked_bread; // talked about bread
	var has_dialogue_crowbar = player.dlg_pirat_get_quest == DIALOGUE_Pirat_QuestWaiting
	                       && !player.dialogue_carpenter_crowbar;

	if (has_dialogue_east)
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
	else if (has_dialogue_tflint)
	{
		DlgText("Hi, Pea!|Weisst Du, wo es hier T-Flints gibt?", player);
		DlgText("Na hoehr mal, ich bin doch Foerster.|Da sind Flints aller Art mein Spezialgebiet.");
		DlgText("Schau Dir doch mal die Baeume an.");
		DlgText("Und letztens ist mir beim Saegen ein T-Flint vor die Fuesse gefallen.");
		DlgText("Kann ich ihn haben?", player);
		DlgText("Du musst mir nur einen Gefallen tun.|Bringe mir etwas Brot.");
		DlgText("OK.", player);
		if (DlgEvent())
		{
			player.dialogue_pea_asked_bread = true;
		}
	}
	else if (has_dialogue_bread)
	{
		var bread = player->FindContents(Bread);
		
		if (bread)
		{
			DlgText("Hier ist das Brot.", player);
			DlgText("Hier ist der T-Flint.");
			if (DlgEvent())
			{
				player.dialogue_pea_gave_bread = true;
				bread->RemoveObject();
				player->CreateContents(TFlint); // this should always fit into the players inventory, because after all he was holding bread before
			}
		}
		else
		{
			DlgText("Was sollte ich dir gleich nochmal bringen?", player);
			DlgText("Bring mir etwas Brot, bitte.");
		}
	}
	else if (has_dialogue_crowbar)
	{
		DlgText("Hi, Pea!|Hast Du ein Brecheisen,|mit dem ich in den Laden komme?", player);
		DlgText("Ich bin Foerster, kein Einbrecher.");
	}
	else
	{
		DlgText("Hi, Pea!", player);
		DlgText("Hi, Du!");
	}
}
