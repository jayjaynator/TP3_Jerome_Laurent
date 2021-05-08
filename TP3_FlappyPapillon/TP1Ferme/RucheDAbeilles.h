#pragma once
#include "Obstacle.h"

class RucheDAbeilles : public Obstacle
{
public:
	RucheDAbeilles();
	~RucheDAbeilles();

	virtual void Update(long Millis) override;

protected:
	double AccelerationX;
	double VelocityX;

};
