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
	double AccelerationY;
	double VelocityY;

	int Vies;

};
