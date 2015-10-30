
static npc_tuti, npc_pirate, npc_carpenter, npc_beggar, npc_drin;
static npc_merchant, npc_iolo, npc_iolos_father, npc_mhoram;
static npc_ndo, npc_pea, npc_quimby, npc_guardsman, npc_scientist;
static door_hut_iolo_top, door_hut_iolo_low, door_castle_top, door_shop_top;
static enemy_cyclops;

func Initialize()
{
	// buildings

	CreateCity();
	CreateWoodHut();
	CreateObject(DecoConstruction, 670, 1007, NO_OWNER);

	CreateStoneHut();
	CreateSawmill();
	CreateWindmill();
	CreateShop();
	CreateCastle();

	CreateElevator();
	CreatePirateCastle();
	CreateScientistLab();
	
	// deco

	CreateButterflies();
	CreateCorpses();
	CreateFields();
	CreateJungle();
	CreateWaterfall();

// some kind of barrier and book, maybe at the cyclops
//	DigFreeRect(3910,1270,30,70);
//	CreateObjectMapZoom(_BWL,3940,1280,0);
//	CreateObjectMapZoom(_BU4,3650,2010,0);

//	DigFreeRect(1020,1200,420,90);

	// characters

	CreateTuti();
	CreatePirate();
	CreateCarpenter();
	CreateBeggar();
	CreateDrin();
	CreateMerchant();
	CreateIolosFather();
	CreateIolo();
	CreateMhoram();
	CreateNDo();
	CreatePea();
	CreateQuimby();
	CreateGuardsman();
	CreateScientist();

	StartBackgroundSequence("Trigger_Bird_Elevator");
	StartBackgroundSequence("Trigger_Bird_Cyclops");
	StartBackgroundSequence("Trigger_Clonkarabas");
}

func InitializePlayer(int player)
{
	var crew = GetHiRank(player);
	crew->SetPosition(80, 1048);
	crew->Fling(100, 1335);
	crew->RemoveBackpack();
	crew->SetMeshMaterial("Clonk_PlayerPullover");
}


func CreateObjectMapZoom(id def, int x, int y, int owner)
{
	var x_scaled = 8 * x / 10;
	var y_scaled = 8 * y / 10;
	Log("CreateObjectMapZoom(%i, %d, %d, %d) -> CreateObject(%i, %d, %d, %d)", def, x, y, owner, def, x_scaled, y_scaled, owner);
	return CreateObject(def, 8 * x / 10, 8 * y / 10, owner);
}

// ----- *** NPC Creation *** -----------------------------------------

func CreateTuti()
{
	npc_tuti=CreateObject(Clonk, 480, 1030, NO_OWNER);
	npc_tuti->SetName("$NPC_Tuti$");
	npc_tuti->SetDialogueEx("Tuti");
	npc_tuti->SetMeshMaterial("Clonk_Tuti");
	npc_tuti->SetDir(DIR_Left);
	npc_tuti->RemoveBackpack();
}

func CreatePirate()
{
	npc_pirate=CreateObject(Clonk, 2095, 365, NO_OWNER);
	npc_pirate->SetName("$NPC_Pirate$");
	npc_pirate->SetDialogueEx("Pirat");
	npc_pirate->RemoveBackpack();
	npc_pirate->SetGraphics("Alchemist");
	npc_pirate->SetMeshMaterial("Clonk_Pirate");
	npc_pirate->SetMeshMaterial("Clonk_PirateTunic", 1);
	npc_pirate->SetDir(DIR_Left);
	
	// hat
	var hat = npc_pirate->CreateContents(PirateHat);
	npc_pirate->AttachMesh(hat, "skeleton_head", "Base", Trans_Mul(Trans_Rotate(20, 0, 1, 0),
	                                                               Trans_Rotate(115, 0, 0, 1),
	                                                               Trans_Rotate(10, 0, 1, 0),
	                                                               Trans_Translate(-3500, -3500, 3000),
	                                                               Trans_Scale(2500, 2500, 2500)));
	hat->SetClrModulation(RGB(50, 50, 50));
}

