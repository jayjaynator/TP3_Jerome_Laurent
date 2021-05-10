#pragma once
#include "Obstacle.h"

class FiletAInsectes : public Obstacle
{
public:
	FiletAInsectes();
	~FiletAInsectes();

	virtual void Update(long Millis) override;

protected:
	double VelocityX;

};
