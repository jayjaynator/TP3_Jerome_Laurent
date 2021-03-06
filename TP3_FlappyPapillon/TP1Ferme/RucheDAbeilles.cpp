#include "RucheDAbeilles.h"
#include "Constants.h"

RucheDAbeilles::RucheDAbeilles(double PositionDepartY)
	:Obstacle{4, PositionDepartY }
	,Largeur{90}
	,Hauteur{95}
{}

RucheDAbeilles::~RucheDAbeilles()
{
}

void RucheDAbeilles::Update(long Millis)
{
	PositionX -= GameSpeed * Millis;
	

	if (IsGoingUp)
	{
		PositionY -= 0.1 * Millis;

		if (PositionY <= 0)
			IsGoingUp = false;	
	}
	else
	{
		PositionY += 0.1 * Millis;

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
