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

double Obstacle::GetLargeur()
{
	return Largeur;
}

double Obstacle::GetHauteur()
{
	return Hauteur;
}
