#appendto ElevatorCase

public func GetNeededPower()
{
	return 0;
}

public func ControlDown(object clonk)
{
	if (IsSlave()) 
		return Control2Master("ControlDown", clonk);
	
	// Pressing down when already on ground results in drilling.
	//var drill = !!GetContact(-1, CNAT_Bottom);
	
	StopAutomaticMovement();
	SetMoveDirection(COMD_Down, true, false); // never drill!
	return true;
}