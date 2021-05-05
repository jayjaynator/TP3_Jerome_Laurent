#include "Bordure.h"

#include <iostream>

using namespace std;

Bordure::Bordure(double X, double Y, int Largeur, int Hauteur,
    unsigned char CouleurR, unsigned char CouleurG, unsigned char CouleurB)
    : Rectangle{ X, Y, Largeur, Hauteur, CouleurR, CouleurG, CouleurB }
{}

Bordure::~Bordure()
{
    cout << "On a détruit une bordure!" << endl;
}

/**
 * Affiche la bordure à l'écran
 *
 * @param Renderer Pointer vers un renderer de SDL2
 */
void Bordure::Render(SDL_Renderer* Renderer) const
{
    SDL_SetRenderDrawColor(Renderer, CouleurR, CouleurG, CouleurB, 255);

    int X = CentreX - Largeur / 2;
    int Y = CentreY - Hauteur / 2;

    SDL_RenderDrawLine(Renderer, X, Y, X + Largeur, Y);
    SDL_RenderDrawLine(Renderer, X, Y, X, Y + Hauteur);

    SDL_RenderDrawLine(Renderer, X + Largeur, Y, X + Largeur, Y + Hauteur);
    SDL_RenderDrawLine(Renderer, X, Y + Hauteur, X + Largeur, Y + Hauteur);
}
