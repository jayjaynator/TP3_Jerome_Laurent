#include "Rectangle.h"

#include "Constants.h"


#include <iostream>
using namespace std;

Rectangle::Rectangle(double X, double Y, int Largeur, int Hauteur,
    unsigned char CouleurR, unsigned char CouleurG, unsigned char CouleurB)
    : Forme{ X, Y, CouleurR, CouleurG, CouleurB }
    , Largeur{ Largeur }, Hauteur{ Hauteur }
{}

void Rectangle::Render(SDL_Renderer* Renderer) const
{
    SDL_SetRenderDrawColor(Renderer, CouleurR, CouleurG, CouleurB, 255);

    // Dessin du rectangle
    SDL_Rect Rect{
        static_cast<int>(CentreX - Largeur / 2), static_cast<int>(CentreY - Hauteur / 2),
        Largeur, Hauteur };
    SDL_RenderFillRect(Renderer, &Rect);

}

void Rectangle::Update(long Millis)
{
    Forme::Update(Millis);

    // Forcer le rectangle à rester dans les bornes de l'écran
    if (CentreX - Largeur / 2 < 0)
    {
        VelocityX = -VelocityX;
        CentreX = Largeur / 2;
    }
    else if (CentreX + Largeur / 2 >= SCREEN_WIDTH)
    {
        VelocityX = -VelocityX;
        CentreX = SCREEN_WIDTH - Largeur / 2;
    }

    if (CentreY - Hauteur / 2 < 0)
    {
        VelocityY = -VelocityY;
        CentreY = Hauteur / 2;
    }
    else if (CentreY + Hauteur / 2 >= SCREEN_HEIGHT)
    {
        VelocityY = -VelocityY;
        CentreY = SCREEN_HEIGHT - Hauteur / 2;
    }
}

void Rectangle::DetectionCollision(Rectangle* AutreRectangle)
{
    int Droite = CentreX + Largeur / 2;
    int GaucheAutre = AutreRectangle->CentreX - AutreRectangle->Largeur / 2;

    int DroiteAutre = AutreRectangle->CentreX + AutreRectangle->Largeur / 2;
    int Gauche = CentreX - Largeur / 2;


    int Bas = CentreY + Hauteur / 2;
    int HautAutre = AutreRectangle->CentreY - AutreRectangle->Hauteur / 2;

    int BasAutre = AutreRectangle->CentreY + AutreRectangle->Hauteur / 2;
    int Haut = CentreY - Hauteur / 2;


    bool EnCollision = !(
        Droite < GaucheAutre || DroiteAutre < Gauche
        || Bas < HautAutre || BasAutre < Haut);

    if (EnCollision)
    {
        // Si c'est le cas : mettre en rouge les deux formes
        CouleurR = 255;
        CouleurG = 0;
        CouleurB = 0;
        AutreRectangle->CouleurR = 255;
        AutreRectangle->CouleurG = 0;
        AutreRectangle->CouleurB = 0;
    }
}
