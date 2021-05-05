#pragma once

#include "Rectangle.h"

class Bordure : public Rectangle
{
public:
    Bordure(double X, double Y, int Largeur, int Hauteur,
        unsigned char CouleurR, unsigned char CouleurG, unsigned char CouleurB);

    ~Bordure();

    virtual void Render(SDL_Renderer* Renderer) const override;
};
