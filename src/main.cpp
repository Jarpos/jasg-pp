#include "config.hpp"
#include "logic/birb.hpp"
#include "ui/render_birbs.hpp"
#include "ui/render_board.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    sf::RenderWindow window(sf::VideoMode(750, 750), "Just Another Snake Game++",
                            sf::Style::None | sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(5);
    window.setKeyRepeatEnabled(false);

    std::vector<logic::Birb_c> birbs(100);
    std::for_each(birbs.begin(), birbs.end(), [](logic::Birb_c& b) {
        b.position = logic::Position_t::GetRandom(750);
    });
    bool pause = false;

    while (window.isOpen()) {
        sf::Event e;
        while (window.pollEvent(e)) {
            if (e.type == sf::Event::Closed)
                window.close();

            if (e.type == sf::Event::KeyPressed) {
                switch (e.key.code) {
                    case sf::Keyboard::Space: /***/ pause = !pause; break;
                    case sf::Keyboard::Escape: /**/ window.close(); break;
                    default: break;
                }
            }
        }

        // Logic
        if (!pause) {
            for (auto& birb : birbs) {
                birb.Move(birbs);
            }
        }

        // Rendering
        window.clear();
        ui::render_board(window);
        ui::render_birbs(window, birbs);
        window.display();
    }
}
