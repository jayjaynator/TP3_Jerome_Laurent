#pragma once
#include "Obstacle.h"

class RucheDAbeilles : public Obstacle
{
public:
	RucheDAbeilles(double PositionDepartY);
	~RucheDAbeilles();

	virtual void Update(long Millis, bool Acceleration) override;

	virtual double GetLargeur() override;
	virtual double GetHauteur() override;

protected:
	double Largeur, Hauteur;
	bool IsGoingUp = true;

};
