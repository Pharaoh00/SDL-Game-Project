#include "../header/baseFont.h"

BaseFont::BaseFont() {
    _x = 0;
    _y = 0;
    _angle = 0;
    _tempangle = 0;
    _scl = 1;
    _font = NULL;
    _size = 28;
    _fontTexture = NULL;
    _red = 0;
    _green = 0;
    _blue = 0;
    _alpha = 255;
    _textColor = {_red, _green, _blue};
    _srcRect = {0, 0, 0, 0};
    _dstRect = {0, 0, 0, 0};
}

//init Padrão
//Requer x, y como coordenadas.
void BaseFont::init(std::string path, std::string text,
                    float initX, float initY) {

    _x = initX;
    _y = initY;
    _dstRect.x = _x;
    _dstRect.y = _y;
    _font = TTF_OpenFont(path.c_str(), 28);
    SDL_Surface* tempSurface = TTF_RenderText_Solid(_font, text.c_str(),
                                                    _textColor);
    _srcRect.w = tempSurface->w;
    _srcRect.h = tempSurface->h;
    _fontTexture = SDL_CreateTextureFromSurface(Game::getRenderer(),
                                                tempSurface);
    SDL_FreeSurface(tempSurface);                                                
}

//init requer o tamanho da fonte
void BaseFont::init(std::string path, std::string text,
                    float initX, float initY, int size) {

    _x = initX;
    _y = initY;
    _size = size;
    _dstRect.x = _x;
    _dstRect.y = _y;
    _font = TTF_OpenFont(path.c_str(), _size);
    SDL_Surface* tempSurface = TTF_RenderText_Solid(_font, text.c_str(),
                                                    _textColor);
    _srcRect.w = tempSurface->w;
    _srcRect.h = tempSurface->h;
    _fontTexture = SDL_CreateTextureFromSurface(Game::getRenderer(),
                                                tempSurface);
    SDL_FreeSurface(tempSurface);                                                
}

void BaseFont::draw() {

    _dstRect.w = _srcRect.w * _scl;
    _dstRect.h = _srcRect.h * _scl;

    SDL_SetTextureAlphaMod(_fontTexture, _alpha);
    SDL_RenderCopyEx(Game::getRenderer(), _fontTexture, &_srcRect, &_dstRect,
                     _angle, NULL, SDL_FLIP_NONE);
}
