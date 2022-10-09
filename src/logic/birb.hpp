#pragma once

#include "position.hpp"

#include <vector>

namespace logic
{

class Birb_c
{
public: // private:
    Position_t position;

public:
    Birb_c() : position(0, 0) {};
    Birb_c(const Position_t& p) : position(p) {};

public:
    Position_t Move(const std::vector<Birb_c>& birbs)
    {
        Position_t closest(100000000, 100000000);
        for (const auto& birb : birbs) {
            if (this->position.Dist(birb.position) < this->position.Dist(closest)) {
                closest = birb.position;
            }
        }
        return closest;
    }
};

} // namespace logic
