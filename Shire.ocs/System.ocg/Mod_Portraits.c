
global func ShirePortrait(string name)
{
	return {Source = ShireCharacters, Name = Format("Portrait%s", name), Color = GetColor()};
}

global func SetShirePortrait(string name)
{
	this.portrait = ShirePortrait(name);
}