#include "Obstacle.h"

Obstacle::Obstacle(double X, double Y, double L, double H)
	:GameObject{X,Y,L,H}
	,PositionX{0}
	,PositionY{0}
{}

Obstacle::~Obstacle()
{

}

void Obstacle::Update(long Millis)
{


}
