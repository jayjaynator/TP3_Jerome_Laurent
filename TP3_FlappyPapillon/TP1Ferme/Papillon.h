#pragma once
#include "GameObject.h"
#include "Obstacle.h"

class Papillon : public GameObject
{
public:
	Papillon();
	~Papillon();

	virtual void Update(long Millis) override;

	void Sauter();

	bool DetectionCollision(Obstacle* obstacle);

protected:
	double AccelerationX=0;
	double VelocityY=0;
	double PositionX, PositionY;
	double Largeur, Hauteur;
	int Vies;

};
