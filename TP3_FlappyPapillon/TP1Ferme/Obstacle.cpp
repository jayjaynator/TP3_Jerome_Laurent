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

}

double Obstacle::PosYRand()
{
	return 0.0;
}