func CreateCarpenter()
{
	npc_carpenter=CreateObject(Clonk, 675, 1025, NO_OWNER);
	npc_carpenter->SetName("$NPC_Carpenter$");
	npc_carpenter->SetDialogueEx("Carpenter");
	npc_carpenter->RemoveBackpack();
	npc_carpenter->SetMeshMaterial("Clonk_Carpenter");
}

func CreateBeggar()
{
	npc_beggar=CreateObject(Clonk, 708, 1020, NO_OWNER);
	npc_beggar->SetName("$NPC_Beggar$");
	npc_beggar->SetDialogueEx("Beggar");
	npc_beggar->RemoveBackpack();
	npc_beggar->SetMeshMaterial("Clonk_Beggar");
}

func CreateDrin()
{
	npc_drin=CreateObject(Clonk, 945, 1020, NO_OWNER);
	npc_drin->SetName("$NPC_Drin$");
	npc_drin->SetDialogueEx("Drin");
	npc_drin->RemoveBackpack();
	npc_drin->SetMeshMaterial("Clonk_Drin");
}

func CreateMerchant()
{
	npc_merchant=CreateObject(Clonk, 990, 1743, NO_OWNER);
	npc_merchant->SetName("$NPC_Merchant$");
	npc_merchant->SetDialogueEx("Merchant");
	npc_merchant->RemoveBackpack();
}

func CreateIolosFather()
{
	npc_iolos_father=CreateObject(Clonk, 785, 1020, NO_OWNER);
	npc_iolos_father->SetName("$NPC_IolosFather$");
	npc_iolos_father->SetDialogueEx("IolosFather");
	npc_iolos_father->RemoveBackpack();
	npc_iolos_father->SetMeshMaterial("Clonk_IolosFather");
}

func CreateIolo()
{
	npc_iolo=CreateObject(Clonk, 620, 1743, NO_OWNER);
	npc_iolo->SetName("$NPC_Iolo$");
	npc_iolo->RemoveBackpack();
	npc_iolo->SetMeshMaterial("Clonk_Iolo");
	npc_iolo->SetDialogueEx("Iolo");
}

func CreateMhoram()
{
	npc_mhoram=CreateObject(Clonk, 1455, 1020, NO_OWNER);
	npc_mhoram->SetName("$NPC_Mhoram$");
	npc_mhoram->SetDialogueEx("Mhoram");
	npc_mhoram->RemoveBackpack();
	npc_mhoram->SetMeshMaterial("Clonk_Mhoram");
}

func CreateNDo()
{
	npc_ndo=CreateObject(Clonk, 2415, 1015, NO_OWNER);
	npc_ndo->SetName("$NPC_NDo$");
	npc_ndo->SetDialogueEx("NDo");
	npc_ndo->RemoveBackpack();
	npc_ndo->SetMeshMaterial("Clonk_NDo");
}

func CreatePea()
{
	npc_pea=CreateObject(Clonk, 840, 1020, NO_OWNER);
	npc_pea->SetName("$NPC_Pea$");
	npc_pea->SetDialogueEx("Pea");
	// pea may keep his backpack!
	npc_pea->SetMeshMaterial("Clonk_Pea");
}

func CreateQuimby()
{
	npc_quimby=CreateObject(Clonk, 1015, 1020, NO_OWNER);
	npc_quimby->SetName("$NPC_Quimby$");
	npc_quimby->SetDialogueEx("Quimby");
	npc_quimby->RemoveBackpack();
	npc_quimby->SetMeshMaterial("Clonk_Quimby");
}

func CreateGuardsman()
{
	npc_guardsman=CreateObject(Clonk, 1080, 985, NO_OWNER);
	npc_guardsman->SetName("$NPC_Guardsman$");
	npc_guardsman->SetDialogueEx("Guardsman");
	npc_guardsman->RemoveBackpack();
	npc_guardsman->SetMeshMaterial("Clonk_Guardsman");
}

