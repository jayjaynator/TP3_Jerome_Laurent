#pragma once
#include "GameObject.h"

class Obstacle : public GameObject
{
public:
	Obstacle();
	~Obstacle();

	virtual void Update(long Millis) override;

	double GetLargeur();
	double GetHauteur();

protected:
	double PositionX, PositionY;

};
