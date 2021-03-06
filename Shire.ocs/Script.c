
static npc_tuti, npc_pirate, npc_carpenter, npc_beggar, npc_drin;
static npc_merchant, npc_iolo, npc_iolos_father, npc_mhoram;
static npc_ndo, npc_pea, npc_quimby, npc_guardsman, npc_scientist;
static door_hut_iolo_top, door_hut_iolo_low, door_castle_top, door_shop_top;
static enemy_cyclops, shop, shop_low_top, dimension_rift, npc_doctor;
static cyclops_dangerous;
static started;

func Initialize()
{
    cyclops_dangerous = false;
	var debug = false;
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
	
	CreateRealWorld();
	
	// deco

	CreateButterflies();
	CreateCorpses();
	CreateFields();
	CreateFlintTrees();
	CreateJungle();
	CreateWaterfall();

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
	CreateCyclops();
	CreateDoctor();

	if (!debug)
	{
		StartBackgroundSequence("Trigger_Bird_Elevator");
		StartBackgroundSequence("Trigger_Clonkarabas");
		StartBackgroundSequence("Trigger_Bird_Cyclops");
	}
}

func InitializePlayer(int player)
{
	var crew = GetHiRank(player);
	crew->SetPosition(80, 1048);

	InitializeCrew(crew);

	SetPlrKnowledge(player, Bread);
	
	if (!started)
	{
		started = true;
		crew->SetLightRange(0, 0);
		SetAmbientBrightness(0);
	
		var dialogue = crew->SetDialogueEx("Intro");
		dialogue->Interact(crew);
	}
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
	npc_tuti->SetShirePortrait("Tuti");
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
	npc_pirate->SetShirePortrait("Pirate");
	
	// hat
	var hat = npc_pirate->CreateContents(PirateHat);
	npc_pirate->AttachMesh(hat, "skeleton_head", "Base", Trans_Mul(Trans_Rotate(20, 0, 1, 0),
	                                                               Trans_Rotate(115, 0, 0, 1),
	                                                               Trans_Rotate(10, 0, 1, 0),
	                                                               Trans_Translate(-2200, -4200, 1500),
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
	npc_carpenter->SetShirePortrait("Carpenter");
}

func CreateBeggar()
{
	npc_beggar=CreateObject(Clonk, 708, 1020, NO_OWNER);
	npc_beggar->SetName("$NPC_Beggar$");
	npc_beggar->SetDialogueEx("Beggar");
	npc_beggar->RemoveBackpack();
	npc_beggar->SetMeshMaterial("Clonk_Beggar");
	npc_beggar->SetShirePortrait("Beggar");
}

func CreateDrin()
{
	npc_drin=CreateObject(Clonk, 945, 1020, NO_OWNER);
	npc_drin->SetName("$NPC_Drin$");
	npc_drin->SetDialogueEx("Drin");
	npc_drin->RemoveBackpack();
	npc_drin->SetMeshMaterial("Clonk_Drin");
	npc_drin->SetShirePortrait("Drin");
}

func CreateMerchant()
{
	npc_merchant=CreateObject(Clonk, 990, 1743, NO_OWNER);
	npc_merchant->SetName("$NPC_Merchant$");
	npc_merchant->SetDialogueEx("Merchant");
	npc_merchant->RemoveBackpack();
	
	var plane = npc_merchant.Plane;
	var counter =  CreateObject(DecoShop, 985, 1722, NO_OWNER);
	counter->SetGraphics("Counter");
	counter.Plane = plane - 1;
	npc_merchant.Plane = plane - 2;
}

func CreateIolosFather()
{
	npc_iolos_father=CreateObject(Clonk, 785, 1020, NO_OWNER);
	npc_iolos_father->SetName("$NPC_IolosFather$");
	npc_iolos_father->SetDialogueEx("IolosFather");
	npc_iolos_father->RemoveBackpack();
	npc_iolos_father->SetMeshMaterial("Clonk_IolosFather");
	npc_iolos_father->SetShirePortrait("IolosFather");
}

func CreateIolo()
{
	npc_iolo=CreateObject(Clonk, 620, 1743, NO_OWNER);
	npc_iolo->SetName("$NPC_Iolo$");
	npc_iolo->RemoveBackpack();
	npc_iolo->SetMeshMaterial("Clonk_Iolo");
	npc_iolo->SetDialogueEx("Iolo");
	npc_iolo->SetShirePortrait("Iolo");
}

func CreateMhoram()
{
	npc_mhoram=CreateObject(Clonk, 1455, 1020, NO_OWNER);
	npc_mhoram->SetName("$NPC_Mhoram$");
	npc_mhoram->SetDialogueEx("Mhoram");
	npc_mhoram->RemoveBackpack();
	npc_mhoram->SetMeshMaterial("Clonk_Mhoram");
	npc_mhoram->SetShirePortrait("Mhoram");
}

func CreateNDo()
{
	npc_ndo=CreateObject(Clonk, 2415, 1015, NO_OWNER);
	npc_ndo->SetName("$NPC_NDo$");
	npc_ndo->SetDialogueEx("NDo");
	npc_ndo->RemoveBackpack();
	npc_ndo->SetMeshMaterial("Clonk_NDo");
	npc_ndo->SetShirePortrait("Ndo");
}

func CreatePea()
{
	npc_pea=CreateObject(Clonk, 840, 1020, NO_OWNER);
	npc_pea->SetName("$NPC_Pea$");
	npc_pea->SetDialogueEx("Pea");
	// pea may keep his backpack!
	npc_pea->SetMeshMaterial("Clonk_Pea");
	npc_pea->SetShirePortrait("Pea");
}

func CreateQuimby()
{
	npc_quimby=CreateObject(Clonk, 1015, 1020, NO_OWNER);
	npc_quimby->SetName("$NPC_Quimby$");
	npc_quimby->SetDialogueEx("Quimby");
	npc_quimby->RemoveBackpack();
	npc_quimby->SetMeshMaterial("Clonk_Quimby");
	npc_quimby->SetShirePortrait("Quimby");
}

func CreateGuardsman()
{
	npc_guardsman=CreateObject(Clonk, 1080, 985, NO_OWNER);
	npc_guardsman->SetName("$NPC_Guardsman$");
	npc_guardsman->SetDialogueEx("Guardsman");
	npc_guardsman->RemoveBackpack();
	npc_guardsman->SetMeshMaterial("Clonk_Guardsman");
	npc_guardsman->SetShirePortrait("Guardsman");
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
	npc_scientist->SetShirePortrait("Scientist");
}

func CreateCyclops()
{
	// Cyclops
	enemy_cyclops = CreateObject(Clonk, 3085, 1010, NO_OWNER);
	enemy_cyclops->SetCon(250);
	enemy_cyclops->SetObjectLayer(enemy_cyclops);
	enemy_cyclops->SetDir(DIR_Left);
	enemy_cyclops->SetMeshMaterial("Cyclops_Body");
	enemy_cyclops->RemoveBackpack();
	enemy_cyclops->CreateContents(Club);

	var head = enemy_cyclops->CreateContents(CyclopsHead);
	enemy_cyclops->AttachMesh(head, "skeleton_head", "main", Trans_Mul(Trans_Translate(-500, 0, 0), Trans_Rotate(90, 0, 0, 1)), AM_DrawBefore);
	
	CreateObject(Tarydium, 3125, 1080, NO_OWNER);
	AddCyclopsAI(enemy_cyclops);
	
	// flames
	
	var flames = [{x = 3022, y = 1020}, {x = 3055, y = 1020}, {x = 2965, y = 1020}];
	
	for (var coordinates in flames)
	{
		// dummy objects did change their shape again after being incinerated
		// using rocks is better in this case
		var flame = CreateObject(Rock, coordinates.x, coordinates.y, NO_OWNER);
		flame.NoBurnDecay = true;
		flame.Visibility = VIS_None;
		flame->SetObjectLayer(flame);
		flame->Incinerate();
	}
	
	// make him hurtable
	CreateObject(CyclopsEye, 3081, 977);
}

func CreateDoctor()
{
	npc_doctor = CreateObject(Clonk, 3000, 230, NO_OWNER);
	npc_doctor->SetName("$NPC_Doctor$");
	npc_doctor->RemoveBackpack();
	npc_doctor->SetGraphics("Alchemist");
	npc_doctor->SetMeshMaterial("Clonk_Doctor");
	npc_doctor->SetMeshMaterial("Clonk_Doctor", 1);
	npc_doctor->SetDir(DIR_Left);
	npc_doctor->SetShirePortrait("Doctor");
}

// ----- *** Buildings Creation *** -----------------------------------------

func CreateCastle()
{
	var castle_low = CreateObject(DecoCastle, 1070, 1727, NO_OWNER);
	castle_low->SetGraphics("Inside");

	var castle_low_top = CreateObject(DecoCastle, 1070, 1727, NO_OWNER);
	castle_low_top->SetSolidMask(0, 0, 67, 55);
	castle_low_top->SetGraphics("InsideTop");
	castle_low_top.Plane = 10000;

	door_castle_top = CreateObject(DecoDoor, 1064, 1024, NO_OWNER);
	var door_castle_low = CreateObject(DecoDoor, 1064, 1744, NO_OWNER);
	door_castle_top->ConnectTo(door_castle_low);
	door_castle_top->SetGraphics("Castle");
	door_castle_low->SetGraphics("Castle");
	door_castle_top->SetEnabled(false);
	door_castle_top->SetDialogueEx("DoorCastle");
	door_castle_top->BecomeEntrance(castle_low_top);
	door_castle_low->BecomeExit(castle_low_top);

	var bed = CreateObject(Bed, 1050, 1738, NO_OWNER);
	bed->Turn(75);

	var cupboard3 = CreateObject(Cupboard, 1080, 1742, NO_OWNER);
	var book = cupboard3->CreateContents(Book);
	book->SetDialogue("Book_Guardsman");

	var cupboard4 = CreateObject(Cupboard, 1090, 1742, NO_OWNER);
	cupboard4->CreateContents(TFlint);
	cupboard4->CreateContents(TFlint);
	cupboard4->CreateContents(TFlint);
	cupboard4->CreateContents(BombArrow); // arrows
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
}

func CreatePirateCastle()
{
	CreateObject(DecoCastle, 2245, 423, NO_OWNER);
	var castle_low = CreateObject(DecoCastle, 2245, 1727, NO_OWNER);
	castle_low->SetGraphics("Inside");

	var castle_low_top = CreateObject(DecoCastle, 2245, 1727, NO_OWNER);
	castle_low_top->SetSolidMask(0, 0, 67, 55);
	castle_low_top->SetGraphics("InsideWaterTop");
	castle_low_top.Plane = 10000;
	
	var door_pcastle_top = CreateObject(DecoDoor, 2239, 440, NO_OWNER);
	var door_pcastle_low = CreateObject(DecoDoor, 2239, 1744, NO_OWNER);
	door_pcastle_top->ConnectTo(door_pcastle_low);
	door_pcastle_top->SetGraphics("WaterCastle");
	door_pcastle_low->SetGraphics("Castle");
	door_pcastle_top->BecomeEntrance(castle_low_top);
	door_pcastle_low->BecomeExit(castle_low_top);


	var cupboard5 = CreateObject(Cupboard, 2255, 1730, NO_OWNER);
	cupboard5->CreateContents(sMett);
	cupboard5->CreateContents(GoldCoin);
	cupboard5->CreateContents(GoldCoin);
	
	var skull = CreateObject(Skull, 2222, 1722, NO_OWNER);
	skull->SetCategory(C4D_StaticBack);
	skull->SetObjectLayer(skull);
	
	CreateObject(Sailboat, 2205, 374, NO_OWNER);
	CreateObject(Bed, 2263, 1738, NO_OWNER)->Turn(70);
}

func CreateStoneHut()
{
	CreateObject(DecoStoneHut, 730, 1007, NO_OWNER);
	var stonehut_low = CreateObject(DecoStoneHut, 730, 1727, NO_OWNER);
	var stonehut_low_top = CreateObject(DecoStoneHut, 730, 1727, NO_OWNER);
	stonehut_low_top->SetSolidMask(0, 0, 60, 55);
	stonehut_low->SetGraphics("Inside");
	stonehut_low_top->SetGraphics("Top");
	stonehut_low_top.Plane = 10000;
	
	var door_stonehut_top = CreateObject(DecoDoor, 742, 1024, NO_OWNER);
	var door_stonehut_low = CreateObject(DecoDoor, 742, 1744, NO_OWNER);
	door_stonehut_top->ConnectTo(door_stonehut_low);
	door_stonehut_top->SetGraphics("Stone");
	door_stonehut_low->SetGraphics("Stone");
	door_stonehut_top->BecomeEntrance(stonehut_low_top);
	door_stonehut_low->BecomeExit(stonehut_low_top);


	var kitchen = CreateObject(Kitchen, 740, 1726);
	kitchen.MeshTransformation = Trans_Mul(Trans_Rotate(30, 0, 1, 0), Trans_Scale(1200, 1200, 1200));
    kitchen->SetShape(-25,-23,20,50);
    kitchen->SetMeshMaterial("Kitchen_Alternate");
    CreateObject(Flour, 709, 1748, NO_OWNER);
    CreateObject(Flour, 713, 1748, NO_OWNER);
    CreateObject(EnvPack_Painting, 711, 1734, NO_OWNER).MeshTransformation = Trans_Mul(Trans_Scale(30, 35, 35), Trans_Rotate(-3, 0, 0, 1));

	var chest = CreateObject(Chest, 752, 1740, NO_OWNER);
	chest.MeshTransformation = Trans_Scale(400, 400, 400);
	chest->CreateContents(Coal);
	var book = chest->CreateContents(Book);
	book->SetDialogue("Book_Mhoram");
	var barrel = CreateObject(Barrel, 756, 1026, NO_OWNER);
	barrel->PutLiquid("Water", 300);	
}

func CreateSawmill()
{
	CreateObject(DecoSawmill, 840, 1005, NO_OWNER);
	CreateObject(EnvPack_TreeTrunks, 804, 1033, NO_OWNER);
}

func CreateScientistLab()
{
	var cupboard7 = CreateObject(Cupboard, 103, 1741, NO_OWNER);
	cupboard7->SetGraphics("Lab");
	AddEffect("IntRespawnGrenades", cupboard7, 1, 300);

	var book = cupboard7->CreateContents(Book);
	book->SetDialogue("Book_Mystery");

	var cupboard8 = CreateObject(Cupboard, 114, 1741, NO_OWNER);
	cupboard8->SetGraphics("Lab");
	AddEffect("IntRespawnGrenades", cupboard8, 1, 300);
	var grenade_launcher = cupboard8->CreateContents(GrenadeLauncher);
	grenade_launcher->SetMeshMaterial("grenade_launcher_alt");

	CreateObject(DecoLab, 125, 527, NO_OWNER);
	DigFreeRect(88 , 520 , 70, 7);	
	DigFreeRect(88 , 1744 , 70, 7);
	var lab_low = CreateObject(DecoLab, 125, 1751, NO_OWNER);
	var lab_low_top = CreateObject(DecoLab, 125, 1751, NO_OWNER);
	lab_low_top->SetSolidMask(0, 0, 71, 95);
	lab_low->SetGraphics("Inside");
	lab_low_top->SetGraphics("Top");
	lab_low_top.Plane = 10000;

	var door_lab_top = CreateObject(DecoSteelDoor, 135, 519, NO_OWNER);
	var door_lab_low = CreateObject(DecoSteelDoor, 135, 1743, NO_OWNER);
	door_lab_top->ConnectTo(door_lab_low);
	door_lab_top->BecomeEntrance(lab_low_top);
	door_lab_low->BecomeExit(lab_low_top);

	CreateObject(DimensionVector, 55, 525, NO_OWNER);
}

func CreateShop()
{
    shop = CreateObject(DecoShop, 985, 1002, NO_OWNER);
    var shop_low = CreateObject(DecoShop, 985, 1722, NO_OWNER);
    shop_low_top = CreateObject(DecoShop, 985, 1722, NO_OWNER);
	shop_low_top->SetSolidMask(0, 0, 60, 65);
	shop_low->SetGraphics("Inside");
	shop_low_top->SetGraphics("Jeans");
	shop_low_top->SetGraphics("Top", DecoShop, 2, GFXOV_MODE_Base);
	shop_low_top.Plane = 10000;

    door_shop_top = CreateObject(DecoDoor, 970, 1024, NO_OWNER);
    var door_shop_low = CreateObject(DecoDoor, 970, 1744, NO_OWNER);
	door_shop_top->ConnectTo(door_shop_low);
	door_shop_top->SetGraphics("Shop");
	door_shop_low->SetGraphics("Shop");
	door_shop_top->SetEnabled(false);
	door_shop_top->SetDialogueEx("DoorShop");
	door_shop_top->BecomeEntrance(shop_low_top);
	door_shop_low->BecomeExit(shop_low_top);


	// cool effects
	shop->SetGraphics("Inside");
	shop->SetGraphics("Counter", DecoShop, 2, GFXOV_MODE_Base);
	shop->SetGraphics(nil, nil, 3, GFXOV_MODE_Object, nil, nil, shop_low_top);
	shop->SetGraphics(nil, DecoShop, 5, GFXOV_MODE_Base);
	AddEffect("IntDisplayMerchant", shop, 1, 1);

//	CreateObjectMapZoom(_SRK,1400,2200,-1); // cupboard
//	CreateObjectMapZoom(_BED,1400,2130,0); // table, chairs, bed
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
	var hut_low_top = CreateObject(DecoHut, 610, 1727, NO_OWNER);
	hut_low_top->SetSolidMask(0, 0, 60, 55);
	hut_low->SetGraphics("Inside");
	hut_low_top->SetGraphics("Top");
	hut_low_top.Plane=10000;
	door_hut_iolo_top = CreateObject(DecoDoor, 600, 1024, NO_OWNER);
	door_hut_iolo_low = CreateObject(DecoDoor, 600, 1744, NO_OWNER);
	door_hut_iolo_top->ConnectTo(door_hut_iolo_low);
	door_hut_iolo_top->BecomeEntrance(hut_low_top);
	door_hut_iolo_low->BecomeExit(hut_low_top);

	var cupboard1 = CreateObject(Cupboard, 630, 1742, NO_OWNER);
	cupboard1->CreateContents(GoldCoin);
	cupboard1->CreateContents(GoldCoin);
	
	var bed = CreateObject(Bed, 620, 1738, NO_OWNER);
	bed->Turn(120);
	bed->SetObjectLayer(bed);
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
	
	var dead_clonkarabas = CreateObject(Clonk, 2925, 230, NO_OWNER);
	dead_clonkarabas->RemoveBackpack();
	dead_clonkarabas->SetGraphics("Alchemist");
	dead_clonkarabas->SetMeshMaterial("Clonk_Clonkarabas");
	dead_clonkarabas->SetMeshMaterial("Clonk_Clonkarabas", 1);
	dead_clonkarabas->SetDir(DIR_Right);
	dead_clonkarabas->Kill(dead_clonkarabas, true);
	
}

func CreateFields()
{
	PlaceForest([Wheat], 220, 1040, 180);
	Grass->Place(80, Shape->Rectangle(50, 1020, 170, 50));
	Grass->Place(60, Shape->Rectangle(410, 1020, 100, 50));
	Grass->Place(50, Shape->Rectangle(1300, 720, 100, 40));
	
	CreateObject(Mushroom, 1435, 1031, NO_OWNER);
	CreateObject(Mushroom, 1415, 1033, NO_OWNER);
	CreateObject(Mushroom, 1428, 1043, NO_OWNER);
	CreateObject(Mushroom, 1448, 1026, NO_OWNER);
	CreateObject(Mushroom, 1439, 1027, NO_OWNER);
	CreateObject(Mushroom, 1423, 1042, NO_OWNER);
}

func CreateFlintTrees()
{
	PlaceForestCustom(Tree_Coniferous2, 30, 1070, 200, false);
	PlaceForestCustom(Tree_Coniferous2, 405, 1050, 100, false);
	PlaceForestCustom(Tree_Coniferous2, 1130, 1050, 150, false);

	for (var tree in FindObjects(Find_ID(Tree_Coniferous2)))
	{
		AttachFlints(tree);
	}
}

func AttachFlints(object tree)
{
	var precision = 1000;
	var scale = tree.deco_scale;

	var dy_tree_bottom = tree->GetDefHeight() + tree->GetDefOffset(1);
	var y_tree_bottom = (tree->GetY() + dy_tree_bottom) * precision;

	// the actual center of the scaled tree
	var x_origin = tree->GetX() * precision;
	var y_origin = y_tree_bottom - dy_tree_bottom * scale;

	// calculate the position for the topmost point of a triangle
	var x_top = x_origin;
	var y_top = y_origin -33 * scale;
	
	// difference from topmost point to leftmost point
	var dx_left = -13 * scale;
	var dy_left = +25 * scale;
	
	// difference from topmost point to rightmost point
	var dx_right = +12 * scale;
	var dy_right = +25 * scale;
	
	var factor_max = 100;
	
	// place actual flints
	var last_factor_sum = 0;
	var flint_amount = RandomX(1, Max(1, scale * 4 / precision));
	for (var i = 1; i <= flint_amount; i++)
	{
		// random factors for placing the flints inside the triangle
		var factor_left = RandomX(0, factor_max);
		var factor_right = RandomX(0, factor_max);
		
		// reroll the factors to get a nicer distribution of flint positions
		for (var factor_sum = factor_left + factor_right; Abs(factor_sum - last_factor_sum) < 20; )
		{
			factor_left = RandomX(0, factor_max);
			factor_right = RandomX(0, factor_max);
			factor_sum = factor_left + factor_right;
		}

		last_factor_sum = factor_left + factor_right;
		
		// actually create the flint and make it non-collectible
		var x = x_top + (factor_left * dx_left + factor_right * dx_right) / (2 * factor_max);
		var y = y_top + (factor_left * dy_left + factor_right * dy_right) / (2 * factor_max);
		
		var flint = CreateObject(TFlint);
		flint->SetPosition(x, y, false, precision);
		flint->SetCategory(C4D_StaticBack);
		flint.Collectible = false;
		flint.Plane = tree.Plane + i;
	}
}

func CreateJungle()
{
	Grass->Place(100, Shape->Rectangle(2400, 1020, 620, 20));
	PlaceForestCustom(Cotton, 2455, 1040, 570, true);
	
	for (var plant in FindObjects(Find_ID(Cotton), Find_InRect(2900, 900, 200, 200)))
	{
		var original = plant->GetClrModulation();
		var percent = Min(100, plant->GetX() - 2900);
		var hundred = 100;
		var r = ((hundred - percent) * GetRGBaValue(original, RGBA_RED  ) + percent * 20) / hundred;
		var g = ((hundred - percent) * GetRGBaValue(original, RGBA_GREEN) + percent * 15) / hundred;
		var b = ((hundred - percent) * GetRGBaValue(original, RGBA_BLUE ) + percent *  5) / hundred;
		
		plant->SetClrModulation(RGB(r, g, b));
	}
}

func PlaceForestCustom(id plant_type, int x, int y, int width, bool oversize)
{
	if (!x) x = 0;
	if (!y) y = LandscapeHeight();
	if (!width) width = LandscapeWidth();

	// Roughly 20% of the size (10% per side) are taken for 'forest ending zones'. Plants will be smaller there.
	var end_zone = Max(1, width * 10 / 100);
	// The width of the standard plants will roughly be the measure for our plant size
	var plant_size = Max(1, plant_type->GetDefWidth()); // our plants will be a lot larger

	var growth, y_pos, plant, x_variance; //, variance = 0, count, j, spot;
	for (var i = plant_size; i < width; i += plant_size)
	{
		growth = 100;
		y_pos = y;
		x_variance = RandomX(-plant_size/2, plant_size/2);
		// End zone check
		if (i < end_zone)
			growth = BoundBy(90 / Max(1, (end_zone * 100 / plant_size)/100) * (i/plant_size), 10, 90);
		else if (i > width - end_zone)
			growth = BoundBy(90 / Max(1, (end_zone * 100 / plant_size)/100) * ((width-i)/plant_size), 10, 90);

		// No ground at y_pos?
		if (!GBackSolid(x + i + x_variance, y_pos)) continue;
		// Get level ground
		while (!GBackSky(x + i + x_variance, y_pos) && y_pos > 0) y_pos--;
		if (y_pos == 0) continue;

		plant = CreateObjectAbove(plant_type, x + i + x_variance, y_pos+5, NO_OWNER);
		SetPlantToDeco(plant);
		
		RandomGrowth(plant, growth, oversize);
		RandomModulation(plant);

		// Every ~7th plant: double plant!
		if (x_variance != 0 && !Random(7))
		{
			y_pos = y;
			if (!GBackSolid(x + i - x_variance, y_pos)) continue;
			while (!GBackSky(x + i - x_variance, y_pos) && y_pos > 0) y_pos--;
			if (y_pos == 0) continue;
			plant = CreateObjectAbove(plant_type, x + i - x_variance, y_pos+5, NO_OWNER);
			plant->SetObjectLayer(plant);
			RandomGrowth(plant, growth, oversize);
			RandomModulation(plant);
		}
	}
}

func SetPlantToDeco(object plant)
{
		plant->SetObjectLayer(plant);
		plant.MeshTransformation = Trans_Rotate(Random(360), 0, 1, 0);
		plant->RemoveTimer("Reproduction");
		plant->RemoveTimer("Seed");
		plant->RemoveTimer("WaterCheck");
		
		var x = plant->GetX();
		if (x > 2500 && x < 2555) return;
		
		if (!Random(3)) plant.Plane = 510;
}

func RandomGrowth(object plant, int growth, bool oversize)
{
	var min = growth * growth / 20 + 500;
	var max = min + 45 * Sqrt(min);
	
	var scale = RandomX(min, max);
	

	var m = -18;

	var y = m * scale  - m * 1000;
	
	if (!oversize)
	{
		scale = 1000 * scale / max;
		y = (plant->GetDefHeight() + plant->GetDefOffset(1)) * (1000 - scale); 
	}
	
	plant->SetObjDrawTransform(scale, 0, 0, 0, scale, y);
	plant.deco_scale = scale;
}

func RandomModulation(object plant)
{
	var dark = RandomX(150, 255);
	plant->SetClrModulation(RGB(dark, dark, dark));
}

func CreateWaterfall()
{
	Seaweed->Place(15, Shape->Rectangle(2170, 420, 180, 50));
	AddEffect("IntWaterfall", nil, 1, 1, nil);

	var dummy = CreateObject(Rock, 2333, 395, NO_OWNER);
	dummy->Sound("waterfall", false, nil, nil, 1);
	dummy->SetClrModulation(RGBa(255, 255, 255, 0));
	dummy.Collectible = false;
	dummy->SetCategory(C4D_StaticBack);
}

func CreateRealWorld()
{
	var light_red = RGB(255, 0, 0);
	var light_yellow = RGB(255, 255, 190);


	CreateObject(DecoSkyline, 3007, 234, NO_OWNER).Plane = -1;

	// porsche
	CreateObject(Porsche, 2955, 240, NO_OWNER);	
	CreateLight(2972, 232, 30, Fx_Light.LGT_Constant, nil, 10)->SetLightColor(light_red);
	CreateLight(2928, 232, 30, Fx_Light.LGT_Constant, nil, 10)->SetLightColor(light_yellow);

	// ambulance
	CreateObject(Ambulance, 3035, 240, NO_OWNER);
	CreateLight(3028, 208, 30, Fx_Light.LGT_Constant, nil, 10)->SetLightColor(light_red);
	CreateLight(3050, 208, 30, Fx_Light.LGT_Constant, nil, 10)->SetLightColor(light_red);
	CreateLight(3007, 208, 30, Fx_Light.LGT_Constant, nil, 10)->SetLightColor(light_red);
	
	CreateLight(3042, 227, 30, Fx_Light.LGT_Constant, nil, 10)->SetLightColor(light_yellow);
	CreateLight(3060, 227, 30, Fx_Light.LGT_Constant, nil, 10)->SetLightColor(light_yellow);
	
}

global func RevealTunnel()
{
	DigFreeRect(2220,  496,  30, 534, false);
	DigFreeRect(2192,  496,  40,  30, false);
	DigFreeRect(2056,  648, 192,  30, false);
	DigFreeRect(2232, 1000, 128,  30, false);
	DigFreeRect(1830,  944, 400,  30, false);
}

global func FxIntRespawnGrenadesTimer(object target, proplist effect, int timer)
{
	if (ObjectCount(Find_ID(Grenade)) < 5)
	{
		target->CreateContents(Grenade);
	}
}

global func FxIntDisplayMerchantTimer(object target, proplist effect, int timer)
{
	if (npc_merchant)
	{
		var precision = 1000;
		var x = npc_merchant->GetX(precision) - target->GetX(precision);
		target->SetGraphics(nil, nil, 1, GFXOV_MODE_Object, nil, nil, npc_merchant);
	    target->SetObjDrawTransform(1000, 0, x, 0, 1000, 20 * precision, 1);
    }
}

global func FxIntWaterfallTimer(object target, proplist effect, int timer)
{

		var color = GetAverageTextureColor("water");
		var particles =
		{	
			CollisionVertex = 500,
			Size = 16,
//			Phase = PV_Linear(0, 7),
			ForceX = 0,
			ForceY = PV_Gravity(1000),
			Alpha = PV_Linear(90, 180),
			Rotation = PV_Random(0, 360),
			OnCollision = PC_Bounce(200),
			R = (color >> 16) & 0xff,
			G = (color >>  8) & 0xff,
			B = (color >>  0) & 0xff,
		};
		
		CreateParticle("Dust", 2342 + RandomX(-2, +2), 233, 0, 0, 10, particles);
		CreateParticle("Dust", 2333 + RandomX(-2, +2), 245, 0, 0, 17, particles);
		CreateParticle("Dust", 2333 + RandomX(-2, +2), 260, 0, 0, 13, particles);
		CreateParticle("Dust", 2333 + RandomX(-2, +2), 280, 0, 0, 13, particles);
		CreateParticle("Dust", 2333 + RandomX(-2, +2), 295, 0, 0, 13, particles);
		//CreateParticle("Dust", 2320, 245, 0, 0, 50, particles);

		var bottom = particles;
		bottom.Size = 18;
		bottom.R = 255;
		bottom.G = 255;
		bottom.B = 255;
		bottom.ForceY = 0;
		bottom.Alpha = PV_KeyFrames(0, 0, 0, 250, 60, 1000, 0);
		
		// 2342, 233
		// 2333, 245
		// 2333, 395

		CreateParticle("Dust", 2333 + RandomX(-5, 5), 395, RandomX(-5,5), RandomX(-5, 0), 24, bottom);
}

func OnClonkDeath(object clonk, killed_by)
{
	var plr = clonk->GetOwner();
	if (plr == NO_OWNER) return;

	var crew = CreateObject(Clonk, 80, 1048, plr);
	crew->GrabObjectInfo(clonk);
	crew->GrabShireInfo(clonk);
	crew->MakeCrewMember(plr);
	SetCursor(plr, crew);
	Rule_BaseRespawn->TransferInventory(clonk, crew);
	InitializeCrew(crew);

	if (clonk->GetX() > 2415 && clonk->GetY() > 800 && clonk->GetY() < 1200)
	{
		crew->SetPosition(2385, 1015);
	}
}

func InitializeCrew(object crew)
{
	crew->RemoveBackpack();
	if (crew.dialogue_merchant_eyepatch)
	{
		crew->SetMeshMaterial("Clonk_Player");
	}
	else
	{
		crew->SetMeshMaterial("Clonk_PlayerPullover");
	}
}