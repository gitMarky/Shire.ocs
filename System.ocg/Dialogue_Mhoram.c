#include Library_Dialogue
#appendto Library_Dialogue

public func Dlg_Mhoram(object player)
{
	if (!player.dialogue_mhoram_completed)
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
			player.dialogue_mhoram_completed = true;
			
			var action = "IdleStrech";
			var duration = 30;
			dlg_target->PlayAnimation(action, CLONK_ANIM_SLOT_Arms, Anim_Linear(0, 0, dlg_target->GetAnimationLength(action), duration, ANIM_Remove), Anim_Linear(0, 0, 1000, 5, ANIM_Remove));

			ScheduleCall(this, "Dlg_Mhoram_Explosion", 20);
		}
	}
	else
	{
		DlgText("Du solltest ueber den Berg gehen, wenn Du zurueck willst.");
	}
}

func Dlg_Mhoram_Explosion()
{
	CreateObject(Rock, AbsX(1641), AbsY(1010))->Explode(25);
	ScheduleCall(this, "Dlg_Mhoram_RemoveRocks", 2);
}

func Dlg_Mhoram_RemoveRocks()
{
	for (var rock in FindObjects(Find_ID(Rock), Find_InRect(AbsX(1615), AbsY(1000), 100, 50)))
	{
		rock->RemoveObject();
	}
}