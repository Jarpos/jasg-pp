#include "render_board.hpp"

#include <SFML/Graphics.hpp>

namespace ui
{

void render_board(sf::RenderWindow& w)
{
    // Draw board
    for (int x = 0; x < w.getSize().x; x++) {
        for (int y = 0; y < w.getSize().y; y++) {
            sf::RectangleShape r(sf::Vector2f(5, 5));
            r.setPosition(x, y);
            // r.setFillColor((x + y) % 2 ? sf::Color(0x80, 0x80, 0x80) : sf::Color(0x2b, 0x2b, 0x2b));
            r.setFillColor(sf::Color(0x2b, 0x2b, 0x2b));
            w.draw(r);
        }
    }
}

} // namespace ui