func CreateScientist()
{
	npc_scientist=CreateObject(Clonk, 160, 520, NO_OWNER);
	npc_scientist->SetName("$NPC_Scientist$");
	npc_scientist->SetDialogueEx("Scientist");
	npc_scientist->RemoveBackpack();
	npc_scientist->SetGraphics("Alchemist");
	npc_scientist->SetMeshMaterial("Clonk_Scientist");
	npc_scientist->SetMeshMaterial("Clonk_Scientist", 1);
}

// ----- *** Buildings Creation *** -----------------------------------------

func CreateCastle()
{
	door_castle_top = CreateObject(DecoDoor, 1064, 1024, NO_OWNER);
	var door_castle_low = CreateObject(DecoDoor, 1064, 1744, NO_OWNER);
	door_castle_top->ConnectTo(door_castle_low);
	door_castle_top->SetGraphics("Castle");
	door_castle_low->SetGraphics("Castle");
	door_castle_top->SetEnabled(false);
	door_castle_top->SetDialogueEx("DoorCastle");

//	CreateObjectMapZoom(_HNB,2025,2260,0);
//	CreateObjectMapZoom(_CSI,2050,2230,-1);
//	CreateObjectMapZoom(_TUC,2050,2200,-1);
//	CreateObjectMapZoom(CANN,1950,2200,0);
//	CreateObjectMapZoom(CATA,2150,2200,0);
//	CreateObjectMapZoom(_BED,1930,2157,0);
//	CreateObjectMapZoom(_BED,1958,2157,0);
//	CreateObjectMapZoom(_SRK,2090,2115,0);

//	var cupboard3 = CreateObjectMapZoom(_SRK,2125,2200,0);
//	cupboard3->CreateContents(_BU1);

//	var cupboard4 = CreateObjectMapZoom(_SRK,2115,2115,0);
//	cupboard4->CreateContents(TFLN);
//	cupboard4->CreateContents(XARP);  
//	cupboard4->CreateContents(TFLN);
//	cupboard4->CreateContents(TFLN);
}

func CreateCity()
{
	var city_x = 795;
	var city_y = 1031;
	CreateObject(DecoCity, city_x, city_y, NO_OWNER);
	var top = CreateObject(DecoCity, city_x, city_y, NO_OWNER);
	top->SetGraphics("Top");
	top.Plane = 10000;
	CreateObject(DecoFlag, city_x - 256, city_y - 139);
	CreateObject(DecoFlag, city_x - 16,  city_y - 100);
	CreateObject(DecoFlag, city_x + 261, city_y - 115);
}

func CreateElevator()
{
	var elevator = CreateObject(Elevator, 1275, 703, NO_OWNER);
	elevator->SetDir(DIR_Right);
	//elevator->SetNoPowerNeed(true); // this causes a few errors because the elevator has no power network
//	CreateObjectMapZoom(BRDG,1640,920,0);
}

func CreatePirateCastle()
{
//	CreateObjectMapZoom(_HNP,2715,2260,0);
//	var cupboard5 = CreateObjectMapZoom(_SRK,2815,2157,0);
//	cupboard5->CreateContents(_SME); // smett!

//	CreateObjectMapZoom(_BED,2620,2157,0);
//	var cupboard6 = CreateObjectMapZoom(_SRK,2780,2115,0);
//	cupboard6->CreateContents(GoldCoin);
//	cupboard6->CreateContents(GoldCoin);

//	CreateObjectMapZoom(SLBT,2640,2200,0); // sail boat
//	CreateObjectMapZoom(_PBI,2740,2230,-1);
//	CreateObjectMapZoom(_TUP,2740,2200,0); // secret door?


//	CreateConstruction(_PBG,2820,550,0,100,1);
//	CreateObjectMapZoom(SLBT,2820,510,0);
}

