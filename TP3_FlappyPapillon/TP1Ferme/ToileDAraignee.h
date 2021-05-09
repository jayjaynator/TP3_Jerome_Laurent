#pragma once
#include "Obstacle.h"

class ToileDAraignee : public Obstacle
{
public:
	ToileDAraignee();
	~ToileDAraignee();

	//virtual void Update(long Millis) override;

	virtual double GetLargeur() override;
	virtual double GetHauteur() override;

protected:
	double Largeur, Hauteur;
	double VelocityX;

};
