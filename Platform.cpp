#include "Platform.h"
#include "Point.h"

#include <SFML/Graphics.hpp>

using namespace sf;

Platform::Platform() {
    this->W = 70;
    this->H = 14;
}

Platform::Platform(Sprite *sprite, int x, int y) {
    this->sprite = sprite;
    this->W = this->sprite->getGlobalBounds().width;
    this->H = this->sprite->getGlobalBounds().height;
    this->pos = Point(x, y);
}
