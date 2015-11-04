#include Library_Dialogue
#appendto Library_Dialogue

func Dlg_Book_Mhoram(object player)
{
	DlgText("Das Tagebuch eines gewissen Mhoram.", player);
	DlgText("798|'Es ist ein schlechtes Jahr'|Alle Ernten gehen kaputt.|Das Vieh geht zu Grunde.");
	DlgText("799|'Endlich wieder Hoffnung'|Der Krieg gegen die Buschmaenner ist vorbei.");
	DlgText("800|'Ein Leben in Frieden'|Die Buschmaenner sind nette Leute und helfen uns beim Wiederaufbau.|Alle leben in Wohlstand.");
	DlgText("802|'Vertrag'|Die Buschmaenner und wir unterzeichnen einen Friedensvertrag.|Nur unser Waechter ist nicht damit einverstanden.");
	DlgText("803|'Mysterioeses'|Aus irgendeinem Grund besuchen uns die Buschmaenner nicht mehr...");
	DlgText("...Sonst haben wir uns oft besucht.|Wir fanden nur einen schwerverletzten Buschmann, der uns etwas sagen wollte...");
	DlgText("...Er stotterte von etwas grossem, einem Riesen oder so.|Und es leben nur noch wenige von seinem Volk.");
	DlgText("804|Ich werde mal eine Reise nach Osten unternehmen.|Es werden Erdbeben erwartet, aber ich muss sehen was geschah.");
	DlgText("Hier hoert das Tagebuch ploetzlich auf.", player);
}