#pragma once
#include "GameObject.h"
#include "BonusDeVie.h"

#include <iostream>

class Obstacle : public GameObject
{
public:
	Obstacle(int Type, double posY);
	~Obstacle();

	virtual void Update(long Millis) override;

	double GetLargeur();
	double GetHauteur();

	int GetType() const;

	double PosYRand();
	

protected:
	int TypeObstacle;
	double PositionY;
	double Hauteur, Largeur;
	/*
	1-bonus de vie
	2-filet a insecte
	3-panneau dacceleration
	4-ruche dabeille
	5-toile daraignee
	*/
};
