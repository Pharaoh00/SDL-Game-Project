#include "../header/player.h" 

void Player::init(std::string path, int srcX, int srcY, int w, int h,
                  float initX, float initY) {

    BaseSprite::init(path, srcX, srcY, w, h, initX, initY, 0, 255, 0);
}

void Player::update() {

    _x += _xvel;
    _y += _yvel;
    _angle = 0;

    _dstRect.x = round(_x);
    _dstRect.y = round(_y);
    SDL_SetTextureColorMod(_imgTexture, red, green, blue);
}

void Player::keyEvent(SDL_Event event) {

    switch(event.type) {
    case SDL_KEYDOWN:
        switch(event.key.keysym.sym) {
        case SDLK_LEFT:
            _xvel = -p_vel*Game::getTileSize();
            green = 0;
            blue = 255;
            break;
        case SDLK_RIGHT:
            _xvel = p_vel*Game::getTileSize();
            green = 255;
            blue = 0;
            break;
        case SDLK_UP:
            _yvel = -p_vel * Game::getTileSize();
            break;
        case SDLK_DOWN:
            _yvel = p_vel * Game::getTileSize();
            break;
        default:
            break;
        }
        break;

    case SDL_KEYUP:
        switch(event.key.keysym.sym) {
        case SDLK_LEFT:
            _xvel = p_vel * 0;
            break;
        case SDLK_RIGHT:
            _xvel = p_vel * 0;
            break;
        case SDLK_UP:
            _yvel = p_vel * 0;
            break;
        case SDLK_DOWN:
            _yvel = p_vel * 0;
            break;
        default:
            break;
        }
        break;
        
    default:
        break;
    }
}
