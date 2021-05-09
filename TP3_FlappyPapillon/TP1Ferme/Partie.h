#pragma once

#include <SDL.h>
#include <array>
#include <vector>

#include "Papillon.h"
#include "Obstacle.h"
#include "Background.h"
#include "Constants.h"


class Partie
{
public:
    Partie();

    void Update(long Millis);
    void Render(SDL_Renderer* Renderer) const;

    void VerifierPartieFinie();

private:
    bool PartieFinie;

    Papillon Joueur;
    //std::array<Obstacle, 5> obstacles;
    
//background peut etre
    Background BG1 = Background(0); Background BG2 = Background(SCREEN_WIDTH);
	
   

};
