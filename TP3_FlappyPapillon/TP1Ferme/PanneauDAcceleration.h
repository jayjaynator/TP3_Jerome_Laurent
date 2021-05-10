#pragma once
#include "Obstacle.h"

class PanneauDAcceleration : public Obstacle
{
public:
	PanneauDAcceleration();
	~PanneauDAcceleration();


	virtual double GetLargeur() override;
	virtual double GetHauteur() override;

protected:
	double Largeur, Hauteur;
	double VelocityX;

};
