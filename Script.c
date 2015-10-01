
static npc_tuti, npc_pirate, npc_carpenter, npc_beggar, npc_drin;
static npc_merchant, npc_iolo, npc_iolos_father, npc_mhoram;
static npc_ndo, npc_pea, npc_quimby, npc_guardsman, npc_scientist;

func Initialize()
{
	CreateObject(DecoCity, 795, 1031, NO_OWNER);
//	CreateObjectMapZoom(_WAF,2920,515,0);

//	CreateObjectMapZoom(AB93,100,1335,0);
//	CreateObjectMapZoom(TI93,300,300,0);

//	CreateObjectMapZoom(_HNH,905,2260,0);
//	CreateObjectMapZoom(_HNS,1405,2260,0);
//	CreateObjectMapZoom(_HN2,405,2260,0);
//	CreateObjectMapZoom(_HNB,2025,2260,0);
//	CreateObjectMapZoom(_HNZ,3650,2245,0);
//	CreateObjectMapZoom(_HNP,2715,2260,0);
//	CreateObjectMapZoom(_LIN,1400,2230,-1);
//	CreateObjectMapZoom(_SRK,1400,2200,-1);
//	CreateObjectMapZoom(_BED,1400,2130,0);
//	CreateObjectMapZoom(_TUL,1375,2200,-1);
//	CreateObjectMapZoom(_ST2,1375,2130,0); 
//	CreateObjectMapZoom(_HUI,900,2230,-1);
//	CreateObjectMapZoom(_TUH,875,2200,-1);
//	CreateObjectMapZoom(_TIS,1437,2200,0);
//	CreateObjectMapZoom(_BED,945,2150,0);

//	var cupboard1 = CreateObjectMapZoom(_SRK,920,2150,0);
//	cupboard1->CreateContents(GoldCoin);
//	cupboard1->CreateContents(GoldCoin);

//	CreateObjectMapZoom(_TIS,930,2200,0);
//	CreateObjectMapZoom(_STU,945,2200,0);
//	CreateObjectMapZoom(_ST2,915,2200,0);
//	CreateObjectMapZoom(_HI2,400,2230,-1);
//	CreateObjectMapZoom(_BED,425,2150,0);
//	CreateObjectMapZoom(_TIS,395,2150,0);
//	CreateObjectMapZoom(_ST2,380,2150,0);
//	CreateObjectMapZoom(_STU,450,2200,0);

//	var cupboard2 = CreateObjectMapZoom(_SRK,352,2200,0);
//	cupboard2->CreateContents(COAL);
//	cupboard2->CreateContents(FB23);
//	cupboard2->CreateContents(WBRL);
//	cupboard2->CreateContents(_BU2);

//	CreateObjectMapZoom(_TU2,425,2200,-1);
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

//	CreateObjectMapZoom(_ZWI,3720,2230,-1);
//	CreateObjectMapZoom(_BRT,3600,2120,-1);
//	CreateObjectMapZoom(_BRT,3630,2120,-1);
//	CreateObjectMapZoom(_BRT,3660,2120,-1);
//	CreateObjectMapZoom(OV23,385,2210,0);
//	CreateObjectMapZoom(_PBI,2740,2230,-1);
//	CreateObjectMapZoom(_TUP,2740,2200,0);

//	var cupboard5 = CreateObjectMapZoom(_SRK,2815,2157,0);
//	cupboard5->CreateContents(_SME);

//	CreateObjectMapZoom(_BED,2620,2157,0);
//	var cupboard6 = CreateObjectMapZoom(_SRK,2780,2115,0);
//	cupboard6->CreateContents(GoldCoin);
//	cupboard6->CreateContents(GoldCoin);
//	CreateObjectMapZoom(SLBT,2640,2200,0);

//	var cupboard7 = CreateObjectMapZoom(_SRK,3585,2150,-1);
//	cupboard7->CreateContents(XARP);
//	cupboard7->CreateContents(XARP);
//	var cupboard8 = CreateObjectMapZoom(_SRK,3680,2200,-1);
//	cupboard8->CreateContents(ARWP);
//	cupboard8->CreateContents(ARWP);
//	cupboard8->CreateContents(_HPK);
//	CreateObjectMapZoom(RU10,3680,2200,0);
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
//	CreateConstruction(_HUT,960,1290,0,100,1);

//	CreateConstruction(_BAS,1020,1290,0,100,1);
//	CreateConstruction(_HU2,1080,1290,0,100,1);
//	CreateConstruction(SAWM,1200,1290,0,100,1);
//	CreateConstruction(WMIL,1260,1290,0,100,1);
//	CreateConstruction(_LA2,1320,1290,0,100,1);
//	CreateConstruction(_PBG,2820,550,0,100,1);
//	CreateObjectMapZoom(SLBT,2820,510,0);

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


//	CreateObjectMapZoom(DV93,50,400,0);  

//	var spawn = CreateObjectMapZoom(RP02,410,2200,-1); 
//	spawn->SetAction("Respawn1000");  
//	spawn->CreateContents(HN93);           

//	CreateConstruction(ELEV,1590,915,0,99,1);
//	CreateObjectMapZoom(BRDG,1640,920,0);




//	CreateObjectMapZoom(TC93,3800,1280,0)->SetAction("JungleClonk");
//	CreateObjectMapZoom(TC93,3790,1280,0)->SetAction("JungleClonk");
//	CreateObjectMapZoom(TC93,3700,1280,0)->SetAction("JungleClonk");
//	CreateObjectMapZoom(TC93,3660,1280,0)->SetAction("JungleClonk");


//	DigFreeRect(3910,1270,30,70);
//	CreateObjectMapZoom(_BWL,3940,1280,0);
//	CreateObjectMapZoom(_BU4,3650,2010,0);

//	CreateObjectMapZoom(SC93,1260,1200,0);
//	CreateObjectMapZoom(SC93,1360,1200,0);
//	CreateObjectMapZoom(SC93,1160,1200,0);
//	CreateObjectMapZoom(SC93,1200,1200,0);
//	CreateObjectMapZoom(SC93,1300,1200,0);
//	CreateObjectMapZoom(SC93,300,1200,0);
//	CreateObjectMapZoom(SC93,400,1200,0);
//	CreateObjectMapZoom(SC93,270,1200,0);
//	DigFreeRect(1020,1200,420,90);


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
}

