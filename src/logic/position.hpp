#pragma once

#include <ctime>
#include <stdlib.h>

namespace logic
{

struct Position_t {
    int x;
    int y;

    Position_t(int x, int y) : x(x), y(y) {}

    int operator==(const Position_t& l) const;

    static Position_t GetRandom(int bounds)
    {
        static bool ran = false;
        if (!ran) {
            srand(time(NULL));
            ran = true;
        }
        return Position_t(rand() % bounds, rand() % bounds);
    }
};

} // namespace logic
