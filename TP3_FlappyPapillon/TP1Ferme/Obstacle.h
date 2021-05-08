#pragma once
#include "GameObject.h"

class Obstacle : public GameObject
{
public:
	Obstacle();
	~Obstacle();

	virtual void Update(long Millis) override;

	virtual double GetLargeur() = 0;
	virtual double GetHauteur() = 0;

	double PosYRand();

protected:

};
