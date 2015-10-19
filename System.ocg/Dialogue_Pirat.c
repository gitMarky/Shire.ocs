#include Library_Dialogue
#appendto Library_Dialogue

static const DIALOGUE_Pirat_NoQuest = 0;
static const DIALOGUE_Pirat_QuestWaiting = 1;
static const DIALOGUE_Pirat_QuestFinished = 2;

public func Dlg_Pirat(object player)
{
	if (player.dlg_pirat_get_quest == DIALOGUE_Pirat_NoQuest || !player.dlg_pirat_get_quest)
	{
	    DlgText("Hallo.|Koennen Sie mir helfen nach Hause zu kommen?", player);
	    DlgText("Har, ich bin schon viel rumgekommen, Du Landratte.");
	    DlgText("Aber einfachso geholfen, habe ich niemandem, har, har.");
	    DlgText("Ein Suesswassermatrose wie Du erkennt es|vielleicht nicht aber ich bin ein Pirat.");
	    DlgText("Und Piraten helfen niemandem, har, har!");
	    DlgText("Har, har, har,|HAR,HAR!");
	    DlgText("Wenn Du mir nicht helfen willst, ...", player);
	    DlgText("Gibt es einen Weg weiter nach Osten zu gelangen?", player);
	    DlgText("Har, das will ich meinen.|Und zwar gibt es in meiner Burg einen Geheimgang nach Osten.");
	    DlgText("Seit wann haben Piraten denn eine Burg?", player);
	    DlgText("Mach Dich nicht ueber mich lustig.");
	    DlgText("Ich bin der Herrscher aller Meere.");
	    DlgText("Und da das, das einzige Meer hier ist,|gehoert es mir.");
	    DlgText("Und mit ihm die Burg.");
	    DlgText("Ist ja schon gut.|Darf ich denn den Geheimgang benutzen?", player);
	    DlgText("Wie gesagt, ich helfe niemandem.");
	    DlgText("Wenn Du mir jedoch eine Augenklappe bringen wuerdest,|wuerde ich eine Ausnahme machen.");
	    DlgText("Denn man ist doch nur ein halber Pirat ohne Augenklappe.");
	    if (DlgEvent())
	    {
	    	player.dlg_pirat_get_quest = DIALOGUE_Pirat_QuestWaiting;
	    }
	}
	else if (player.dlg_pirat_get_quest == DIALOGUE_Pirat_QuestWaiting)
	{
		var eyepatch = player->FindContents(Eyepatch);
		DlgText("Hast Du die Augenklappe?");
		if (!eyepatch)
		{
			DlgText("Noch nicht.", player);
		}
		else
		{
			DlgText("Hier ist die Augenklappe.", player);
  			DlgText("Heiliges Kanonenrohr.|Geh in meine Burg, erste Tuer links.");
  			if (DlgEvent())
  			{
  				eyepatch->RemoveObject();
		    	player.dlg_pirat_get_quest = DIALOGUE_Pirat_QuestFinished;
  			}
		}
	}
}