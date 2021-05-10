#include "RucheDAbeilles.h"
#include "Constants.h"

RucheDAbeilles::RucheDAbeilles()
	:Obstacle{4, Hauteur}
	,Largeur{90}
	,Hauteur{95}
{}

RucheDAbeilles::~RucheDAbeilles()
{
}

void RucheDAbeilles::Update(long Millis)
{
	PositionX -= 0.2 * Millis;

	if (IsGoingUp)
	{
		PositionY -= 0.5 * Millis;

		if (PositionY <= 0)
			IsGoingUp = false;	
	}
	else
	{
		PositionY += 0.5 * Millis;

		if (PositionY >= SCREEN_HEIGHT - Hauteur)
			IsGoingUp = true;
	}

}

double RucheDAbeilles::GetLargeur()
{
	return Largeur;
}

double RucheDAbeilles::GetHauteur()
{
	return Hauteur;
}