func CreateStoneHut()
{
	CreateObject(DecoStoneHut, 730, 1007, NO_OWNER);
	var stonehut_low = CreateObject(DecoStoneHut, 730, 1727, NO_OWNER);
	stonehut_low->SetGraphics("Inside");
	var door_stonehut_top = CreateObject(DecoDoor, 742, 1024, NO_OWNER);
	var door_stonehut_low = CreateObject(DecoDoor, 742, 1744, NO_OWNER);
	door_stonehut_top->ConnectTo(door_stonehut_low);
	door_stonehut_top->SetGraphics("Stone");
	door_stonehut_low->SetGraphics("Stone");
	var kitchen = CreateObject(Kitchen, 740, 1726);
	kitchen.MeshTransformation = Trans_Mul(Trans_Rotate(30, 0, 1, 0), Trans_Scale(1200, 1200, 1200));
    kitchen->SetShape(-25,-23,20,50);
    kitchen->SetMeshMaterial("Kitchen_Alternate");
    CreateObject(Flour, 709, 1748, NO_OWNER);
    CreateObject(Flour, 713, 1748, NO_OWNER);
    CreateObject(EnvPack_Painting, 711, 1734, NO_OWNER).MeshTransformation = Trans_Mul(Trans_Scale(30, 35, 35), Trans_Rotate(-3, 0, 0, 1));

//	CreateObjectMapZoom(_HN2,405,2260,0);
//	CreateObjectMapZoom(_HI2,400,2230,-1);
//	CreateObjectMapZoom(_BED,425,2150,0);
//	CreateObjectMapZoom(_TIS,395,2150,0);
//	CreateObjectMapZoom(_ST2,380,2150,0);
//	CreateObjectMapZoom(_STU,450,2200,0);

//	CreateObjectMapZoom(OV23,385,2210,0); // oven

//	var cupboard2 = CreateObjectMapZoom(_SRK,352,2200,0);
//	cupboard2->CreateContents(COAL);
//	cupboard2->CreateContents(FB23);
//	cupboard2->CreateContents(WBRL);
//	cupboard2->CreateContents(_BU2);

//	CreateObjectMapZoom(_TU2,425,2200,-1);

// honey spawn
//	var spawn = CreateObjectMapZoom(RP02,410,2200,-1); 
//	spawn->SetAction("Respawn1000");  
//	spawn->CreateContents(HN93);           

}

func CreateSawmill()
{
	CreateObject(DecoSawmill, 840, 1005, NO_OWNER);
	CreateObject(EnvPack_TreeTrunks, 804, 1033, NO_OWNER);
}

func CreateScientistLab()
{
//	CreateObjectMapZoom(_HNZ,3650,2245,0);
//	CreateObjectMapZoom(_ZWI,3720,2230,-1);
//	CreateObjectMapZoom(_BRT,3600,2120,-1); // brett
//	CreateObjectMapZoom(_BRT,3630,2120,-1); // brett
//	CreateObjectMapZoom(_BRT,3660,2120,-1); // brett

//	var cupboard7 = CreateObjectMapZoom(_SRK,3585,2150,-1);
//	cupboard7->CreateContents(XARP);
//	cupboard7->CreateContents(XARP);
//	var cupboard8 = CreateObjectMapZoom(_SRK,3680,2200,-1);
//	cupboard8->CreateContents(ARWP);
//	cupboard8->CreateContents(ARWP);
//	cupboard8->CreateContents(_HPK);
//	CreateObjectMapZoom(RU10,3680,2200,0); // backpack
//	CreateObjectMapZoom(_SCP,3600,2210,0)->SetAction("on");
//	CreateObjectMapZoom(_SCH,3590,2110,0)->SetAction("1off");
//	CreateObjectMapZoom(_SCH,3610,2110,0)->SetAction("1on");
//	CreateObjectMapZoom(_TUZ,3725,2200,-1);
//	CreateObjectMapZoom(_WA3,3655,2217,-1);
//	CreateObjectMapZoom(_WA3,3655,2190,-1);
//	CreateObjectMapZoom(_WA3,3655,2160,-1);
//	CreateObjectMapZoom(_WA3,3655,2147,-1);  
//	CreateObjectMapZoom(_WA2,3687,2147,-1);

//	CreateConstruction(_ZWS,150,660,0,100,1);
//	DigFree(150,660,90);
//	CreateObjectMapZoom(BRDG,90,665,0);
//	CreateObjectMapZoom(BRDG,210,665,0);

//	CreateObjectMapZoom(DV93,50,400,0);  // dimension-vector
}

