#pragma once

#include <ctime>
#include <stdlib.h>

namespace logic
{

struct Position_t {
    int x;
    int y;

    Position_t(int x, int y) : x(x), y(y) {}

    int operator==(Position_t l);

    static Position_t GetRandom(int bounds)
    {
        srand(time(NULL));
        return Position_t(rand() % bounds, rand() % bounds);
    }
};

} // namespace logic
