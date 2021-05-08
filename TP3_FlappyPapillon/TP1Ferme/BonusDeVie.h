#pragma once
#include "Obstacle.h"
class BonusDeVie : public Obstacle
{
public:
	BonusDeVie();
	~BonusDeVie();

	virtual void Update(long Millis) override;

protected:
	double AccelerationX;
	double VelocityX;

};
