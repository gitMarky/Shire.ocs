#include Library_Dialogue
#appendto Library_Dialogue

public func Dlg_Clonkarabas(object player)
{
	DlgText("CLONKARABAS??? Ich dachte, ich haette Dich getoetet???", player);
	DlgText("Du selbst waerst doch auch fast von einem Auto ueberfahren worden.");
	DlgText("Ich bin also auch kurz vor dem sicheren Tod in dieses Land versetzt worden.");
	DlgText("Dann bist Du derjenige, von dem der Magier sprach?", player);
	DlgText("Nein, es gibt da noch jemanden.|Er koennte Dich vielleicht wieder nach Hause bringen.");
	DlgText("Aber ich bin natuerlich nicht wenig nachtragend.|Du wirst diesen Mann also nicht erreichen.");
	DlgText("Als Strafe, dafuer, dass Du mich fast getoetet haettest,|wirst Du ewig hier bleiben.");
	if (DlgEvent())
	{
		GetActiveSequence()->Stop();
	}
}