#pragma once
#include "GameObject.h"

class Obstacle : public GameObject
{
public:
	Obstacle();
	~Obstacle();

	double GetLargeur();
	double GetHauteur();

protected:
	double PositionX, PositionY;

};
