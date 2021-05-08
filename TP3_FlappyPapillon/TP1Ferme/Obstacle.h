#pragma once
#include "GameObject.h"

class Obstacle : public GameObject
{
public:
	Obstacle();
	~Obstacle();

	virtual void Update(long Millis) override;

	double GetLargeur() const;
	double GetHauteur() const;

	double PosYRand();

protected:

};
