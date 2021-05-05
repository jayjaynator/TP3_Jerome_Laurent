#pragma once

#include <vector>

#include "Rectangle.h"
#include "Bordure.h"
class Game {
public:
    static const int MS_PER_STEP = 30;

    Game();
    ~Game();
    void Loop(SDL_Renderer* Renderer);

    void HandleInput(const SDL_Event& Event);
    void Update(long Millis);
    void Render(SDL_Renderer* Renderer);
    void AjouterFormeAleatoire();
    void DeplacerToutesLesFormes(int DeltaX, int DeltaY);

protected:
    bool KeepPlaying;
    bool Pause;

    std::vector<Rectangle*> Formes;
};
