#include "Constants.h"
#include "Input.h"
#include "Papillon.h"

#include <iostream>
using namespace std;

Papillon::Papillon()
    : GameObject{ 2*SCREEN_WIDTH/5, SCREEN_HEIGHT/2}
    , Largeur{60}
    , Hauteur{55}
    , AccelerationY{500}
    , VelocityY{0}
    , Vies{3}
    , Invulnerable{false}
{}

Papillon::~Papillon()
{}


void Papillon::Update(long Millis)
{
	NbSecondes = Millis / 1000.0;


    if (VelocityPlusGrandA299())
        ;
    else
        GraviteAffecteVelocite();


    PositionY += VelocityY * NbSecondes;

    //cout << "AccelerationY = " << AccelerationY << ", VelocityY = " << VelocityY << endl;


    if (Input::PressedKeys[Input::Space])
        Sauter();

    if (SortieHaut() || SortieBas())
        Rebondir();




    //if (Invulnerable)
    //{
    //    if (NbSecInv <= 0)
    //    {
    //        Invulnerable = false;
    //        NbSecInv = 3;
    //    }

    //    if (NbSecInv > 0)
    //    {
    //        NbSecInv = -NbSecondes;
    //    }
    //}

}

double Papillon::GetLargeur() const
{
    return Largeur;
}
double Papillon::GetHauteur() const
{
    return Hauteur;
}
void Papillon::GraviteAffecteVelocite()
{
    if (AccelerationActive)
        VelocityY += +AccelerationY * NbSecondes + 30;
    else
        VelocityY += +AccelerationY * NbSecondes;
}
void Papillon::Sauter()
{
	VelocityY = -300;
}
void Papillon::Rebondir()
{
    if (SortieHaut())
        VelocityY = 300;
    if (SortieBas())
        VelocityY = -300;
}
void Papillon::PerdreUneVie()
{
    Vies = Vies - 1;
}

bool Papillon::VelocityPlusGrandA299()
{
    if (VelocityY > 299)
        return true;
    else
        return false;
}
bool Papillon::SortieHaut()
{
    if (PositionY <= 0)
        return true;
    else
        return false;
}
bool Papillon::SortieBas()
{
    if (PositionY >= 400-Hauteur)
        return true;
    else
        return false;
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
int Papillon::GetVies() const
{
    return Vies;
}
