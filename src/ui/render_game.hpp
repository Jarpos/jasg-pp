#pragma once

#include "../logic/board.hpp"

#include <SFML/Graphics.hpp>

namespace ui
{

void render_game(sf::RenderWindow& w, const logic::Game& b, int tilesize)
{
    const auto& tiles = b.getBoard();
    for (int x = 0; x < tiles.size(); x++) {
        for (int y = 0; y < tiles[x].size(); y++) {
            sf::RectangleShape r(sf::Vector2f(tilesize, tilesize));
            r.setPosition(x * tilesize, y * tilesize);
            // r.setOutlineThickness(5);

            switch (tiles[x][y]) {
            case logic::TileType::apple:
                r.setFillColor(sf::Color(0xAA, 0x00, 0x00));
                break;

            case logic::TileType::head:
                r.setFillColor(sf::Color(0x00, 0xDD, 0x00));
                break;

            case logic::TileType::snake:
                r.setFillColor(sf::Color(0x00, 0xAA, 0x00));
                break;

            case logic::TileType::none:
                if ((x + y) % 2)
                    r.setFillColor(sf::Color(0x80, 0x80, 0x80));
                else
                    r.setFillColor(sf::Color(0x2b, 0x2b, 0x2b));

                break;
            }

            w.draw(r);
        }
    }
}

} // namespace ui
