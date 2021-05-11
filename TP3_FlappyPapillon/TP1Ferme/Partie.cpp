#include "Partie.h"

#include <algorithm>
#include <array>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

#include "Constants.h"
#include "Input.h"
#include "Render.h"

#include "Background.h"
#include "GameObject.h"
#include "Papillon.h"
#include "Obstacle.h"
#include "BonusDeVie.h"
#include "FiletAInsectes.h"
#include "PanneauDAcceleration.h"
#include "RucheDAbeilles.h"
#include "ToileDAraignee.h"


Partie::Partie()
    : PartieFinie(true) {}

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
    {
        return;
    }
    bool Accelere = false;
    Joueur.Update(Millis);

    // Mise à jour des obstacles
    for(auto& obstacle : obstacles)
    {
        obstacle->Update(Millis);
    }


    std::vector<Obstacle*>::iterator obstacle;

    for (obstacle = obstacles.begin(); obstacle != obstacles.end(); )

    //for (auto& obstacle : obstacles)
    {
        if (Joueur.DetectionCollision((*obstacle)))
        {
            int Type = (*obstacle)->GetType();

            {
                switch (Type)
                {
                case 1: // BonusDeVie
                    if (Joueur.GetVies() < 3)
                        Joueur.GagnerUneVie();

                    delete* obstacle;
                    obstacle = obstacles.erase(obstacle);

                    break;

                case 2: // FiletAInsectes
                    if (Joueur.GetInvulnerable() == false)
                    {
                        Joueur.PerdreUneVie();
                        Joueur.DevientInvulnerable2Sec();
                    }
                    break;

                case 3: // PanneauDAcceleration
                  
                    delete* obstacle;
                    obstacle = obstacles.erase(obstacle);

                    Acceleration();
                    break;

                case 4: // RuchesDAbeilles
                    if (Joueur.GetInvulnerable() == false)
                    {
                        Joueur.PerdreUneVie();
                        Joueur.DevientInvulnerable2Sec();
                    }
                    break;

                case 5: // ToilesDAraignee
                    if (Joueur.GetInvulnerable() == false)
                    {
                        Joueur.PerdreUneVie();
                        Joueur.DevientInvulnerable2Sec();
                    }
                    break;
                }
            }
        }

        if (obstacle >= obstacles.end())
            break;

        
        ++obstacle;
    }

    TimerFlashPapillon += Millis;

    if (TimerFlashPapillon > 500)
        TimerFlashPapillon = 0;
    

    BG1.Update(Millis);
    BG2.Update(Millis);

    TimerObstacle += 0.2 * Millis;
    if (DoitAjouterObstacle())
        AjouterObstacle();

    SupressionObstacle();

    if (Input::PressedKeys[Input::S])
    {
        Save();
    }

    if (Input::PressedKeys[Input::L])
    {
        Load();
    }

    VerifierPartieFinie();
}

void Partie::Render(SDL_Renderer* Renderer) const
{
    //render BG1
    Render::DrawSprite(Renderer, Sprite::Background, BG1.GetPositionX(), 0);

    //render BG2
    Render::DrawSprite(Renderer, Sprite::Background, BG2.GetPositionX(), 0);

    if (Input::PressedKeys[Input::D])
    {
        SDL_SetRenderDrawColor(Renderer, 255, 255, 0, 255);
        
        // Dessin du joueur
        SDL_Rect Rect{ Joueur.GetX(), Joueur.GetY(),Joueur.GetLargeur(), Joueur.GetHauteur() };
        SDL_RenderFillRect(Renderer, &Rect);

        for (auto& obstacle : obstacles)
        {
              // Dessin des obstacles
            SDL_Rect Rect{ obstacle->GetX(), obstacle->GetY(),obstacle->GetLargeur(), obstacle->GetHauteur() };
            SDL_RenderFillRect(Renderer, &Rect);
        }
    }


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

    if (Joueur.GetInvulnerable())
    {
       
        if (TimerFlashPapillon < 250)
        {
            Render::DrawSprite(Renderer, Sprite::Papillon, Joueur.GetX(), Joueur.GetY());
            

        }
    }
    else
        Render::DrawSprite(Renderer, Sprite::Papillon, Joueur.GetX(), Joueur.GetY());
    


    // Dessin des coeurs
    if (Joueur.GetVies() > 0)
        Render::DrawSprite(Renderer, Sprite::Coeur, 10,10);

    if (Joueur.GetVies() > 1)
        Render::DrawSprite(Renderer, Sprite::Coeur, 42,10);

    if (Joueur.GetVies() > 2)
        Render::DrawSprite(Renderer, Sprite::Coeur, 74,10);
    



    if (PartieFinie)
    {
        Render::DrawSprite(Renderer, Sprite::GameOver, SCREEN_WIDTH / 2 - 300 / 2, SCREEN_HEIGHT / 2 - 120 / 2);
    }
}

void Partie::VerifierPartieFinie()
{
    if (Joueur.GetVies() == 0)
        PartieFinie = true;
}

void Partie::AjouterObstacle()
{
    int RandType = (rand() % 5) + 1;
    switch (RandType)
    {
    case 1:
        obstacles.push_back(new BonusDeVie(PosRandY(RandType)));
        break;

    case 2:
        obstacles.push_back(new FiletAInsectes(PosRandY(RandType)));
        break;

    case 3:
        obstacles.push_back(new PanneauDAcceleration(PosRandY(RandType)));
        break;

    case 4:
        obstacles.push_back(new RucheDAbeilles(PosRandY(RandType)));
        break;

    case 5:
        obstacles.push_back(new ToileDAraignee(PosRandY(RandType)));
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
    std::vector<Obstacle*>::iterator obstacle;

    for (obstacle = obstacles.begin(); obstacle != obstacles.end(); )
    {
        if ((*obstacle)->GetX() < -((*obstacle)->GetLargeur()))
        {
            delete* obstacle;
            obstacle = obstacles.erase(obstacle);
        }
        else
        {
            ++obstacle;
        }
    }

}

bool Partie::ConditionSupressionObstacle()
{
    if (obstacles[0]->GetX() <= -obstacles[0]->GetLargeur())
        return true;
    else
        return false;
}

double Partie::PosRandY(int Type)
{
    switch (Type)
    {
    case 1:
        return rand() % (SCREEN_HEIGHT-50);
        break;

    case 2:
        return rand() % (SCREEN_HEIGHT-88);
        break;

    case 3:
        return rand() % (SCREEN_HEIGHT-109);
        break;

    case 4:
        return rand() % (SCREEN_HEIGHT-95);
        break;

    case 5:
        return rand() % (SCREEN_HEIGHT-99);
        break;

    default:
        return 0;
        break;
    }
}

void Partie::Acceleration()
{
    GameSpeed += 0.05;

    Joueur.Acceleration();
}

void Partie::Save()
{
    std::cout << "Saved";
}

void Partie::Load()
{
    std::cout << "Loaded";
}
