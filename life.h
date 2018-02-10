#ifndef LIFE_H
#define LIFE_H

#include "evol.h"
#include "grid.h"
#include "cellular.h"

namespace Cellular {

struct LifeCell {
    enum class State : int {
        ALIVE,
        DEAD
    };
    State state;

    using Array = std::vector<LifeCell>;
    LifeCell(State state = State::DEAD) : state(state) {}

    explicit LifeCell(char c);
    explicit operator char() const;

    bool operator==(const LifeCell &rhs) const { return state == rhs.state; }
};

using LifeGame = Automaton<LifeCell, MooreEvolution>;
using LifeGrid = Grid<LifeCell>;

}

#endif
