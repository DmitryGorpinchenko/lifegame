#ifndef CELLULAR_H
#define CELLULAR_H

#include "grid.h"

namespace Cellular {

template <typename CellType, template <typename> typename EvolutionPolicy>
class Automaton : private EvolutionPolicy<CellType> {
    using EvolutionPolicy<CellType>::NextGeneration;
    
    Grid<CellType> grid;
    mutable int generations;
public:
    Automaton(const std::string &file, int generations);
    ~Automaton();
    
    void Save(const std::string &file) const;
    void Run() { while (!Terminate()) { NextGeneration(grid); } }
private:
    bool Terminate() const { return generations-- == 0; }
};

}

#include "cellular.cpp"

#endif
