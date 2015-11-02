/**
	Cupboard
	Storage for items.
*/

local is_open;

/*-- Contents --*/

public func IsContainer() { return true; }

private func MaxContentsCount()
{
	return 50;
}

protected func RejectCollect()
{
	if (ContentsCount() >= this->MaxContentsCount())
		return true;
	return false;
}

public func OnContentMenuOpened()
{
}

public func OnContentMenuClosed()
{
}

local Name = "$Name$";
local Description = "$Description$";
