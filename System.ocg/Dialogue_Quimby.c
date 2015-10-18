#include Library_Dialogue
#appendto Library_Dialogue

public func Dlg_Quimby(object player)
{
	var bottle_of_smett = player->FindContents(sMett);

	if (!player.dialogue_quimby_asked_smett)
	{
		DlgText("Hallo.", player);
		DlgText("Hallo, Du.");
		DlgText("Du siehst so aus, als koenntest Du|einem alten Mann, wie mir helfen.");
		DlgText("Eigentlich will ICH ja nach Hause,| aber was kann ich denn fuer Dich tun?", player);
		DlgText("Du koenntest mir eine Flasche voll mit sMett bringen.");
		DlgText("sMett??? Wo kriege ich sowas denn her???", player);
		DlgText("Wenn ich das wuesste wuerde ich Dich nicht schicken.");
		DlgText("Aber Du bekommst auch eine BELOHNUNG, wenn Du mir hilfst.");
		DlgText("Okay, ich versuche eine Flasche aufzutreiben.", player);
		if (DlgEvent())
		{
			player.dialogue_quimby_asked_smett = true;
		}
	}
	else if (!bottle_of_smett)
	{
		DlgText("Hast Du eine Flasche?");
		DlgText("Nee, noch nicht.", player);
	}
	else if (!player.dialogue_quimby_gave_smett)
	{
		DlgText("Hier ist eine Flasche sMett.", player);
		if (DlgEvent())
		{
			bottle_of_smett->RemoveObject();
		}
		DlgText("Ohhhh, vielen Dank!!!");
		DlgText("Ich hatte Dir ja eine Belohnung versprochen...");
		DlgText("Hier nimm diesen Zauberstab, den ich gefunden habe.");
		if (DlgEvent())
		{
			player->CreateContents(WizardStaff);
			player.dialogue_quimby_gave_smett = true;
		}
		DlgText("Danke.", player);
	}
	else
	{
		DlgText("Hast Du noch mehr sMett?");
		DlgText("Nee, ich denke das war das letzte.", player);
	}
}