func InitializePlayer(int player)
{
	var crew = GetHiRank(player);
	crew->SetPosition(80, 1048);
	crew->Fling(100, 1335);
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
	npc_tuti=CreateObject(Clonk, 695, 1020, NO_OWNER);
	npc_tuti->SetName("$NPC_Tuti$");
	npc_tuti->SetDialogueEx("Tuti");
}

func CreatePirate()
{
	npc_pirate=CreateObject(Clonk, 2095, 365, NO_OWNER);
	npc_pirate->SetName("$NPC_Pirate$");
	npc_pirate->SetDialogueEx("Pirat");
}

func CreateCarpenter()
{
	npc_carpenter=CreateObject(Clonk, 815, 1020, NO_OWNER);
	npc_carpenter->SetName("$NPC_Carpenter$");
	npc_carpenter->SetDialogueEx("Carpenter");
}

func CreateBeggar()
{
	npc_beggar=CreateObject(Clonk, 855, 1020, NO_OWNER);
	npc_beggar->SetName("$NPC_Beggar$");
	npc_beggar->SetDialogueEx("Beggar");
}

func CreateDrin()
{
	npc_drin=CreateObject(Clonk, 1030, 1020, NO_OWNER);
	npc_drin->SetName("$NPC_Drin$");
	npc_drin->SetDialogueEx("Drin");
}

func CreateMerchant()
{
	npc_merchant=CreateObject(Clonk, 1160, 1760, NO_OWNER);
	npc_merchant->SetName("$NPC_Merchant$");
	npc_merchant->SetDialogueEx("Merchant");
}

func CreateIolosFather()
{
	npc_iolos_father=CreateObject(Clonk, 915, 1020, NO_OWNER);
	npc_iolos_father->SetName("$NPC_IolosFather$");
	npc_iolos_father->SetDialogueEx("IolosFather");
}

func CreateIolo()
{
	npc_iolo=CreateObject(Clonk, 735, 1720, NO_OWNER);
	npc_iolo->SetName("$NPC_Iolo$");
}

func CreateMhoram()
{
	npc_mhoram=CreateObject(Clonk, 1455, 1025, NO_OWNER);
	npc_mhoram->SetName("$NPC_Mhoram$");
	npc_mhoram->SetDialogueEx("Mhoram");
}

func CreateNDo()
{
	npc_ndo=CreateObject(Clonk, 2415, 1020, NO_OWNER);
	npc_ndo->SetName("$NPC_NDo$");
	npc_ndo->SetDialogueEx("NDo");
}

func CreatePea()
{
	npc_pea=CreateObject(Clonk, 1020, 1020, NO_OWNER);
	npc_pea->SetName("$NPC_Pea$");
	npc_pea->SetDialogueEx("Pea");
}

func CreateQuimby()
{
	npc_quimby=CreateObject(Clonk, 1095, 1020, NO_OWNER);
	npc_quimby->SetName("$NPC_Quimby$");
	npc_quimby->SetDialogueEx("Quimby");
}

func CreateGuardsman()
{
	npc_guardsman=CreateObject(Clonk, 1155, 1020, NO_OWNER);
	npc_guardsman->SetName("$NPC_Guardsman$");
	npc_guardsman->SetDialogueEx("Guardsman");
}

func CreateScientist()
{
	npc_scientist=CreateObject(Clonk, 160, 520, NO_OWNER);
	npc_scientist->SetName("$NPC_Scientist$");
	npc_scientist->SetDialogueEx("Scientist");
}

