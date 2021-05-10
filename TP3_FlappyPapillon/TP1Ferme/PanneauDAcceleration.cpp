#include "PanneauDAcceleration.h"

PanneauDAcceleration::PanneauDAcceleration(double PositionDepartY)
	:Obstacle{3,PositionDepartY }
	
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
