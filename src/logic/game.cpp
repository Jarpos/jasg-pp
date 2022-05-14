#include "game.hpp"

#include <algorithm>
#include <time.h>

namespace logic
{

Game::Game(const int xysize) :
    size(xysize), snake({Position_t(xysize / 2, xysize / 2)}),
    current_direction(MoveDirection::up), apple(Position_t::GetRandom(xysize))
{
    this->snake.push_back(this->snake.back());
    this->snake.push_back(this->snake.back());
}

Game::~Game() {}

const int Game::GetSize() const
{
    return this->size;
}

const Position_t& Game::GetApple() const
{
    return this->apple;
}

const std::vector<Position_t>& Game::GetSnake() const
{
    return this->snake;
}

const bool Game::CheckCollisions() const
{
    const Position_t& head = this->snake.front();
    if (head.x < 0 || head.y < 0)
        return true;
    if (head.x > this->size || head.y > this->size)
        return true;

    return std::find(this->snake.begin() + 1, this->snake.end(), this->snake.front()) !=
           this->snake.end();
}

void Game::SetDirection(MoveDirection d)
{
    MoveDirection nd, cd = this->current_direction;
    switch (d) {
        case MoveDirection::up:
            nd = cd == MoveDirection::down ? MoveDirection::down : d;
            break;
        case MoveDirection::down:
            nd = cd == MoveDirection::up ? MoveDirection::up : d;
            break;
        case MoveDirection::left:
            nd = cd == MoveDirection::right ? MoveDirection::right : d;
            break;
        case MoveDirection::right:
            nd = cd == MoveDirection::left ? MoveDirection::left : d;
            break;
    }
    this->current_direction = nd;
}

bool Game::NextRound()
{
    for (int i = this->snake.size() - 1; i > 0; i--) {
        this->snake.at(i) = this->snake.at(i - 1);
    }

    switch (this->current_direction) {
        case MoveDirection::up: /*****/ this->snake.front().y--; break;
        case MoveDirection::down: /***/ this->snake.front().y++; break;
        case MoveDirection::left: /***/ this->snake.front().x--; break;
        case MoveDirection::right: /**/ this->snake.front().x++; break;
    }

    if (this->snake.front() == this->apple) {
        this->snake.push_back(this->snake.back());
        this->GenerateApple();
    }

    return this->CheckCollisions();
}

void Game::GenerateApple()
{
    this->apple = Position_t::GetRandom(this->size);
}

} // namespace logic
