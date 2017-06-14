#appendto Library_Dialogue

public func Dlg_Intro(object player)
{
	player->SetDir(DIR_Right);
	DlgText("$DlgIntro01$");
	DlgText("$DlgIntro02$");
	DlgText("$DlgIntro03$");
	if (DlgEvent())
	{
		StartBackgroundSequence("Intro", 0, player, this);
	}
}
