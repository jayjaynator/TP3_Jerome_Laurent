#include <iostream>

#include <SDL.h>

#include "Constants.h"
#include "Forme.h"
#include "Game.h"
#include "Rectangle.h"
#include "Bordure.h"

using namespace std;

Game::Game()
    : KeepPlaying(true)
    , Pause(false)
{
    for (int i = 0; i < 5; i++) {
        unsigned char R = static_cast<unsigned char>(rand() % 255);
        unsigned char G = static_cast<unsigned char>(rand() % 255);
        unsigned char B = static_cast<unsigned char>(rand() % 255);

        Formes.push_back(new Rectangle{
                static_cast<double>(rand() % (SCREEN_WIDTH - 50)),
                static_cast<double>(rand() % (SCREEN_HEIGHT - 50)),
                50, 50,
                R, G, B });
    }
}

Game::~Game()
{
    cout << "Destructeur de Game appelé" << endl;

    for (auto& F : Formes)
    {
        delete F;
    }
}

/**
 * Main game Loop
 *
 * See
 * http://gameprogrammingpatterns.com/game-loop.html
 * https://gafferongames.com/post/fix_your_timestep/
 */
void Game::Loop(SDL_Renderer* Renderer)
{
    SDL_Event Event;

    long LastFrameTime = SDL_GetTicks() - MS_PER_STEP;
    long TimeAccumulator = 0;

    while (KeepPlaying) {

        long FrameTime = SDL_GetTicks();
        long Dt = FrameTime - LastFrameTime;

        // Clamp dt to avoid the spiral of death when the game lags
        if (Dt > 100) Dt = 100;

        TimeAccumulator += Dt;

        // -- Events --
        while (SDL_PollEvent(&Event)) {
            HandleInput(Event);
        }

        // -- Update --
        while (TimeAccumulator >= MS_PER_STEP) {

            Update(MS_PER_STEP);

            TimeAccumulator -= MS_PER_STEP;
        }

        // Update(TimeAccumulator);

        TimeAccumulator = 0;

        Render(Renderer);

        int Wait = FrameTime + MS_PER_STEP - SDL_GetTicks();

        if (Wait < 0) {
            cout << "WARNING: lag of " << -Wait << "ms" << endl;
        }
        else {
            SDL_Delay(Wait);
        }

        LastFrameTime = FrameTime;
    }
}

void Game::HandleInput(const SDL_Event& Event)
{
    switch (Event.type) {
        // Si on relâche une touche
    case SDL_KEYUP:
        switch (Event.key.keysym.sym) {
        case SDLK_LEFT:
            break;
        case SDLK_RIGHT:
            break;
        case SDLK_DOWN:
            break;
        case SDLK_UP:
            break;
        case SDLK_SPACE:
            break;
        }
        break;

        // Si on presse une touche
    case SDL_KEYDOWN:
        switch (Event.key.keysym.sym) {
        case SDLK_LEFT:
            DeplacerToutesLesFormes(-10, 0);
            break;
        case SDLK_RIGHT:
            DeplacerToutesLesFormes(+10, 0);
            break;
        case SDLK_DOWN:
            DeplacerToutesLesFormes(0, +10);
            break;
        case SDLK_UP:
            DeplacerToutesLesFormes(0, -10);
            break;
        case SDLK_SPACE:
            for (auto& F : Formes)
                F->Sauter();

            break;

        case SDLK_p: // Pause
            Pause = !Pause;
            break;

        case SDLK_ESCAPE:
            KeepPlaying = false;
            break;
        }
    }
}

void Game::AjouterFormeAleatoire()
{
    // Rajoute une nouvelle forme au hasard
    unsigned char R = rand() % 255;
    unsigned char G = rand() % 255;
    unsigned char B = rand() % 255;

    int Largeur = 50;
    int Hauteur = 50;
    double PosX = static_cast<double>(rand() % (SCREEN_WIDTH - Largeur));
    double PosY = static_cast<double>(rand() % (SCREEN_HEIGHT - Hauteur));

    int Choix = rand() % 2;

    if (Choix == 0)
        Formes.push_back(new Rectangle{ PosX, PosY, Largeur, Hauteur, R, G, B });
    else if (Choix == 1)
        Formes.push_back(new Bordure{ PosX, PosY, Largeur, Hauteur, R, G, B });
    // else {
    //     int X2 = rand() % (SCREEN_WIDTH - Largeur);
    //     int Y2 = rand() % (SCREEN_HEIGHT - Hauteur);
    //     int X3 = rand() % (SCREEN_WIDTH - Largeur);
    //     int Y3 = rand() % (SCREEN_HEIGHT - Hauteur);
    //     Formes.push_back(new Triangle{PosX, PosY, X2, Y2, X3, Y3, R, G, B});
}

void Game::DeplacerToutesLesFormes(int DeltaX, int DeltaY)
{
    for (auto& Forme : Formes)
    {
        Forme->Deplacer(DeltaX, DeltaY);
    }
}

void Game::Update(long Millis)
{
    if (Pause) return;

    // Déplacement
    for (auto& Forme : Formes)
    {
        Forme->Update(Millis);
    }

    // Vérifier les collisions

    // Pour chaque forme
    for (int i = 0; i < Formes.size() - 1; i++)
        // Regarder les autres formes (qui n'ont pas été comparées)
        for (int j = i + 1; j < Formes.size(); j++)
        {
            // Tester la paire de formes i avec j
            Formes[i]->DetectionCollision(Formes[j]);
        }
}

void Game::Render(SDL_Renderer* Renderer)
{
    // -- Clear screen --
    SDL_SetRenderDrawColor(Renderer, 255, 255, 255, 255);
    SDL_RenderClear(Renderer);

    // Dessiner toutes les formes

    for (auto& Forme : Formes)
    {
        Forme->Render(Renderer);
    }

    SDL_RenderPresent(Renderer);
}
