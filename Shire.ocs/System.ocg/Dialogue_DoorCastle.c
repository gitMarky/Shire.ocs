#appendto Library_Dialogue

public func Dlg_DoorCastle(object player)
{
	var can_enter = player.dialogue_guardsman_gave_tflint;

	if (can_enter)
	{
		door_castle_top->SetEnabled(true);
		door_castle_top->Interact(player);
		ScheduleCall(this, "RemoveObject", 1);
	}
	else
	{
		DlgText("$DlgDoorCastle$", player);
	}
}
