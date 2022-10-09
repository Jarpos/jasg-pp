#include "render_birbs.hpp"

#include "../logic/birb.hpp"

#include <SFML/Graphics.hpp>

namespace ui
{

void render_birbs(sf::RenderWindow& w, const std::vector<logic::Birb_c> birbs)
{
    // Draw board
    for (const auto& birb : birbs) {

            sf::RectangleShape r(sf::Vector2f(5, 5));
            r.setPosition(birb.position.x, birb.position.y);
            r.setFillColor(sf::Color(0xFF, 0x00, 0x00));
            w.draw(r);
    }
}

} // namespace ui
