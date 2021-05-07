#include "GameObject.h"

GameObject::GameObject()
	:PositionX{0}
	,PositionY{0}
	,Largeur{0}
	,Hauteur{0}
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
