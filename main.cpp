#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>

#include "Point.h"
#include "Player.h"
#include "Platform.h"
#include "Window.h"

using namespace sf;

int main() {
    srand(time(NULL));

    MWindow window;
    RenderWindow app(VideoMode(window.W, window.H), "Doodle Jump");
    app.setFramerateLimit(60);

    Texture t1, t2, t3;
    t1.loadFromFile("images/background.png");
    t2.loadFromFile("images/platform.png");
    t3.loadFromFile("images/doodle.png");

    Sprite sBackground(t1), sPlat(t2), sPlayer(t3);

    Player player(&sPlayer, 100, 100, 0, 0);

    Platform plat[20];
    for(int i = 0; i < 10; i++)
        plat[i] = Platform(&sPlat, rand() % (window.W - plat[i].W), rand() % (window.H - plat[i].H));

    while(app.isOpen()) {
        Event e;
        while(app.pollEvent(e)) {
            if(e.type == Event::Closed)
                app.close();
        }
        player.apply_input();

        for(int i = 0; i < 10; i ++)
            if(player.collision(&plat[i]))
                break;

        player.apply_physics(&window);

        /// move camera

        if(player.pos.y < window.high) {
            player.pos.y = window.high;
            for(int i = 0; i < 10; i++){
                plat[i].pos.y -= player.vel.y;
                if(plat[i].pos.y > window.H)
                    plat[i] = Platform(&sPlat, rand() % (window.W - plat[i].W), - plat[i].H);
            }
        }

        app.draw(sBackground);

        for(int i = 0; i < 10; i++)
            plat[i].draw(&app);
        player.draw(&app);

        app.display();

        std::cout << player.pos.y << std::endl;
    }
    system("pause");
}
