#include "../header/loadimg.h"

SDL_Texture* LoadImg::load(std::string path) {

    SDL_Surface* tempSurface = IMG_Load(path.c_str());
    SDL_Texture* imgTexture = nullptr;
    if(tempSurface == NULL) {
        std::cout << "Unable to load Image: " << path.c_str() << " - Error: "
                  << IMG_GetError() << std::endl;
    }
    else {
        imgTexture = SDL_CreateTextureFromSurface(Game::getRenderer(),
                                                  tempSurface);
        if(imgTexture == NULL) {
            std::cout << "Unable to create texture from: " << path.c_str()
                      << " Error: " << SDL_GetError() << std::endl;
        }
        SDL_FreeSurface(tempSurface);
        return imgTexture;
    }
};
