#include "../header/game.h"

Game* game = nullptr;
const int FPS = 60;
const int FRAMEDELAY = 1000 / FPS;
Uint32 frameStart;
int framTime;

int main(int argc, char* argv[]) {

    game = new Game("Untitle", SCREEN_WIDTH, SCREEN_HEIGHT);
    game->gameInit();

    while(game->running) {

        game->gameEvent();
        game->gameUpdate();
        game->gameRender();
    }

    game->gameClean();
    return 0;
}
