#include Library_Dialogue
#appendto Library_Dialogue

public func Dlg_NDo(object player)
{
	if (true) //TODO did not complete first dialogue
	{
		DlgText("Hallo.|Bist Du ein Buschmann?", player);
		DlgText("Uhg, warum Fremder wissen wollen?");
		DlgText("Na, ich habe was ueber einen Krieg gegen euch gehoehrt.", player);
		DlgText("Fremder auch wissen von grosses Gefahr?");
		DlgText("Meinst Du den Grund, weswegen viele von euch gestorben sind?", player);
		DlgText("Ugh, es ist schrecklich Gefahr. Hat viele getoetet.");
		DlgText("Grosses Gefahr.|Grosses Clonk, mit nur ein Augen.");
		DlgText("Ist diese Gefahr hier im Wald?", player);
		DlgText("Fremder nicht gehen weiter sollte.|Er in Not geraten wird.");
		DlgText("Ich muss aber weiter.|Ich muss alles erforschen.|Ich muss nach Hause.", player);
		DlgText("Und ich muss vielleicht sogar in Not geraten.", player);
	}
	else
	{
		DlgText("Fremder nicht gehen weiter sollte.|Er in Not geraten wird.");
	}
}
