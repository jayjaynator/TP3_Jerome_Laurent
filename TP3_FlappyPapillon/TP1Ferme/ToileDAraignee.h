#pragma once
#include "Obstacle.h"

class ToileDAraignee : public Obstacle
{
public:
	ToileDAraignee(double PositionDepartY);
	~ToileDAraignee();

	virtual double GetLargeur() override;
	virtual double GetHauteur() override;

protected:
	double Largeur, Hauteur;
	

};
