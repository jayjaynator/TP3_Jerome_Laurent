#include "Constants.h"

#include "Background.h"

Background::Background()
{
}

Background::Background(double PositionDepartX)
	: PositionX{PositionDepartX}
	, AccelerationActive{false}
{
}

Background::~Background()
{
}

void Background::Update(long Millis)
{
	if (PositionX < (-SCREEN_WIDTH))
		PositionX = SCREEN_WIDTH;
	
		PositionX -= 0.2 * Millis; // 2
}

double Background::GetPositionX() const
{
	return PositionX;
}

void Background::ActiverAcceleration()
{
	AccelerationActive = true;
}

void Background::DesactiverAcceleration()
{
	AccelerationActive = false;
}
