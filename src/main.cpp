#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML Game",
                            sf::Style::None | sf::Style::Close);
    window.setFramerateLimit(60);
    window.setKeyRepeatEnabled(false);

    while (window.isOpen()) {
        sf::Event e;
        while (window.pollEvent(e)) {
            if (e.type == sf::Event::Closed) window.close();

            if (e.type == sf::Event::KeyPressed) {
                if (e.key.code == sf::Keyboard::Left) {}
                if (e.key.code == sf::Keyboard::Right) {}
            }

            if (e.type == sf::Event::KeyReleased) {
                if (e.key.code == sf::Keyboard::Left) {}
                if (e.key.code == sf::Keyboard::Right) {}
            }
        }

        // Rendering
        window.clear();
        window.display();
    }
}
