#pragma once

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
    std::vector<std::vector<TileType>> board;
    MoveDirection current_direction = MoveDirection::up;

public:
    Game(const int xysize);
    ~Game();

public:
    const std::vector<std::vector<TileType>>& getBoard() const;
    void SetDirection(MoveDirection d);
    bool DoMove();

private:
    void GenerateApple();
};

} // namespace logic
