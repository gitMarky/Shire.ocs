
static npc_tuti, npc_pirate, npc_carpenter, npc_beggar;

func Initialize()
{
//	CreateObjectMapZoom(_BGC,1160,1291,0);
//	CreateObjectMapZoom(_WAF,2920,515,0);

//	CreateObjectMapZoom(_VEW,200,650,0);
//	CreateObjectMapZoom(AB93,100,1335,0);
//	CreateObjectMapZoom(_IO1,1140,1200,0);
//	CreateObjectMapZoom(IL93,920,2150,0);
//	CreateObjectMapZoom(_MHO,1820,1280,0);
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
//	CreateObjectMapZoom(_HAE,1450,2200,0);
//	CreateObjectMapZoom(_TIS,1437,2200,0);
//	CreateObjectMapZoom(_BED,945,2150,0);

//	var cupboard1 = CreateObjectMapZoom(_SRK,920,2150,0);
//	cupboard1->CreateContents(GC06);
//	cupboard1->CreateContents(GC06);

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
//	cupboard6->CreateContents(GC06);
//	cupboard6->CreateContents(GC06);
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
//	CreateObjectMapZoom(_PEA,1200,1270,0);
//	CreateConstruction(SAWM,1200,1290,0,100,1);
//	CreateConstruction(WMIL,1260,1290,0,100,1);
//	CreateObjectMapZoom(_DRI,1290,1200,0);
//	CreateConstruction(_LA2,1320,1290,0,100,1);
//	CreateObjectMapZoom(_QUI,1365,1200,0);
//	CreateObjectMapZoom(_WAM,1440,1200,0);
//	CreateConstruction(_CS2,1440,1290,0,100,1);
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



//	CreateObjectMapZoom(_NDO,3020,1200,0);

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
	npc_carpenter=CreateObject(Clonk, 815, 1025, NO_OWNER);
	npc_carpenter->SetName("$NPC_Carpenter$");
	npc_carpenter->SetDialogueEx("Carpenter");
}

func CreateBeggar()
{
	npc_beggar=CreateObject(Clonk, 855, 960, NO_OWNER);
	npc_beggar->SetName("$NPC_Beggar$");
	npc_beggar->SetDialogueEx("Beggar");
}