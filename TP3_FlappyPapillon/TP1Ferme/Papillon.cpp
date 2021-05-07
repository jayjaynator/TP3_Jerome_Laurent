#include "Constants.h"
#include "Papillon.h"

// Changement 

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
    double Gauche = PositionX;
    double Droite = PositionX + Largeur;
    double Haut = PositionY;
    double Bas = PositionY + Hauteur;

    double GaucheAutre = obstacle->GetX();
    double DroiteAutre = obstacle->GetX() + obstacle->GetLargeur();
    double HautAutre = obstacle->GetY();
    double BasAutre = obstacle->GetY() + obstacle->GetHauteur();

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
