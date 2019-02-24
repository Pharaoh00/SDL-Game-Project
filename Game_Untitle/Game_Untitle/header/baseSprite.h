#pragma once
#include "../header/game.h"
#include "../header/loadimg.h"

class BaseSprite {

 public:
    void init(std::string path,
              int srcX, int srcY, int w, int h, float initX, float initY);
    void init(std::string path,
              int srcX, int srcY, int w, int h, float initX, float initY,
              Uint8 r, Uint8 g, Uint8 b);
    void draw();
    void setRed(Uint8 r) { red = r; };
    void setGreen(Uint8 g) { green = g; };
    void setBlue(Uint8 b) { blue = b; };

 protected:
    float _x;
    float _y;
    float _xvel;
    float _yvel;
    double _angle;
    double _tempangle;
    int _scl = 1;

    TTF_Font* _font = NULL;
    SDL_Texture* _imgTexture;
    Uint8 red = 255;
    Uint8 green = 255;
    Uint8 blue = 255;
    
    SDL_Rect _srcRect;
    SDL_Rect _dstRect;
};
