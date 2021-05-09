#include "PanneauDAcceleration.h"

PanneauDAcceleration::PanneauDAcceleration()
	:Obstacle{}
	,VelocityX{ 0 }
	,Largeur{120}
	,Hauteur{109}
{}

PanneauDAcceleration::~PanneauDAcceleration()
{}

//void PanneauDAcceleration::Update(long Millis)
//{
//
//}

double PanneauDAcceleration::GetLargeur()
{
	return Largeur;
}

double PanneauDAcceleration::GetHauteur()
{
	return Hauteur;
}
