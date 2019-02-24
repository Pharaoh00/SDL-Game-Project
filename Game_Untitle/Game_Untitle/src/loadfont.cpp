#include "../header/loadfont.h"

SDL_Texture* LoadFont::load(TTF_Font* font, std::string text) {

    if(font == NULL) {
        std::cout << "Erro na font!" << std::endl;
    }
    SDL_Texture* fontTexture = NULL;
    SDL_Color textColor = {0, 0, 0};
    SDL_Surface* tempSurface = TTF_RenderText_Solid(font, text.c_str(),
                                                    textColor);
    if(tempSurface == NULL) {
        std::cout << "Erro na surface!" << TTF_GetError() <<std::endl;
    }
    fontTexture = SDL_CreateTextureFromSurface(Game::getRenderer(),
                                               tempSurface);
    SDL_FreeSurface(tempSurface);
    return fontTexture;
}
