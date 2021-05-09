#include "ToileDAraignee.h"

ToileDAraignee::ToileDAraignee()
	:Obstacle{5}
	,VelocityX{0}
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
