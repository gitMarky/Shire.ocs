#include Library_Dialogue
#appendto Library_Dialogue

public func Dlg_Guardsman(object player)
{
	var has_dialogue_elevator = player.dialogue_pea_east // pea told player to go east
	                        && !player.dialogue_guardsman_elevator; // did not tell the player about the elevator yet
	var has_dialogue_need_arrow = player.dialogue_iolo_arrow // iolo needs an arrow
	                          && !player.dialogue_guardsman_asked_tflint; // did not ask about the t-flint yet.
	var has_dialogue_give_flint = player.dialogue_guardsman_asked_tflint // guardsman asked to give him the flint
	                          && !player.dialogue_guardsman_gave_tflint; // did not give the t-flint to the guardsman yet.
	var has_dialogue_go_east = player.dialogue_guardsman_gave_tflint;
	var has_dialogue_crowbar = player.dlg_pirat_get_quest == DIALOGUE_Pirat_QuestWaiting
	                       && !player.dialogue_carpenter_crowbar;


	if (has_dialogue_elevator)
	{
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
		if (DlgEvent())
		{
			player.dialogue_guardsman_elevator = true; // gives new dialogue in iolo's father
		}
	}
	else if (has_dialogue_need_arrow)
	{
		DlgText("Hallo, nochmal.|Ich wuerde gerne einen Sprengpfeil|aus der Burg holen.", player);
		DlgText("Aber sie ist abgeschlossen.", player);
		DlgText("Das wird sie auch bleiben, ich habe naemlich keine Waffen,|mit denen ich eine offene Burg verteidigen koennte.");
		DlgText("Was waere denn, wenn wir angegriffen werden?");
		DlgText("Wir waeren schutzlos ausgeliefert| und die Gegner koennten einfach in die Burg hineinspazieren.");
		DlgText("Du solltest mir also erstmal einen T-Flint bringen.");
		if (DlgEvent())
		{
			player.dialogue_guardsman_asked_tflint = true;
		}
	}
	else if (has_dialogue_give_flint)
	{
		var tflint = player->FindContents(TFlint);
		if (tflint)
		{
			DlgText("Hi, Waechter!|Hier ist Dein T-Flint.", player);
			DlgText("Sehr gut! Jetzt kannst Du in die Burg.");
			DlgText("Und wenn wir angegriffen werden,|werden unsere Gegner T-Flints zu spueren bekommen.");
			if (DlgEvent())
			{
				tflint->RemoveObject();
				player.dialogue_guardsman_gave_tflint = true;
			}
		}
		else
		{
			DlgText("Hi, leider habe ich noch keinen T-Flint für Dich.", player);
			DlgText("Du weißt ja...|Kein T-Flint, kein Zugang zur Burg.");
		}
	}
	else if (has_dialogue_crowbar)
	{
		DlgText("Haben Sie zufaellig ein Brecheisen,|mit dem ich in den Laden komme?", player);
		DlgText("Nein, ich besitze kein Brecheisen.");
	}
	else // default dialogue
	{
		DlgText("Hallo.", player);
		if (has_dialogue_go_east) DlgText("Hallo. Was willst Du?|Ich dachte, du willst nach Osten.");
		                     else DlgText("Hallo. Was willst Du?|Zivilisten haben hier nichts zu suchen.");
		DlgText("Tja, ich weiss nicht genau, was ich suche, aber ich...", player);
		DlgText("Wenn Du nicht weisst, was Du suchst solltest|Du wiederkommen, wenn Du es weisst. ");
	}
}
