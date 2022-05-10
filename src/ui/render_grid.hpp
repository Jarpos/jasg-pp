#pragma once

#include <SFML/Graphics.hpp>

namespace ui
{

void render_grid(sf::RenderWindow& w, int xycount, int tilesize)
{
    for (int x = 0; x < xycount; x++) {
        for (int y = 0; y < xycount; y++) {
            sf::RectangleShape r(sf::Vector2f(tilesize, tilesize));
            r.setPosition(x * tilesize, y * tilesize);
            if ((x + y) % 2) {
                r.setFillColor(sf::Color(0x80, 0x80, 0x80));
            } else {
                r.setFillColor(sf::Color(0x2b, 0x2b, 0x2b));
            }
            w.draw(r);
        }
    }
}

} // namespace ui
