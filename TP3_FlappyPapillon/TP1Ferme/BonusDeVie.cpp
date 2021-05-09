#include "BonusDeVie.h"

BonusDeVie::BonusDeVie()
	:Obstacle{}
	,VelocityX{ 0 }
	,Largeur{50}
	,Hauteur{50}
{}

BonusDeVie::~BonusDeVie()
{}

//void BonusDeVie::Update(long Millis)
//{
//
//
//
//}

double BonusDeVie::GetLargeur()
{
	return Largeur;
}

double BonusDeVie::GetHauteur()
{
	return Hauteur;
}
