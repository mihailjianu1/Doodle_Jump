#ifndef GAME_OBJECT_H_INCLUDED
#define GAME_OBJECT_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "Point.h"

using namespace sf;

class Game_Object {
public:
    int W, H;
    Point pos;
    Sprite* sprite;

    void draw(RenderWindow* app);
};

#endif // GAME_OBJECT_H_INCLUDED
