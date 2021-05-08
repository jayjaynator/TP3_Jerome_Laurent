#include "Constants.h"
#include "Input.h"
#include "Papillon.h"


Papillon::Papillon()
    : GameObject{ 2 * SCREEN_WIDTH / 5, SCREEN_HEIGHT / 2, 60,55}
    , AccelerationY{500}
    , VelocityY{300}
    , Vies{3}
{}
// PositionX{2*SCREEN_WIDTH/5}
// PositionY{SCREEN_HEIGHT/2}
// 
// 

Papillon::~Papillon()
{
}

void Papillon::Update(long Millis)
{
	double NbSecondes = Millis / 1000.0;

	VelocityY += +AccelerationY * NbSecondes;

    PositionY += VelocityY * NbSecondes;


    if (Input::PressedKeys[Input::Space])
        Sauter();

    if (PositionY >= 0)
    {

    }

    if (PositionY <= 400)
    {

    }
}



void Papillon::Sauter()
{
	VelocityY = -300;
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
