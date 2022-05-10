#include "config.hpp"
#include "logic/board.hpp"
#include "ui/render_game.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

int main()
{
    sf::RenderWindow window(sf::VideoMode(750, 750), "Just Another Snake Game++",
                            sf::Style::None | sf::Style::Close);
    window.setFramerateLimit(2);
    window.setKeyRepeatEnabled(false);
    logic::Game game(config::TILES_X);

    while (window.isOpen()) {
        sf::Event e;
        int direction = 0;
        while (window.pollEvent(e)) {
            if (e.type == sf::Event::Closed) window.close();

            if (e.type == sf::Event::KeyPressed) {
                if (e.key.code == sf::Keyboard::Left) {
                    direction |= (int)logic::MoveDirection::left;
                    game.SetDirection(logic::MoveDirection::left);
                }
                if (e.key.code == sf::Keyboard::Right) {
                    direction |= (int)logic::MoveDirection::right;
                    game.SetDirection(logic::MoveDirection::right);
                }
                if (e.key.code == sf::Keyboard::Up) {
                    direction |= (int)logic::MoveDirection::up;
                    game.SetDirection(logic::MoveDirection::up);
                }
                if (e.key.code == sf::Keyboard::Down) {
                    direction |= (int)logic::MoveDirection::down;
                    game.SetDirection(logic::MoveDirection::down);

                }
            }
        }

        // Logic
        game.DoMove();

        // Rendering
        window.clear();
        ui::render_game(window, game, window.getSize().x / config::TILES_X);
        window.display();
    }
}
