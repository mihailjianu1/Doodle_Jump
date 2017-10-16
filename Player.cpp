#include "Player.h"
#include "Point.h"
#include "Window.h"
#include "Rules.h"
#include "Platform.h"

#include <SFML/Graphics.hpp>


using namespace sf;

Player::Player(Sprite *sprite, float x, float y, float dx, float dy) {
    this->left_foot = 20;
    this->right_foot = 50;
    this->force = 10;
    this->sprite = sprite;
    this->W = this->sprite->getGlobalBounds().width;
    this->H = this->sprite->getGlobalBounds().height;
    this->pos = Point(x, y);
    this->vel = Point(dx, dy);
}

void Player::apply_input() {
    vel.x = 0;
    if(Keyboard::isKeyPressed(Keyboard::Right))
        vel.x += 3;
    if(Keyboard::isKeyPressed(Keyboard::Left))
        vel.x -= 3;
}

void Player::apply_physics(MWindow *window) {
    pos.x += vel.x;
    Help::bound(pos.x, 0, window->W - this->W);

    vel.y += Rules::g();
    pos.y += vel.y;
    if(pos.y >= window->H - this->H)
        jump();
}

bool Player::collision(Platform* plat) {
    bool ans = (this->pos.x + right_foot > plat->pos.x) &&
               (this->pos.x + left_foot < plat->pos.x + plat->W) &&
               (this->pos.y + this->H > plat->pos.y) &&
               (this->pos.y + this->H < plat->pos.y + plat->H) &&
               (this->vel.y > 0);
    if(ans)
        jump();
    return ans;
}

void Player::jump() {
    vel.y = -force;
}
