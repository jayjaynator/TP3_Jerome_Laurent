#include "Triangle.h"

Triangle::Triangle(int X1, int Y1, int X2, int Y2, int X3, int Y3,
    unsigned char CouleurR, unsigned char CouleurG, unsigned char CouleurB)
    :Forme{ CouleurR,CouleurG,CouleurB }
    ,X1(X1),Y1(Y1)
    ,X2(X2),Y2(Y2)
    ,X3(X3),Y3(Y3)
{}

void Triangle::Render(SDL_Renderer* Renderer) const
{
    SDL_SetRenderDrawColor(Renderer, CouleurR, CouleurG, CouleurB, 255);

    SDL_RenderDrawLine(Renderer, X1, Y1, X2, Y2);
    SDL_RenderDrawLine(Renderer, X2, Y2, X3, Y3);
    SDL_RenderDrawLine(Renderer, X3, Y3, X1, Y1);
}