#include "game.hpp"

#include <time.h>

namespace logic
{

Game::Game(const int xysize) :
    board(xysize, std::vector<TileType>(xysize, TileType::none))
{
    board[xysize / 2][xysize / 2] = TileType::head;
    this->GenerateApple();
}

Game::~Game() {}

const std::vector<std::vector<TileType>>& Game::getBoard() const
{
    return this->board;
}

void Game::SetDirection(MoveDirection d)
{
    this->current_direction = d;
}

bool Game::DoMove()
{
    for (int x = 0; x < this->board.size(); x++) {
        for (int y = 0; y < this->board[x].size(); y++) {
            if (this->board[x][y] == TileType::head) {
                this->board[x][y] = TileType::none;

                switch (this->current_direction) {
                    case MoveDirection::left: {
                        this->board[x - 1][y] = TileType::head;
                        break;
                    }
                    case MoveDirection::right: {
                        this->board[x + 1][y] = TileType::head;
                        break;
                    }
                    case MoveDirection::up: {
                        this->board[x][y - 1] = TileType::head;
                        break;
                    }
                    case MoveDirection::down: {
                        this->board[x][y + 1] = TileType::head;
                        break;
                    }
                }
                return true;
            }
        }
    }
    return false;
}

void Game::GenerateApple()
{
    srand(time(NULL));
    int x = rand() % this->board.size();
    int y = rand() % this->board.size();
    if (this->board[x][y] == TileType::none) {
        this->board[x][y] = TileType::apple;
    }
}

} // namespace logic
