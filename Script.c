
static npc_tuti;

func Initialize()
{
	CreateTuti();
}

func InitializePlayer(int player)
{
	var crew = GetHiRank(player);
	crew->SetPosition(80, 1048);
}

// ----- *** NPC Creation *** -----------------------------------------

func CreateTuti()
{
	npc_tuti = CreateObject(Clonk, 695, 1020, NO_OWNER);
	npc_tuti->SetName("$NPC_Tuti$");
	npc_tuti->SetDialogueEx("Tuti");
}