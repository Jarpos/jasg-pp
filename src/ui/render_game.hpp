#pragma once

#include "../logic/game.hpp"

#include <SFML/Graphics.hpp>

namespace ui
{

void render_game(sf::RenderWindow& w, const logic::Game& g, int tilesize)
{
    // Draw board
    for (int x = 0; x < g.GetSize(); x++) {
        for (int y = 0; y < g.GetSize(); y++) {
            sf::RectangleShape r(sf::Vector2f(tilesize, tilesize));
            r.setPosition(x * tilesize, y * tilesize);

            if ((x + y) % 2)
                r.setFillColor(sf::Color(0x80, 0x80, 0x80));
            else
                r.setFillColor(sf::Color(0x2b, 0x2b, 0x2b));
            w.draw(r);
        }
    }

    // Draw snake & apple
    sf::RectangleShape r(sf::Vector2f(tilesize, tilesize));
    r.setFillColor(sf::Color(0xFF, 0x00, 0x00));
    r.setPosition(g.GetApple().x * tilesize, g.GetApple().y * tilesize);
    w.draw(r);

    int i = 0;
    for (const auto& s : g.GetSnake()) {
        sf::RectangleShape r(sf::Vector2f(tilesize, tilesize));
        r.setPosition(s.x * tilesize, s.y * tilesize);

        if (i++ % 2)
            r.setFillColor(sf::Color(0x00, 0xAA, 0x00));
        else
            r.setFillColor(sf::Color(0x00, 0xBB, 0x00));

        w.draw(r);
    }

    sf::RectangleShape head(sf::Vector2f(tilesize, tilesize));
    head.setFillColor(sf::Color(0x00, 0xDD, 0x00));
    head.setPosition(g.GetSnake()[0].x * tilesize, g.GetSnake()[0].y * tilesize);
    w.draw(head);
}

} // namespace ui
