#include "Constants.h"
#include "Papillon.h"


Papillon::Papillon()
	: GameObject{}
	, PositionX{2*SCREEN_WIDTH/5}
	, PositionY{SCREEN_HEIGHT/2}
    , Largeur{60}
    , Hauteur{55}
    , Vies{3}
{}

Papillon::~Papillon()
{
}

void Papillon::Update(long Millis)
{
	double NbSecondes = Millis / 1000.0;

	VelocityY += +AccelerationX * NbSecondes;
}

void Papillon::Sauter()
{
	VelocityY = -100;
}

bool Papillon::DetectionCollision(Obstacle* obstacle)
{
    int Gauche = PositionX;
    int Droite = PositionX + Largeur;
    int Haut = PositionY;
    int Bas = PositionY + Hauteur;

    int GaucheAutre = obstacle->GetX();
    int DroiteAutre = obstacle->GetX() + obstacle->GetLargeur();
    int HautAutre = obstacle->GetY();
    int BasAutre = obstacle->GetY() + obstacle->GetHauteur();

    bool EnCollision =
        !(
            Droite < GaucheAutre ||
            DroiteAutre < Gauche ||
            Bas < HautAutre ||
            BasAutre < Haut
        );

    if (EnCollision)
        return true;
    else
        return false;
}
