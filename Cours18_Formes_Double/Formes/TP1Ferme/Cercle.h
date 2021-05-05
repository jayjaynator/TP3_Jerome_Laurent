#pragma once

#include <SDL.h>
#include "Forme.h"

class Cercle : public Forme
{
public:
    Cercle(int CentreX, int CentreY, int Rayon, unsigned char R, unsigned char G, unsigned char B);

    virtual void Render(SDL_Renderer* Renderer) const override;

private:
    int CentreX, CentreY;
    int Rayon;
};
