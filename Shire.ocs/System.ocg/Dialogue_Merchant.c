#appendto Library_Dialogue

public func Dlg_Merchant(object player)
{
	var has_dialogue_eyepatch = !player.dialogue_merchant_eyepatch;
	var has_dialogue_pullover = player.dialogue_merchant_eyepatch
	                        && !player.dialogue_merchant_pullover; 

	if (has_dialogue_eyepatch)
	{
		DlgText("$DlgMerchantA01$", player);
		DlgText("$DlgMerchantA02$");
		DlgText("$DlgMerchantA03$", player);
		DlgText("$DlgMerchantA04$");
		DlgText("$DlgMerchantA05$", player);
		DlgText("$DlgMerchantA06$");
		DlgText("$DlgMerchantA07$", player);
		DlgText("$DlgMerchantA08$");
		DlgText("$DlgMerchantA09$");
		DlgText("$DlgMerchantA10$");
		DlgText("$DlgMerchantA11$");
		DlgText("$DlgMerchantA12$");
		DlgText("$DlgMerchantA13$", player);
		DlgText("$DlgMerchantA14$");
		DlgText("$DlgMerchantA15$", player);
		if (DlgEvent())
		{
			player.dialogue_merchant_eyepatch = true;
			player->CreateObject(Pullover);
			player->SetMeshMaterial("Clonk_Player");
		}
	}
	else if (has_dialogue_pullover)
	{
		var has_pullover = player->FindContents(Pullover);
		if (has_pullover)
		{
			DlgText("$DlgMechantB01$", player);
			DlgText("$DlgMechantB02$");
			DlgText("$DlgMechantB03$", player);
			if (DlgEvent())
			{
				if (has_pullover) has_pullover->RemoveObject();
				player->CreateContents(Eyepatch);
				player.dialogue_merchant_pullover = true;
				shop_low_top->SetGraphics("Pullover", DecoShop, 1, GFXOV_MODE_Base);
				shop->SetGraphics("Pullover", DecoShop, 4, GFXOV_MODE_Base); // workaround for bug #0001458
			}
		}
		else
		{
			DlgText("$DlgMechantB04$");
		    DlgText("$DlgMechantB05$", player);
		}
	}
	else
	{
		DlgText("$DlgMechantB06$");
	}
}
