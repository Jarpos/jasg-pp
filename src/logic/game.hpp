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
    up,
    down,
    left,
    right,
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
    void SetDirection(const MoveDirection&);
    int Grow(int l = 1);

private:
    void GenerateApple();
};

} // namespace logic
