#pragma once
#include "Obstacle.h"

class ToileDAraignee : public Obstacle
{
public:
	ToileDAraignee();
	~ToileDAraignee();

	virtual void Update(long Millis) override;

protected:
	double AccelerationX;
	double VelocityX;

};
