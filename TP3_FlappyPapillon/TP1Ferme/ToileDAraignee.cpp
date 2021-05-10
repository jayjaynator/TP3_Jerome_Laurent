#include "ToileDAraignee.h"

ToileDAraignee::ToileDAraignee(double PositionDepartY)
	:Obstacle{5, PositionDepartY }

	,Largeur{99}
	,Hauteur{99}
{}

ToileDAraignee::~ToileDAraignee()
{}


double ToileDAraignee::GetLargeur()
{
	return Largeur;
}

double ToileDAraignee::GetHauteur()
{
	return Hauteur;
}
