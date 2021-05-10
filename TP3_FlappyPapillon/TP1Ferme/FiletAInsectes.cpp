#include "FiletAInsectes.h"

FiletAInsectes::FiletAInsectes(double PositionDepartY)
	:Obstacle{2, PositionDepartY }
	
	,Largeur{78}
	,Hauteur{88}
{}

FiletAInsectes::~FiletAInsectes()
{}

void FiletAInsectes::Update(long Millis)
{



}

double FiletAInsectes::GetLargeur()
{
	return Largeur;
}

double FiletAInsectes::GetHauteur()
{
	return Hauteur;
}
