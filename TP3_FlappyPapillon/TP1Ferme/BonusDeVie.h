#pragma once
#include "Obstacle.h"
class BonusDeVie : public Obstacle
{
public:
	BonusDeVie(double PositionDepartY);
	~BonusDeVie();

	virtual double GetLargeur() override;
	virtual double GetHauteur() override;

protected:
	double Largeur, Hauteur;

};
