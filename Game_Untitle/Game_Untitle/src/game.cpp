#include "../header/game.h"
#include "../header/baseSprite.h"
#include "../header/player.h"
// #include "../header/loadfont.h"
#include "../header/baseFont.h"

SDL_Window* Game::window = nullptr;
SDL_Renderer* Game::renderer = nullptr;
BaseSprite player;
Player myPlayer;
// SDL_Texture* myFont;
// TTF_Font* ttfFont = NULL;
BaseFont myFont;

Game::Game(const char* title, int width, int height, bool fullscreen) {

    int flag = 0;
    if(fullscreen) {
        flag = SDL_WINDOW_FULLSCREEN;
    }

    if(SDL_Init(SDL_INIT_EVERYTHING) == 0) {

        window = SDL_CreateWindow(title,
                                  SDL_WINDOWPOS_CENTERED,
                                  SDL_WINDOWPOS_CENTERED,
                                  width, height,
                                  flag);
        if(window) {
            std::cout << "WINDOW CREATED!" << std::endl;
        }
        
        renderer = SDL_CreateRenderer(window, -1, 0);
        if(renderer) {
            std::cout << "RENDER SUCCESS!" << std::endl;
        }

        running = true;
        TTF_Init();
    }
    else {
        if (window == NULL) {
            std::cout << "WINDOW FAIL!" << std::endl;
            running = false;
        }
    }
}

Game::~Game() {
}
// void printKeyInfo(SDL_KeyboardEvent *key) {

//     if(key->type == SDL_KEYUP) {
//         printf("Realease: - \n" );
//     }
//     else {
//         printf("Press: - \n");
//     }
//     printf("Scancode: 0x%02X\n", key->keysym.scancode);
//     printf( ", Name: %s\n", SDL_GetKeyName(key->keysym.sym));

//     // if(key->type == SDL_KEYDOWN) {

//     //     printf(", Unicode: ");
//     //     if(key->keysym.unicode  < 0x80 && key->keysym.unicode > 0){
//     //         printf("%c (0x%04X)", (char)key->keysym.unicode,
//     //                 key->keysym.unicode );
//     //     }
//     //     else {
//     //         printf( "? (0x%04X)", key->keysym.unicode );
//     //     }
//     // }
// };

void Game::gameInit() {

    // ttfFont = TTF_OpenFont("assets/font/lazy.ttf", 28);
    player.init("assets/imgs/oracle.png", 0, 0, 64, 64, 100, 100);
    myPlayer.init("assets/imgs/hero.png", 0, 0, 12, 15, 200, 200);
    myPlayer.setScl(4);
    // std::cout << SDL_GetWindowSurface(Game::getWindow())->w << std::endl;
    // std::cout << SDL_GetWindowSurface(Game::getWindow())->h << std::endl;

    std::string someText = "Ola SDL!";
    // myFont = LoadFont::load(ttfFont, someText);
    // SDL_RenderCopy(renderer, myFont, NULL, NULL);
    myFont.init("assets/font/8-Bit_Madness.ttf", someText, 300, 300, 112);
    
}
void Game::gameEvent() {

    SDL_Event mainEvent;
    while(SDL_PollEvent(&mainEvent) != 0) {
        switch(mainEvent.type) {
        case SDL_QUIT:
            running = false;
            break;
        default:
            break;
        }
        myPlayer.keyEvent(mainEvent);
    }
}

void Game::gameUpdate() {
    myPlayer.update();
}

void Game::gameRender() {

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    //VERTICAL
    for(int x = 0; x < SCREEN_HEIGHT; x+=TILESIZE) {
        //O ponto final tem q ser o ponto aposto
        //No caso o tamanho da tela vertical
        SDL_RenderDrawLine(renderer, 0, x, SCREEN_WIDTH, x);
    }

    //HORIZONTAL
    for(int y = 0; y < SCREEN_WIDTH; y+=TILESIZE) {
        //O ponto final tem q ser o ponto aposto
        //No caso o tamanho da tela horizontal
        SDL_RenderDrawLine(renderer, y, 0, y, SCREEN_HEIGHT);
    }
    player.draw();
	myPlayer.draw();
    myFont.draw();

    SDL_RenderPresent(renderer);
}

void Game::gameClean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}
