#pragma once
#include "Obstacle.h"

class PanneauDAcceleration : public Obstacle
{
public:
	PanneauDAcceleration();
	~PanneauDAcceleration();

	virtual void Update(long Millis) override;

protected:
	double AccelerationX;
	double VelocityX;

};
