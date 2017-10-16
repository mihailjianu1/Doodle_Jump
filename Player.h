#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <SFML/Graphics.hpp>

#include "Point.h"
#include "Game_Object.h"
#include "Window.h"
#include "Help.h"
#include "Platform.h"

using namespace sf;

class Player : public Game_Object{
public:
    Point vel;
    float force;
    float left_foot;
    float right_foot;

    Player(Sprite *sprite, float x, float y, float dx, float dy);
    void apply_input();
    void apply_physics(MWindow*);
    bool collision(Platform *plat);
    void jump();
};

#endif // PLAYER_H_INCLUDED
