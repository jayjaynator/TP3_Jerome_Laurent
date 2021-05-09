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

void Partie::Update(long Millis)
{
    // Si la partie n'est pas encore terminée, on fait avancer l'état
    // du jeu
    if (PartieFinie)
        return;
    

    Joueur.Update(Millis);

    // Mise à jour des obstacles
    //for(auto& Obstacle : obstacles)
    //{
    //    Obstacle.Update(Millis);
    //}
    
    
    
    test.Update(Millis);
    std::cout << test.GetX() << "  " << test.GetY() << std::endl;


    BG1.Update(Millis);
    BG2.Update(Millis);

    VerifierPartieFinie();
}

void Partie::Render(SDL_Renderer* Renderer) const
{
    //render BG1
    Render::DrawSprite(Renderer, Sprite::Background, BG1.GetPositionX(), 0);
    
    //render BG2
    Render::DrawSprite(Renderer, Sprite::Background, BG2.GetPositionX(), 0);

    //render obstacle test
    Render::DrawSprite(Renderer, Sprite::ToileDAraignee, test.GetX(), test.GetY());
    
   /* 
    SDL_SetRenderDrawColor(Renderer, Rouge, Vert, Bleu, 255);
    SDL_RenderClear(Renderer);
  */

    // TODO: Dessin des obstacles 
    // for(auto& Obstacle : obstacles)
    //          switch type dobstacle
    //        Render::DrawSprite(Renderer, Sprite::Oeuf, O.GetPositionX(), O.GetPositionY());
   
    
   
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
