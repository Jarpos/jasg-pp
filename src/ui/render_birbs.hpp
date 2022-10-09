#pragma once

#include "../logic/birb.hpp"

#include <SFML/Graphics.hpp>
#include <vector>

namespace ui
{

void render_birbs(sf::RenderWindow& w, const std::vector<logic::Birb_c> birbs);

} // namespace ui
