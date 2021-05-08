#pragma once
#include "Obstacle.h"

class RucheDAbeilles : public Obstacle
{
public:
	RucheDAbeilles();
	~RucheDAbeilles();

	virtual void Update(long Millis) override;

	virtual double GetLargeur() override;
	virtual double GetHauteur() override;

protected:
	double Largeur, Hauteur;
	double VelocityX;

};
