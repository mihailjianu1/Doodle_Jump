#include "Game_Object.h"
#include <SFML/Graphics.hpp>

using namespace sf;

void Game_Object::draw(RenderWindow* app) {
    sprite->setPosition(pos.x, pos.y);
    app->draw(*sprite);
}
