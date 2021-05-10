#include "Constants.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Obstacle.h"

Obstacle::Obstacle(int Type, double posY)
	:GameObject{ SCREEN_WIDTH+1, PosYRand()}
	, TypeObstacle(Type)
	, PositionY(PosYRand())
    , Largeur(GetLargeur())
    , Hauteur(GetHauteur())
{}

Obstacle::~Obstacle()
{}

void Obstacle::Update(long Millis)
{
	//if (PositionX == (-Largeur))
	//	destroy obstacle

	PositionX -= 0.2 * Millis;
}

double Obstacle::GetLargeur()
{
    switch (TypeObstacle)
    {
    case 1:
        Largeur = 50;
        break;
    case 2:
        Largeur = 78;
        break;
    case 3:
        Largeur = 120;
        break;
    case 4:
        Largeur = 90;
        break;
    case 5:
        Largeur = 99;
        break;
    }
	return Largeur;
}

double Obstacle::GetHauteur()
{
    switch (TypeObstacle)
    {
    case 1:
        Hauteur = 50;
        break;
    case 2:
        Hauteur = 88;
        break;
    case 3:
        Hauteur = 109;
        break;
    case 4:
        Hauteur = 95;
        break;
    case 5:
        Hauteur = 99;
        break;
    }
    return Hauteur;
}

int Obstacle::GetType() const
{
	return TypeObstacle;
}

double Obstacle::PosYRand()
{
	PositionY = rand() % SCREEN_HEIGHT - Largeur; // substract height of sprite
	return PositionY;
}



