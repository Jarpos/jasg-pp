#include "config.hpp"
#include "logic/game.hpp"
#include "ui/render_game.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

int main()
{
    sf::RenderWindow window(sf::VideoMode(750, 750), "Just Another Snake Game++",
                            sf::Style::None | sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(5);
    window.setKeyRepeatEnabled(false);

    bool pause = false;
    logic::Game game(config::TILES_X);
    logic::MoveDirection mdir = logic::MoveDirection::up;

    while (window.isOpen()) {
        sf::Event e;
        while (window.pollEvent(e)) {
            if (e.type == sf::Event::Closed)
                window.close();

            if (e.type == sf::Event::KeyPressed) {
                switch (e.key.code) {
                    case sf::Keyboard::Left: /***/ mdir = logic::MoveDirection::left; break;
                    case sf::Keyboard::Right: /**/ mdir = logic::MoveDirection::right; break;
                    case sf::Keyboard::Up: /*****/ mdir = logic::MoveDirection::up; break;
                    case sf::Keyboard::Down: /***/ mdir = logic::MoveDirection::down; break;

                    case sf::Keyboard::Escape: window.close(); break;
                    case sf::Keyboard::Space: pause = !pause; break;
                    default: break;
                }
            }
        }

        // Logic
        if (!pause) {
            game.SetDirection(mdir);
            if (game.CheckCollisions()) {
                std::cout << "Lost\n";
                mdir = logic::MoveDirection::up;
                game = logic::Game(config::TILES_X);
            }
            game.NextRound();
        }

        // Rendering
        window.clear();
        ui::render_game(window, game, window.getSize().x / config::TILES_X);
        window.display();
    }
}
