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
	if (PositionX <= (-SCREEN_WIDTH))
		PositionX = SCREEN_WIDTH;
	
	PositionX -= GameSpeed * Millis;

	
}

double Background::GetPositionX() const
{
	return PositionX;
}

