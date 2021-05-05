#pragma once

#include <SDL.h>

class Forme
{
public:
    Forme(double CX, double CY, unsigned char CouleurR, unsigned char CouleurG, unsigned char CouleurB);
    virtual ~Forme() = default;

    virtual void Update(long Millis);

    void Sauter();

    virtual void Render(SDL_Renderer* Renderer) const = 0;
    virtual void Deplacer(double DeltaX, double DeltaY);

protected:
    double AccX, AccY;
    double VelocityX, VelocityY;
    double CentreX, CentreY;
    unsigned char CouleurR, CouleurG, CouleurB;
};
