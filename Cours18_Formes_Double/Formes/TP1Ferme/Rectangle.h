#pragma once

#include <SDL.h>

#include "Forme.h"

class Rectangle : public Forme
{
public:
    Rectangle(double X, double Y, int Largeur, int Hauteur,
        unsigned char CouleurR, unsigned char CouleurG, unsigned char CouleurB);

    virtual void Update(long Millis) override;

    void DetectionCollision(Rectangle* F);

    virtual void Render(SDL_Renderer* Renderer) const override;

protected:
    int Largeur, Hauteur;
};
