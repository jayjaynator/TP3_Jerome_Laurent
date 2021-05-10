#pragma once
#include "Obstacle.h"

class FiletAInsectes : public Obstacle
{
public:
	FiletAInsectes(double PositionDepartY);
	~FiletAInsectes();

	virtual void Update(long Millis) override;

	virtual double GetLargeur() override;
	virtual double GetHauteur() override;

protected:
	double Largeur, Hauteur;
	double TeleportTimer;

};
