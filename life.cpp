#include "life.h"

#include <algorithm>

namespace Cellular {

LifeCell::LifeCell(char c)
    : state(c == '+' ? State::ALIVE : State::DEAD)
{}

LifeCell::operator char() const
{
    return state == State::ALIVE ? '+' : '-';
}

template <>
LifeCell MooreEvolution<LifeCell>::NextCell(const LifeCell &cell, const LifeCell::Array &neighs) const
{
    const auto n_alive = std::count_if(std::begin(neighs),
                                       std::end(neighs), [](auto neigh) { return neigh.state == LifeCell::State::ALIVE; });
    if (cell.state == LifeCell::State::ALIVE) {
        if (n_alive < 2 || n_alive > 3) {
            return { LifeCell::State::DEAD };
        }
    } else if (n_alive == 3) {
        return { LifeCell::State::ALIVE };
    }
    return cell;
}

}
