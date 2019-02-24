#pragma once
#include "../header/game.h"

struct LoadFont {

    static SDL_Texture* load(TTF_Font* font, std::string text);
};
