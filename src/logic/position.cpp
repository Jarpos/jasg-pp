#include "position.hpp"

namespace logic
{

int Position_t::operator==(const Position_t& l) const
{
    return (l.x == this->x && l.y == this->y);
}

Position_t Position_t::operator+(const Position_t& l)
{
    this->x += l.x;
    this->y += l.y;
    return *this;
}

Position_t Position_t::operator-(const Position_t& l)
{
    this->x -= l.x;
    this->y -= l.y;
    return *this;
}

} // namespace logic
