#pragma once

#include "position.hpp"

#include <vector>

namespace logic
{

enum class TileType : int {
    none,
    apple,
    head,
    snake,
};

enum class MoveDirection : int {
    left = 1 << 0,
    right = 1 << 1,
    up = 1 << 2,
    down = 1 << 3,
};

class Game
{
private:
    int size;
    std::vector<Position_t> snake;
    MoveDirection current_direction;
    Position_t apple;

public:
    Game(const int xysize);

public:
    const int GetSize() const;
    const std::vector<Position_t>& GetSnake() const;
    const Position_t& GetApple() const;
    const bool CheckCollisions() const;

public:
    void NextRound();
    void SetDirection(MoveDirection d);
    int Grow(int l = 1);

private:
    void GenerateApple();
};

} // namespace logic
