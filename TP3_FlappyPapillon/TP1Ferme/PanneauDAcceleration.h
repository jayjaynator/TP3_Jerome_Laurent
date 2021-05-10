#pragma once
#include "Obstacle.h"

class PanneauDAcceleration : public Obstacle
{
public:
	PanneauDAcceleration(double PositionDepartY);
	~PanneauDAcceleration();


	virtual double GetLargeur() override;
	virtual double GetHauteur() override;

protected:
	double Largeur, Hauteur;

};
