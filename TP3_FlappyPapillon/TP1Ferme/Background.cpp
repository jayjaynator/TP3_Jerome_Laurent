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

void Background::Update(double BGSpeed)
{
	if (PositionX == (-SCREEN_WIDTH))
		PositionX = SCREEN_WIDTH;
	
		PositionX -= BGSpeed;
}

double Background::GetPositionX() const
{
	return PositionX;
}
