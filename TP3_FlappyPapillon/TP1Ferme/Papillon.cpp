#include "Constants.h"
#include "Papillon.h"


Papillon::Papillon()
	: GameObject{}
	, PositionX{2*SCREEN_WIDTH/5}
	, PositionY{SCREEN_HEIGHT/2}
    , Largeur{60}
    , Hauteur{55}
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
    //int Droite = PositionX + Largeur;
    //int Gauche = PositionX;
    //int Bas = PositionY + Hauteur;
    //int Haut = PositionY;

    //int GaucheAutre = obstacle->PositionX - obstacle->Largeur;
    //int DroiteAutre = AutreRectangle->CentreX + AutreRectangle->Largeur / 2;
    //int HautAutre = AutreRectangle->CentreY - AutreRectangle->Hauteur / 2;
    //int BasAutre = AutreRectangle->CentreY + AutreRectangle->Hauteur / 2;



    //bool EnCollision = !
    //(
    //    Droite < GaucheAutre ||
    //    DroiteAutre < Gauche ||
    //    Bas < HautAutre ||
    //    BasAutre < Haut
    //);


    //if (EnCollision)
    //    return true;
    //else
        return false;
}
