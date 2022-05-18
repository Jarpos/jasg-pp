#pragma once

#include "../logic/game.hpp"

#include <SFML/Graphics.hpp>

namespace ui
{

void render_game(sf::RenderWindow& w, const logic::Game& g, int tilesize);

} // namespace ui
