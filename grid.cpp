#ifndef GRID_CPP
#define GRID_CPP

#include "grid.h"

#include <sstream>
#include <string>

namespace Cellular {

template <typename CellType>
void Grid<CellType>::SetAt(int i, int j, const CellType &cell)
{
    cells.at(i * w + j) = cell;
}

template <typename CellType>
const CellType &Grid<CellType>::At(int i, int j) const
{
    return cells.at(i * w + j);
}

template <typename CellType>
bool Grid<CellType>::Inside(int i, int j) const
{
    return i >= 0 && i < h && j >= 0 && j < w;
}

template <typename CellType>
std::istream &operator>>(std::istream &in, Grid<CellType> &grid)
{
    std::string line;
    std::getline(in, line);

    std::istringstream iss(line);
    iss >> grid.w >> grid.h;

    for (int i = 0; i < grid.h; ++i) {
        std::getline(in, line);
        for (int j = 0; j < grid.w; ++j) {
            grid.cells.emplace_back(line.at(j));
        }
    }
}

template <typename CellType>
std::ostream &operator<<(std::ostream &o, const Grid<CellType> &grid)
{
    o << grid.w << " " << grid.h << std::endl;
    for (int i = 0; i < grid.h; ++i) {
        for (int j = 0; j < grid.w; ++j) {
            o << char(grid.At(i, j));
        }
        o << std::endl;
    }
}

}

#endif
