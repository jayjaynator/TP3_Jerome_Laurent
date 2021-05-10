#include "FiletAInsectes.h"
#include "Constants.h"

FiletAInsectes::FiletAInsectes(double PositionDepartY)
	:Obstacle{2, PositionDepartY }
	
	,Largeur{78}
	,Hauteur{88}
	,TeleportTimer{0}
{}

FiletAInsectes::~FiletAInsectes()
{}

void FiletAInsectes::Update(long Millis, bool Acceleration)
{
	PositionX -= 0.2 * Millis;

	if (Acceleration)
	{
		PositionX -= 0.2 * Millis;
	}
	
	TeleportTimer += Millis;

	if (TeleportTimer >= 750)
	{
		PositionY = rand() % (SCREEN_HEIGHT - 88);
		TeleportTimer = 0;
	}
}

double FiletAInsectes::GetLargeur()
{
	return Largeur;
}

double FiletAInsectes::GetHauteur()
{
	return Hauteur;
}
