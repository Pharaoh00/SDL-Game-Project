#pragma once
#include "../header/game.h"
#include "../header/loadfont.h"

class BaseFont {

 public:
    BaseFont();
    void init(std::string path, std::string text, float initX, float initY);
    void init(std::string path, std::string text, float initX, float initY,
              int size);
    void draw();
	void setAlpha(Uint8 alpha) { _alpha = alpha; };

 protected:
    float _x;
    float _y;
    double _angle;
    double _tempangle;
    int _scl;

    TTF_Font* _font;
    int _size;
    SDL_Texture* _fontTexture;
    Uint8 _red;
    Uint8 _green;
    Uint8 _blue;
    Uint8 _alpha;
    SDL_Color _textColor;

    SDL_Rect _srcRect;
    SDL_Rect _dstRect;
};
