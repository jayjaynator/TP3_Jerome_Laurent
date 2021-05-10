#include "Partie.h"

#include <algorithm>
#include <array>
#include <vector>

#include "Input.h"
#include "Constants.h"
#include "Obstacle.h"
#include "Papillon.h"
#include "Render.h"
#include "Background.h"

//はいはい！

#include "GameObject.h"

#include "FiletAInsectes.h"
#include "ToileDAraignee.h"
#include "RucheDAbeilles.h"

#include "BonusDeVie.h"
#include "PanneauDAcceleration.h"

#include <iostream>

Partie::Partie()
    : PartieFinie(false) {}

Partie::~Partie()
{
    for (auto& obstacle : obstacles)
        delete obstacle;
}

void Partie::Update(long Millis)
{
    // Si la partie n'est pas encore terminée, on fait avancer l'état
    // du jeu
    if (PartieFinie)
        return;
    

    Joueur.Update(Millis);

    // Mise à jour des obstacles
    for(auto& obstacle : obstacles)
    {
        obstacle->Update(Millis);
    }

    BG1.Update(Millis);
    BG2.Update(Millis);

    TimerObstacle += 0.2 * Millis;
    if (DoitAjouterObstacle())
        AjouterObstacle();


    //SupressionObstacleQuiSort();
    //if (ConditionSupressionObstacle())
    SupressionObstacle();

    VerifierPartieFinie();
}

void Partie::Render(SDL_Renderer* Renderer) const
{
    //render BG1
    Render::DrawSprite(Renderer, Sprite::Background, BG1.GetPositionX(), 0);

    //render BG2
    Render::DrawSprite(Renderer, Sprite::Background, BG2.GetPositionX(), 0);


    for (auto& obstacle : obstacles)
    {

        switch (obstacle->GetType())
        {
        case 1:
            Render::DrawSprite(Renderer, Sprite::BonusDeVie, obstacle->GetX(), obstacle->GetY());
            break;

        case 2:
            Render::DrawSprite(Renderer, Sprite::FileAInsecte, obstacle->GetX(), obstacle->GetY());
            break;

        case 3:
            Render::DrawSprite(Renderer, Sprite::PanneauDAcceleration, obstacle->GetX(), obstacle->GetY());
            break;

        case 4:
            Render::DrawSprite(Renderer, Sprite::RucheDAbeilles, obstacle->GetX(), obstacle->GetY());
            break;

        case 5:
            Render::DrawSprite(Renderer, Sprite::ToileDAraignee, obstacle->GetX(), obstacle->GetY());
            break;

        default:
            break;
        }

    }

   
    // Dessin du papillon
    Render::DrawSprite(Renderer, Sprite::Papillon, Joueur.GetX(), Joueur.GetY());

     if(PartieFinie)
        Render::DrawSprite(Renderer, Sprite::GameOver, SCREEN_WIDTH/2 - 300/2, SCREEN_HEIGHT/2 - 120/2);
}

void Partie::VerifierPartieFinie()
{
    if (Joueur.GetVies() == 0)
        PartieFinie = true;
}

void Partie::AjouterObstacle()
{
    int RandType = (rand() % 4) + 1;
    switch (RandType)
    {
    case 1:
        obstacles.push_back(new BonusDeVie);
        break;

    case 2:
        obstacles.push_back(new FiletAInsectes);
        break;

    case 3:
        obstacles.push_back(new PanneauDAcceleration);
        break;

    case 4:
        obstacles.push_back(new RucheDAbeilles);
        break;

    case 5:
        obstacles.push_back(new ToileDAraignee);
        break;

    default:
        break;
    }

    TimerObstacle = 0;
}

bool Partie::DoitAjouterObstacle()
{
    if (TimerObstacle > 480)
        return true;
    else
        return false;
}

void Partie::SupressionObstacle()
{
    //for (int i = 0; i < obstacles.size(); i++)
    //{
    //    if (obstacles[0]->GetX() <= -obstacles[i]->GetLargeur())
    //    {
    //        Obstacle* it = obstacles.at(i);
    //        delete(it);
    //        it = NULL;
    //    }
    //}

    if (obstacles[0]->GetX() <= -obstacles[0]->GetLargeur())
    {
        Obstacle* it = obstacles.at(0);
        delete obstacles.at(0);
        obstacles.erase (obstacles.begin());
    }

}

bool Partie::ConditionSupressionObstacle()
{
    if (obstacles[0]->GetX() <= -obstacles[0]->GetLargeur())
        return true;
    else
        return false;
}
