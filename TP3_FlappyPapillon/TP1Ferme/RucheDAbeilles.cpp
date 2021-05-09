#include "RucheDAbeilles.h"

RucheDAbeilles::RucheDAbeilles()
	:Obstacle{4}
	,VelocityX{0}
	,Largeur{90}
	,Hauteur{95}
{}

RucheDAbeilles::~RucheDAbeilles()
{
}

void RucheDAbeilles::Update(long Millis)
{
}

double RucheDAbeilles::GetLargeur()
{
	return Largeur;
}

double RucheDAbeilles::GetHauteur()
{
	return Hauteur;
}
