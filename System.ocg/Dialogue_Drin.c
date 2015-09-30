#include Library_Dialogue
#appendto Library_Dialogue

public func Dlg_Drin(object player)
{
	DlgText("Hi, wie geht es dir?", player);
	DlgText("Schlecht...Hick....Bssssss. ");
	DlgText("Kannst Du mir vielleicht helfen?", player);
	DlgText("Geh wech...Hick...Hick...");
	DlgReset();
}
