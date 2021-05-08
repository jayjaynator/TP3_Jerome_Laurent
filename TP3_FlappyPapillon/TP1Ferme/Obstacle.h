#pragma once
#include "GameObject.h"

class Obstacle : public GameObject
{
public:
	Obstacle(double X, double Y, double L, double H);
	~Obstacle();

	virtual void Update(long Millis) override;

protected:
	double PositionX, PositionY;

};
