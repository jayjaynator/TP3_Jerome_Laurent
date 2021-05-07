#pragma once
#include "GameObject.h"

class Obstacle : public GameObject
{
public:
	Obstacle();
	~Obstacle();

	virtual void Update(long Millis) override;

	virtual double GetX() const override;
	virtual double GetY() const override;
	virtual void SetX(double X) override;
	virtual void SetY(double Y) override;
	virtual double GetLargeur() const override;
	virtual double GetHauteur() const override;

protected:
	double PositionX, PositionY;

};