func CreateShop()
{
    CreateObject(DecoShop, 985, 1002, NO_OWNER);
    var shop_low = CreateObject(DecoShop, 985, 1722, NO_OWNER);
	shop_low->SetGraphics("Inside");
    door_shop_top = CreateObject(DecoDoor, 970, 1024, NO_OWNER);
    var door_shop_low = CreateObject(DecoDoor, 970, 1744, NO_OWNER);
	door_shop_top->ConnectTo(door_shop_low);
	door_shop_top->SetGraphics("Shop");
	door_shop_low->SetGraphics("Shop");
	door_shop_top->SetEnabled(false);
	door_shop_top->SetDialogueEx("DoorShop");

//	CreateObjectMapZoom(_HNS,1405,2260,0);
//	CreateObjectMapZoom(_LIN,1400,2230,-1);

//	CreateObjectMapZoom(_SRK,1400,2200,-1);
//	CreateObjectMapZoom(_BED,1400,2130,0);
//	CreateObjectMapZoom(_TUL,1375,2200,-1);
//	CreateObjectMapZoom(_ST2,1375,2130,0);
//	CreateObjectMapZoom(_TIS,1437,2200,0);
//	CreateObjectMapZoom(_BED,945,2150,0);
}

func CreateWindmill()
{
	var windmill = CreateObject(Windmill, 915, 985, NO_OWNER);
	windmill.MeshTransformation = Trans_Rotate(-10, 0, 1 ,0);
	windmill->SetMeshMaterial("Windmill_Alternate");
}

func CreateWoodHut()
{
	CreateObject(DecoHut, 610, 1007, NO_OWNER);
	var hut_low = CreateObject(DecoHut, 610, 1727, NO_OWNER);
	hut_low->SetGraphics("Inside");
	door_hut_iolo_top = CreateObject(DecoDoor, 600, 1024, NO_OWNER);
	door_hut_iolo_low = CreateObject(DecoDoor, 600, 1744, NO_OWNER);
	door_hut_iolo_top->ConnectTo(door_hut_iolo_low);
	
//	CreateObjectMapZoom(_HNH,905,2260,0);
//	CreateObjectMapZoom(_HUI,900,2230,-1); 
//	CreateObjectMapZoom(_TUH,875,2200,-1);

//	var cupboard1 = CreateObjectMapZoom(_SRK,920,2150,0);
//	cupboard1->CreateContents(GoldCoin);
//	cupboard1->CreateContents(GoldCoin);

//	CreateObjectMapZoom(_TIS,930,2200,0);
//	CreateObjectMapZoom(_STU,945,2200,0);
//	CreateObjectMapZoom(_ST2,915,2200,0);
}

// ----- *** Deco Creation *** -----------------------------------------

func CreateButterflies()
{
	CreateObject(Butterfly, 1000, 960, NO_OWNER);
	CreateObject(Butterfly, 1090, 960, NO_OWNER);
	CreateObject(Butterfly,  930, 960, NO_OWNER);
	CreateObject(Butterfly,  960, 960, NO_OWNER);
	CreateObject(Butterfly, 1040, 960, NO_OWNER);
	CreateObject(Butterfly,  240, 960, NO_OWNER);
	CreateObject(Butterfly,  320, 960, NO_OWNER);
	CreateObject(Butterfly,  220, 960, NO_OWNER);
}

