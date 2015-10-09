#include Library_Dialogue
#appendto Library_Dialogue

public func Dlg_Mhoram(object player)
{
	if (true) //TODO completed the first dialogue
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
		if (DlgEvent())
		{
			//TODO: explode the rocks
		}
	}
	else
	{
		DlgText("Du solltest ueber den Berg gehen, wenn Du zurueck willst.");
	}
}
