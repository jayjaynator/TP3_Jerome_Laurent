#pragma once

#include <SDL.h>
#include <array>
#include <vector>

#include "Papillon.h"
#include "Obstacle.h"
#include "Background.h"
#include "Constants.h"

#include "ToileDAraignee.h"
#include <vector>
#include<iostream>

class Partie
{
public:
    Partie();
    ~Partie();

    void Update(long Millis);
    void Render(SDL_Renderer* Renderer) const;

    void VerifierPartieFinie();

    void AjouterObstacle();
    bool DoitAjouterObstacle();

    void SupressionObstacle();
    bool ConditionSupressionObstacle();

    double PosRandY(int Type);

private:
    bool PartieFinie;

    Papillon Joueur;
    std::vector <Obstacle*> obstacles;
    
    double TimerObstacle = 0;

    

    //background 
    Background BG1 = Background(0); Background BG2 = Background(SCREEN_WIDTH);
	

};
