#pragma once
#include "../header/baseSprite.h"
#include <math.h>

class Player : virtual public BaseSprite {

 public:
    void init(std::string path, int srcX, int srcY, int w, int h,
              float initX, float initY);
    void update();
    void keyEvent(SDL_Event event);
	void setScl(int scl) { _scl = scl; };

 private:
    float p_vel = 1;
};
