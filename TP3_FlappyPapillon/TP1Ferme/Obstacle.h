#pragma once
#include "GameObject.h"

class Obstacle : public GameObject
{
public:
	Obstacle();
	~Obstacle();

protected:
	double PositionX, PositionY;

};
