#include "Constants.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Obstacle.h"

Obstacle::Obstacle(int Type, double PositionDepartY)
	:GameObject{ SCREEN_WIDTH+1, PositionDepartY}
	, TypeObstacle(Type)
{}

Obstacle::~Obstacle()
{
	
}

void Obstacle::Update(long Millis, bool Acceleration)
{
	//if (PositionX == (-Largeur))
	//	destroy obstacle

	PositionX -= 0.120 * Millis;
	if (Acceleration)
	{
		PositionX -= (0.120+0.030) * Millis;
	}
}

int Obstacle::GetType() const
{
	return TypeObstacle;
}


