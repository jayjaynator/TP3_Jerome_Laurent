#include "Forme.h"

Forme::Forme(double CX, double CY, unsigned char CouleurR, unsigned char CouleurG, unsigned char CouleurB)
    : AccX{ 0 }, AccY{ 50 }
    , VelocityX{ 20 }, VelocityY{ 0 }
    , CentreX{ CX }, CentreY{ CY }
    , CouleurR{ CouleurR }, CouleurG{ CouleurG }, CouleurB{ CouleurB }
{
}

void Forme::Update(long Millis)
{
    double NbSecondesEcoulees = Millis / 1000.0;

    VelocityX += AccX * NbSecondesEcoulees;
    VelocityY += AccY * NbSecondesEcoulees;

    CentreX += VelocityX * NbSecondesEcoulees;
    CentreY += VelocityY * NbSecondesEcoulees;
}

void Forme::Deplacer(double DeltaX, double DeltaY)
{
    CentreX += DeltaX;
    CentreY += DeltaY;
}


void Forme::Sauter()
{
    VelocityY = -100;
}
