#ifndef CELLULAR_CPP
#define CELLULAR_CPP

#include "cellular.h"
#include "opts.h"

#include <fstream>

namespace Cellular {

template <typename CellType, template <typename> typename EvolutionPolicy>
Automaton<CellType, EvolutionPolicy>::Automaton(const std::string &file, int generations)
    : generations(generations)
{
    std::ifstream(file) >> grid;
}

template <typename CellType, template <typename> typename EvolutionPolicy>
Automaton<CellType, EvolutionPolicy>::~Automaton()
{
    try {
        std::ofstream(Opts::Instance().log_file) << grid;
    } catch (...) {    
    }
}

template <typename CellType, template <typename> typename EvolutionPolicy>
void Automaton<CellType, EvolutionPolicy>::Save(const std::string &file) const
{
    std::ofstream(file) << grid;
}

}

#endif
