#include "position.hpp"

namespace logic
{

int Position_t::operator==(Position_t l)
{
    return (l.x == this->x && l.y == this->y);
}

} // namespace logic
