#pragma once
#include "GameObject.h"
#include "Obstacle.h"

// changement

class Papillon : public GameObject
{
public:
	Papillon();
	~Papillon();

	void Update(long Millis);

	void Sauter();

	bool DetectionCollision(Obstacle* obstacle);

protected:
	double AccelerationX=0;
	double VelocityY=0;
	double PositionX, PositionY;
	double Largeur, Hauteur;
	int Vies;

};
