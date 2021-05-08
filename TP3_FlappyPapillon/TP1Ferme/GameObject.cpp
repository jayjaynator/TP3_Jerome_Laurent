#include "GameObject.h"

GameObject::GameObject(double X, double Y)
	:PositionX{X}
	,PositionY{Y}
	,AccelerationActive{false}
{}

void GameObject::Update(long Millis)
{}

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