func CreateCorpses()
{
	for (var x in [2930, 2960, 3030, 3040])
	{
		var corpse = CreateObject(Clonk, x, 1010, NO_OWNER);
		corpse->SetDir(Random(2));
		corpse->SetMeshMaterial("Clonk_NDo");
		corpse->Kill(corpse, true);
	}
}

func CreateFields()
{
//	CreateObjectMapZoom(MO93,380,1293,0);
//	CreateObjectMapZoom(MO93,390,1293,0);
//	CreateObjectMapZoom(MO93,400,1293,0);
//	CreateObjectMapZoom(MO93,410,1293,0);
//	CreateObjectMapZoom(MO93,420,1293,0); 
//	CreateObjectMapZoom(MO93,430,1293,0);
//	CreateObjectMapZoom(MO93,440,1293,0);
//	CreateObjectMapZoom(MO93,450,1293,0);
//	CreateObjectMapZoom(MO93,460,1293,0);
//	CreateObjectMapZoom(MO93,470,1293,0);
//	CreateObjectMapZoom(MO93,480,1293,0);
//	CreateObjectMapZoom(MO93,490,1293,0);

//	CreateObjectMapZoom(MO93,640,1293,0);
//	CreateObjectMapZoom(MO93,650,1293,0);
//	CreateObjectMapZoom(MO93,660,1293,0);
//	CreateObjectMapZoom(MO93,670,1293,0);
//	CreateObjectMapZoom(MO93,680,1293,0);
//	CreateObjectMapZoom(MO93,690,1293,0);
//	CreateObjectMapZoom(MO93,700,1293,0);
//	CreateObjectMapZoom(MO93,710,1293,0);
//	CreateObjectMapZoom(MO93,720,1293,0);
//	CreateObjectMapZoom(MO93,730,1293,0);
//	CreateObjectMapZoom(MO93,740,1293,0);
//	CreateObjectMapZoom(MO93,750,1293,0);
}

func CreateJungle()
{

//	CreateObjectMapZoom(_TR1,2990,1290,0);
//	CreateObjectMapZoom(_TR1,3050,1290,0);
//	CreateObjectMapZoom(_TR2,3100,1290,0);
//	CreateObjectMapZoom(_TR1,3130,1290,0);
//	CreateObjectMapZoom(_TR1,3170,1290,0);
//	CreateObjectMapZoom(_TR2,3250,1290,0);
//	CreateObjectMapZoom(_TR1,3300,1290,0);
//	CreateObjectMapZoom(_TR1,3360,1290,0);
//	CreateObjectMapZoom(_TR2,3405,1290,0);
//	CreateObjectMapZoom(_TR1,3440,1290,0);
//	CreateObjectMapZoom(_TR2,3500,1290,0);
//	CreateObjectMapZoom(_TR1,3520,1290,0);
//	CreateObjectMapZoom(_TR2,3580,1290,0);
//	CreateObjectMapZoom(_TR1,3600,1290,0);
//	CreateObjectMapZoom(_TR1,3650,1290,0);
//	CreateObjectMapZoom(_TR2,3710,1290,0);
//	CreateObjectMapZoom(_TR1,3780,1290,0);
//	CreateObjectMapZoom(_TR1,3850,1290,0);
//	CreateObjectMapZoom(_BIR,3380,1110,0);
//	CreateObjectMapZoom(_BIR,3700,1110,0);
}

func CreateWaterfall()
{
//	CreateObjectMapZoom(_WAF,2920,515,0);
}

func RevealTunnel()
{
	DigFreeRect(2220,  496,  30, 534, false);
	DigFreeRect(2192,  496,  40,  30, false);
	DigFreeRect(2056,  648, 192,  30, false);
	DigFreeRect(2232, 1000, 128,  30, false);
	DigFreeRect(1830,  944, 400,  30, false);
}