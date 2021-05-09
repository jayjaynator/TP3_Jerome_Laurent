#include "Constants.h"

#include "Background.h"

Background::Background()
{
}

Background::Background(double PositionDepartX)
	: PositionX{PositionDepartX}
{
}

Background::~Background()
{
}

void Background::Update(long Millis)
{
	if (PositionX == (-SCREEN_WIDTH))
		PositionX = SCREEN_WIDTH;
	
		PositionX -= 0.2 * Millis;
}

double Background::GetPositionX() const
{
	return PositionX;
}
