#include "Constants.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Obstacle.h"

Obstacle::Obstacle()
	:GameObject{ 641, PosYRand()}
{}

Obstacle::~Obstacle()
{}

void Obstacle::Update(long Millis)
{


}

double Obstacle::GetLargeur() const
{
	return 0.0;
}

double Obstacle::GetHauteur() const
{
	return 0.0;
}

double Obstacle::PosYRand()
{
	return 0.0;
}

