#include "ToileDAraignee.h"

ToileDAraignee::ToileDAraignee()
	:Obstacle{}
	,VelocityX{0}
	,Largeur{99}
	,Hauteur{99}
{}

ToileDAraignee::~ToileDAraignee()
{}

//void ToileDAraignee::Update(long Millis)
//{
//
//
//}

double ToileDAraignee::GetLargeur()
{
	return Largeur;
}

double ToileDAraignee::GetHauteur()
{
	return Hauteur;
}
