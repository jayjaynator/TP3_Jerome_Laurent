#include "Partie.h"

#include <algorithm>
#include <array>
#include <vector>

#include "Input.h"
#include "Constants.h"
#include "Obstacle.h"
#include "Papillon.h"

//はいはい！

#include "GameObject.h"

#include "FiletAInsectes.h"
#include "ToileDAraignee.h"
#include "RucheDAbeilles.h"

#include "BonusDeVie.h"
#include "PanneauDAcceleration.h"


Partie::Partie()
    : PartieFinie(false)
{
}

void Partie::Update(long Millis)
{
    // Si la partie n'est pas encore terminée, on fait avancer l'état
    // du jeu
    if (PartieFinie)
        return;
    


    papillon.Update(Millis);

    // Mise à jour des obstacles
    for(auto& Obstacle : obstacles)
    {
        Obstacle.Update(Millis);
    }

    VerifierPartieFinie();
}

void Partie::Render(SDL_Renderer* Renderer) const
{
   /* 
    SDL_SetRenderDrawColor(Renderer, Rouge, Vert, Bleu, 255);
    SDL_RenderClear(Renderer);
  */

    // TODO: Dessin des obstacles 
   // for(auto& O : Oeufs)
   //     if(O.EstVisible())
    //        Render::DrawSprite(Renderer, Sprite::Oeuf, O.GetPositionX(), O.GetPositionY());

   
    // Dessin du papillon
    Render::DrawSprite(Renderer, Joueur.LooksLeft() ? Sprite::GnomeLeft : Sprite::GnomeRight, Joueur.GetPositionX(), Joueur.GetPositionY());

   // if(PartieFinie)
    //    Render::DrawSprite(Renderer, Sprite::GameOver, SCREEN_WIDTH/2 - 300/2, SCREEN_HEIGHT/2 - 120/2);
}

void Partie::VerifierPartieFinie()
{
    //if papillon vies == 0, set partiefine = true
}
