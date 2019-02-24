#include "../header/baseSprite.h"

void BaseSprite::init(std::string path,
                      int srcX, int srcY,
                      int w, int h, float initX, float initY) {
    
    _imgTexture = LoadImg::load(path.c_str());

    _srcRect.x = srcX;
    _srcRect.y = srcY;
    _srcRect.w = w;
    _srcRect.h = h;

    _x = initX;
    _y = initY;

    _dstRect.x = _x;
    _dstRect.y = _y;
}

void BaseSprite::init(std::string path,
                      int srcX, int srcY, int w, int h, float initX, float initY,
                      Uint8 r, Uint8 g, Uint8 b) {

    this->red = r;
    this->green = g;
    this->blue = b;
    _imgTexture = LoadImg::load(path.c_str());
    SDL_SetTextureColorMod(_imgTexture, red, green, blue);

    _srcRect.x = srcX;
    _srcRect.y = srcY;
    _srcRect.w = w;
    _srcRect.h = h;

    _x = initX;
    _y = initY;

    _dstRect.x = _x;
    _dstRect.y = _y;
}

void BaseSprite::draw() {

    _dstRect.w = _srcRect.w * _scl;
    _dstRect.h = _srcRect.h * _scl;

    SDL_RenderCopyEx(Game::getRenderer(), _imgTexture, &_srcRect, &_dstRect,
                     _angle, NULL, SDL_FLIP_NONE);
}
