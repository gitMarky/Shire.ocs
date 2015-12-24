#include Library_Dialogue
#appendto Library_Dialogue

public func Dlg_Clonkarabas(object player)
{
	DlgText("$DlgClonkarabas01$", player);
	DlgText("$DlgClonkarabas02$");
	DlgText("$DlgClonkarabas03$");
	DlgText("$DlgClonkarabas04$", player);
	DlgText("$DlgClonkarabas05$");
	DlgText("$DlgClonkarabas06$");
	DlgText("$DlgClonkarabas07$");
	if (DlgEvent())
	{
		GetActiveSequence()->Stop();
	}
}