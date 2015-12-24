#include Library_Dialogue
#appendto Library_Dialogue

static const DIALOGUE_Pirat_NoQuest = 0;
static const DIALOGUE_Pirat_QuestWaiting = 1;
static const DIALOGUE_Pirat_QuestFinished = 2;

public func Dlg_Pirat(object player)
{
	if (player.dialogue_pirat_get_quest == DIALOGUE_Pirat_NoQuest || !player.dialogue_pirat_get_quest)
	{
	    DlgText("$DlgPirateA01$", player);
	    DlgText("$DlgPirateA02$");
	    DlgText("$DlgPirateA03$");
	    DlgText("$DlgPirateA04$");
	    DlgText("$DlgPirateA05$");
	    DlgText("$DlgPirateA06$");
	    DlgText("$DlgPirateA07$", player);
	    DlgText("$DlgPirateA08$", player);
	    DlgText("$DlgPirateA09$");
	    DlgText("$DlgPirateA10$", player);
	    DlgText("$DlgPirateA11$");
	    DlgText("$DlgPirateA12$");
	    DlgText("$DlgPirateA13$");
	    DlgText("$DlgPirateA14$");
	    DlgText("$DlgPirateA15$", player);
	    DlgText("$DlgPirateA16$");
	    DlgText("$DlgPirateA17$");
	    DlgText("$DlgPirateA18$");
	    if (DlgEvent())
	    {
	    	player.dialogue_pirat_get_quest = DIALOGUE_Pirat_QuestWaiting;
	    }
	}
	else if (player.dialogue_pirat_get_quest == DIALOGUE_Pirat_QuestWaiting)
	{
		var eyepatch = player->FindContents(Eyepatch);
		DlgText("$DlgPirateB01$");
		if (!eyepatch)
		{
			DlgText("$DlgPirateB02$", player);
		}
		else
		{
			DlgText("$DlgPirateB03$", player);
  			DlgText("$DlgPirateB04$");
  			if (DlgEvent())
  			{
  				eyepatch->RemoveObject();
		    	player.dialogue_pirat_get_quest = DIALOGUE_Pirat_QuestFinished;
		    	
		    	var secret_door = CreateObject(DecoDoor, AbsX(2220), AbsY(1744), NO_OWNER);
		    	secret_door->SetClrModulation(RGB(180, 180, 180));
		    	secret_door->SetObjDrawTransform(600, 0, 0, 0, 1000);
		    	secret_door->SetGraphics("Stone");
		    	
		    	var secret_exit = CreateObject(DecoDoor, AbsX(2205), AbsY(518), NO_OWNER);
		    	secret_exit->ConnectTo(secret_door);
		    	secret_exit.Visibility = VIS_None;
		    	
		    	var effect = AddEffect("IntRevealTunnel", secret_door, 1, 1, this);
		    	effect.secret_exit = secret_exit;
  			}
		}
	}
}

func FxIntRevealTunnelTimer(object target, proplist effect, int timer)
{
	if (target->GetAction() == "OpenDoor")
	{
		effect.secret_exit.Visibility = VIS_All;
		RevealTunnel();
		return FX_Execute_Kill;
	}
}