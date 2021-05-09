#include "BonusDeVie.h"

BonusDeVie::BonusDeVie()
	:Obstacle{1}
	,VelocityX{ 0 }
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
