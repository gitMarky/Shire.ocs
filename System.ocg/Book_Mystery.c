#include Library_Dialogue
#appendto Library_Dialogue

func Dlg_Book_Mystery(object player)
{
	DlgText("In dem ganzen Buch steht nur ein Satz:", player);
	DlgText("Honk gonc vingil gheshnec imatril.");
	DlgText("Ich hoffe ich hab das richtig ausgesprochen.", player);
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