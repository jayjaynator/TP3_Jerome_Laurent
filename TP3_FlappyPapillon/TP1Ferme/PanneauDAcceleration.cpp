#include "PanneauDAcceleration.h"

PanneauDAcceleration::PanneauDAcceleration()
	:Obstacle{3}
	,VelocityX{ 0 }
	,Largeur{120}
	,Hauteur{109}
{}

PanneauDAcceleration::~PanneauDAcceleration()
{}



double PanneauDAcceleration::GetLargeur()
{
	return Largeur;
}

double PanneauDAcceleration::GetHauteur()
{
	return Hauteur;
}
