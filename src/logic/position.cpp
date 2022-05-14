#include "position.hpp"

namespace logic
{

int Position_t::operator==(const Position_t& l) const
{
    return (l.x == this->x && l.y == this->y);
}

} // namespace logic
