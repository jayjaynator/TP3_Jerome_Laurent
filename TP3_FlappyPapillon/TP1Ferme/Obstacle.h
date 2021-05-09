#pragma once
#include "GameObject.h"
#include <iostream>

class Obstacle : public GameObject
{
public:
	Obstacle(int Type);
	~Obstacle();

	virtual void Update(long Millis) override;

	virtual double GetLargeur() = 0;
	virtual double GetHauteur() = 0;

	int GetType() const;

	double PosYRand();
	

protected:
	int TypeObstacle;
	/*
	1-bonus de vie
	2-filet a insecte
	3-panneau dacceleration
	4-ruche dabeille
	5-toile daraignee
	*/
};
