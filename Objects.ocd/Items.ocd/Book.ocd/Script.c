/*--
An item, that looks like a book. Can have a dialogue.

@note The item gets initialized with a standard dialogue.

@title Book
@version 0.1.0
@author Sven2 (Graphics), Marky (Script)
 --*/
 
#include Library_Dialogue

protected func Initialize()
{
	SetColor(HSL(Random(256), 255, Random(128) + 128));
	_inherited(...);
}
 
/**
 * Starts the dialogue.
 *
 * @par player The object that activated the book. The dialogue is displayed to this object.
 */ 
protected func ControlUseStart(object player)
{
	ProgressDialogue(player);
	return true;
}


public func MenuOK(proplist menu_id, object player)
{
	// prevent the menu from closing when pressing MenuOK
	ProgressDialogue(player);
}

public func SetDialogue(string name)
{
	dlg_target = this; // TODO: Replace with method calls
	dlg_name = name;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// properties

local Name = "$Name$";
local Description = "$Description$";
local Collectible = 1;
