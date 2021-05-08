#pragma once
#include "Obstacle.h"

class PanneauDAcceleration : public Obstacle
{
public:
	PanneauDAcceleration();
	~PanneauDAcceleration();

	virtual void Update(long Millis) override;

	virtual double GetLargeur() override;
	virtual double GetHauteur() override;

protected:
	double Largeur, Hauteur;
	double VelocityX;

};
