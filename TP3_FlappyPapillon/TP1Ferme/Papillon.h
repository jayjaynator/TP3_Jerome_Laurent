#pragma once
#include "GameObject.h"
#include "Obstacle.h"

class Papillon : public GameObject
{
public:
	Papillon();
	~Papillon();

	virtual void Update(long Millis) override;

	virtual double GetX() const override;
	virtual double GetY() const override;
	virtual void SetX(double X) override;
	virtual void SetY(double Y) override;

	void Sauter();

	bool DetectionCollision(Obstacle* obstacle);

protected:
	double AccelerationX=0;
	double VelocityY=0;
	double PositionX, PositionY;
	double Largeur, Hauteur;
	int Vies;

};
