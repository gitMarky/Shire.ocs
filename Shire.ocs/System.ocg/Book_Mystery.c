#appendto Library_Dialogue

func Dlg_Book_Mystery(object player)
{
	DlgText("$DlgBookMystery01$", player);
	DlgText("$DlgBookMystery02$");
	DlgText("$DlgBookMystery03$", player);
	if (DlgEvent())
	{
		StartSequence("Rift_Appear", 0, player);
		ScheduleCall(this, this.Dlg_Book_Mystery_Remove, 2);
	}
}

func Dlg_Book_Mystery_Remove()
{
	RemoveObject();
}