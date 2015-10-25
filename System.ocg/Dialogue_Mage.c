#include Library_Dialogue
#appendto Library_Dialogue

public func Dlg_Mage(object player)
{
	var knows_mhoram = player.dialogue_mhoram_completed;
	
	if (knows_mhoram)
	{
		DlgText("Du bist der Magier von dem Mhoram sprach!!!", player);
		DlgText("Und Du hast mich in der Stunde der Not gerettet.|Danke.", player);
	}
	else
	{
		DlgText("Bist du ein Magier?!", player);
		DlgText("Du hast mich in der Stunde der Not gerettet.|Danke.", player);
	}

	DlgText("Ich habe Dich gewarnt. Oder erinnerst Du|Dich nicht mehr an den Vogel?");
	DlgText("Du warst der Vogel???", player);
	DlgText("Mhoram hat mir erzaehlt, dass Du vielleicht weisst,|wie ich wieder in meine Welt komme.", player);
	DlgText("Ich habe davon schonmal gehoert.|Es gab mal einen Mann, der war in der gleichen Lage, wie Du.");
	DlgText("Und er kam aus der gleichen Welt, wie Du.");
	DlgText("Was??? Auch aus meiner Welt???", player);
	DlgText("Ich konnte ihm nicht helfen. Dir kann ich also auch nicht helfen.");
	DlgText("Ich kann Dich nur zu ihm fuehren. Auf dass er Dir helfen moege.");
	DlgText("So gehe nach Westen, Du wirst Deinen Landsmann finden.");
	if (DlgEvent())
	{
		GetActiveSequence()->ScheduleNext(40);
	}
}
