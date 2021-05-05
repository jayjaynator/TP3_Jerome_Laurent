#pragma once

#include <SDL.h>

#include "Forme.h"

class Triangle : public Forme
{
public:
	Triangle(int X1, int Y1, int X2, int Y2, int X3, int Y3,
		unsigned char CouleurR, unsigned char CouleurG, unsigned char CouleurB);

	virtual void Render(SDL_Renderer* Renderer) const override;
protected:
	int X1, Y1, X2, Y2, X3, Y3;
};

