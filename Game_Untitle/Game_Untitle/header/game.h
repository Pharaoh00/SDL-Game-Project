#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>
#include <string>
#include <string>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

class Game {

 private:
    static SDL_Window* window;
    static SDL_Renderer* renderer;
    SDL_Event mainEvent;
    static const int TILESIZE = 32;

 public:
    Game(const char* title, int width, int height, bool fullscreen = false);
    ~Game();

    bool running;
    static SDL_Window* getWindow() { return window; };
    static SDL_Renderer* getRenderer() { return renderer; };
    static int const getTileSize() { return TILESIZE; };
    //static SDL_Event getEvent() { return mainEvent; };

    void gameInit();
    void gameEvent();
    void gameUpdate();
    void gameRender();
    void gameClean();
    
};
