#ifndef PLATFORM_H_INCLUDED
#define PLATFORM_H_INCLUDED

#include "Game_Object.h"

#include <SFML/Graphics.hpp>

using namespace sf;

class Platform : public Game_Object {
public:
    Platform();
    Platform(Sprite *sprite, int x, int y);
};

#endif // PLATFORM_H_INCLUDED
