#include "Obstacle.h"

Obstacle::Obstacle()
	:GameObject{}
	,PositionX{0}
	,PositionY{0}
{}

Obstacle::~Obstacle()
{

}

void Obstacle::Update(long Millis)
{


}

double Obstacle::GetX() const
{
	return PositionX;
}

double Obstacle::GetY() const
{
	return PositionY;
}

void Obstacle::SetX(double X)
{
	PositionX = X;
}

void Obstacle::SetY(double Y)
{
	PositionY = Y;
}

double Obstacle::GetLargeur() const
{
	return Largeur;
}

double Obstacle::GetHauteur() const
{
	return Hauteur;
}
