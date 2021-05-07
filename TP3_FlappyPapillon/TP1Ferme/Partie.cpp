#include "Partie.h"

#include <algorithm>
#include <array>
#include <vector>

#include "Input.h"
#include "Constants.h"
#include "Obstacle.h"
#include "Papillon.h"
#include "Render.h"

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
    


    Joueur.Update(Millis);

    // Mise à jour des obstacles
    for(auto& Obstacle : obstacles)
    {
        Obstacle.Update(Millis);
    }

    //methode qui efface hors decran

    /*
    if efface? 
            
            obstacles.makenewobs();
    */



    VerifierPartieFinie();
}

void Partie::Render(SDL_Renderer* Renderer) const
{
    Render::DrawSprite(Renderer, Sprite::Background, 0, 0);
  
    // TODO: Dessin des obstacles 
    for (auto& Obstacle : obstacles)
    {
        
    }
        //Render::DrawSprite(Renderer, Sprite::, O.GetPositionX(), O.GetPositionY());
   
    // Dessin du papillon
    Render::DrawSprite(Renderer, Sprite::Papillon, Joueur.GetX(), Joueur.GetY());

     if(PartieFinie)
        Render::DrawSprite(Renderer, Sprite::GameOver, SCREEN_WIDTH/2 - 300/2, SCREEN_HEIGHT/2 - 120/2);
}

void Partie::VerifierPartieFinie()
{
    //if papillon vies == 0, set partiefine = true
}
