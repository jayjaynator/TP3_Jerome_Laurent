#pragma once
#include "Obstacle.h"

class PanneauDAcceleration : public Obstacle
{
public:
	PanneauDAcceleration();
	~PanneauDAcceleration();

protected:
	double VelocityX;

};
