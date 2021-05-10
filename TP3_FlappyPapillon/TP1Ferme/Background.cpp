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

void Background::Update(long Millis, bool Acceleration)
{
	if (PositionX < (-SCREEN_WIDTH))
		PositionX = SCREEN_WIDTH;
	
	PositionX -= 0.120 * Millis;
	if (Acceleration)
	{
		PositionX -= (0.120 + 0.030) * Millis;
	}
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
