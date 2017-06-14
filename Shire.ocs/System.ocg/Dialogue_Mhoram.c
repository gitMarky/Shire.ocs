#appendto Library_Dialogue

public func Dlg_Mhoram(object player)
{
	if (!player.dialogue_mhoram_completed)
	{
		DlgText("$DlgMhoram01$", player);
		DlgText("$DlgMhoram02$");
		DlgText("$DlgMhoram03$");
		DlgText("$DlgMhoram04$", player);
		DlgText("$DlgMhoram05$", player);
		DlgText("$DlgMhoram06$");
		DlgText("$DlgMhoram07$");
		DlgText("$DlgMhoram08$", player);
		DlgText("$DlgMhoram09$");
		DlgText("$DlgMhoram10$");
		DlgText("$DlgMhoram11$", player);
		DlgText("$DlgMhoram12$");
		DlgText("$DlgMhoram13$", player);
		DlgText("$DlgMhoram14$");
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
		DlgText("$DlgMhoram15$");
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