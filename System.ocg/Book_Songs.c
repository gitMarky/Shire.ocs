#include Library_Dialogue
#appendto Library_Dialogue

func Dlg_Book_Songs(object player)
{
	DlgText("Das ist ein Liederbuch.", player);
	DlgText("Das erste Lied geht so:", player);
	DlgText("Die Welt war jung, die Berge gruen,|Als fleckenlos der Mond noch schien,|Nicht Berg noch Tal, nicht Strom noch Land|War da, zu Jans Zeit, benannt.");
	DlgText("Er gab den Dingen Nam und Stand,|Trank den ersten Trunk vom Quellenrand|Und sah im Spiegel Widerschein,|Von Sternen, Gold und Edelstein,");
	DlgText("Sah sich zu Haeupten eine Kron|Aufblinken und verschatten schon.");
	DlgText("Das geht jetzt endlos noch so weiter.", player);
}