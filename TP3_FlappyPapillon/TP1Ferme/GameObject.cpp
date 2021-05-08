#include "GameObject.h"

GameObject::GameObject(double X, double Y, double L, double H)
	:PositionX{X}
	,PositionY{Y}
	,Largeur{L}
	,Hauteur{H}
{
}

void GameObject::Update(long Millis)
{

}

double GameObject::GetX() const
{
	return PositionX;
}

double GameObject::GetY() const
{
	return PositionY;
}

void GameObject::SetX(double X)
{
	PositionX = X;
}

void GameObject::SetY(double Y)
{
	PositionY = Y;
}

double GameObject::GetLargeur() const
{
	return Largeur;
}

double GameObject::GetHauteur() const
{
	return Hauteur;
}
