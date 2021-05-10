#include "BonusDeVie.h"

BonusDeVie::BonusDeVie(double PositionDepartY)
	:Obstacle{1, PositionDepartY}
	
	,Largeur{50}
	,Hauteur{50}
{}

BonusDeVie::~BonusDeVie()
{}


double BonusDeVie::GetLargeur()
{
	return Largeur;
}

double BonusDeVie::GetHauteur()
{
	return Hauteur;
}
