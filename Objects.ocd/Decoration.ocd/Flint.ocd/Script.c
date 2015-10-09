/*--- Flint ---*/

protected func Construction()
{
	var graphic = Random(3);
	if(graphic)
		SetGraphics(Format("%d",graphic));
}


local Name = "$Name$";
local Description = "$Description$";
local Plane = 530; // cause it's explosive, players should see it in a pile of stuff
