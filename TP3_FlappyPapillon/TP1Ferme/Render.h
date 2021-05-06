#include <SDL.h>
#include <string>
#include <array>

enum class Sprite
{
    Background,
    GameOver,
    Papillon,
    Coeur,
    FileAInsecte,
    RucheDAbeilles,
    ToileDAraignee,
    BonusDeVie,
    PanneauDAcceleration
};

namespace Render
{
    const int NB_SPRITES = static_cast<int>(Sprite::PanneauDAcceleration) + 1;
    
    const std::array<const char*, NB_SPRITES> Paths = {
        "imgs/bg.bmp",
        "imgs/game-over.bmp",
        "imgs/papillon.bmp",
        "imgs/coeur.bmp",
        "imgs/filet.bmp",
        "imgs/ruche.bmp",
        "imgs/toile.bmp",
        "imgs/bonus-vie.bmp",
        "imgs/acceleration.bmp"
    };

    void LoadImgs(SDL_Renderer* Renderer);
    void FreeImgs();
    SDL_Texture* LoadImg(SDL_Renderer* Renderer, const char* src);
    void DrawTexture(SDL_Renderer* Renderer, SDL_Texture* Texture, int x, int y);

    void DrawSprite(SDL_Renderer* Renderer, Sprite S, double X, double Y);
}
