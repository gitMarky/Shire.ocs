#include Library_Dialogue
#appendto Library_Dialogue

//func DlgNiclaus(object player)
//{
//	var jump;
//	DlgText("Was willst du?");
//	if (DlgOption("Was zu essen"))
//	{
//		if (DlgEvent()) player->CreateContents(Bread);
//		DlgText("Hier, nimm dieses Brot!");
//		DlgText("Danke", player);
//		DlgReset();
//	}
//	if (DlgOption("Ich suche etwas"))
//	{
//		DlgText("Kein Problem, was denn?");
//		if (DlgOption("Wo ist das Gold?")) DlgText("Gold ist in der Hoehle.");
//		if (DlgOption("Wo sind die Rubine?")) DlgText("Rubine sind in der Hoehle");
//		if (DlgOption("Wo ist Niklaus?")) DlgText("Beats me.");
//		if (DlgOption("Kann man auch im Dialog kreuz und quer springen?")) jump = true;
//		if (DlgOption("Ich suche doch nix...")) DlgReset();
//		DlgOptionEnd();
//	}
//	if (DlgOption("Kann man auch im Dialog kreuz und quer springen?")) jump = true;
//	// Mehrere Pfade zum gleichen Dialogteil
//	if (jump) DlgText("Ja, springen geht auch.");
//}

public func Dlg_Tuti(object player)
{
	Log("Calling Dlg_Tuti on %s", player->GetName());
	DlgText("Hallo! Koennen Sie mir sagen,|wo ich bin?", player);
	DlgText("Du kannst Du sagen.");
	DlgText("Du bist naemlich in Shîre.");
	DlgText("Hae??? Wooo???", player);
	DlgText("In Shîre.|Das ist der Name von dem Land,|in dem wir leben, und Du dich gerade aufhaeltst. ");
	DlgText("Hier ist der Eingang zu unserer Stadt,|sie heisst Armagânth. ");
	DlgText("Das heisst 'Die Stadt'.|Lustig, nich? ");
	DlgText("Das ist mir sowas von egal, ich moechte wieder|nach Hause, wo ich herkomme.", player);
	DlgText("Wie bist Du denn dann hierher gekommen,|wenn Du nicht weisst, wie Du wieder zurueck kommst?");
	DlgText("Ich wurde von einem Auto ueberfahren und muesste tot sein.|Das hier ist anscheinend die Hoelle.", player);
	DlgText("Ich glaube nicht, dass Du tot bist.|Du siehst naemlich sehr lebendig aus.");
	DlgText("Gibt es denn sonst eine logischere Erklaerung dafuer,|dass ich nicht mehr auf Mutter Erde bin, als meinen Tod?|Oder traeum ich?", player);
	DlgText("Ich weiss nicht viel, vielleicht solltest Du mal jemand anderes fragen...");
	DlgText("Ich glaube das ist wohl besser.|Ich will naemlich so schnell wie moeglich nach Hause.", player);
	DlgReset();
}