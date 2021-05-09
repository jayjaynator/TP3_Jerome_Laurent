#include "Constants.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Obstacle.h"

Obstacle::Obstacle()
	:GameObject{ SCREEN_WIDTH+1, PosYRand()}
{}

Obstacle::~Obstacle()
{}

void Obstacle::Update(long Millis)
{
	//if (PositionX == (-Largeur))
	//	destroy obstacle

	PositionX -= 0.2 * Millis;
}

double Obstacle::PosYRand()
{
	PositionY = rand() % SCREEN_HEIGHT;
	return PositionY;
}

