#include "FiletAInsectes.h"

FiletAInsectes::FiletAInsectes()
	:Obstacle{2}
	,VelocityX{0}
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
