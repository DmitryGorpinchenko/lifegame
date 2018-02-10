#ifndef GRID_H
#define GRID_H

#include <fstream>
#include <vector>

namespace Cellular {

template <typename CellType>
class Grid {
    int w {}, h {};
    typename CellType::Array cells;
public:
    Grid() = default;
    Grid(int w, int h) : w(w), h(h), cells(w * h) {}

    void SetAt(int i, int j, const CellType &cell);
    const CellType &At(int i, int j) const;
    bool Inside(int i, int j) const;
    
    void swap(Grid &other) {
        using std::swap;
        swap(w, other.w);
        swap(h, other.h);
        swap(cells, other.cells);
    }

    int W() const { return w; }
    int H() const { return h; }
    
    template <typename CellT> friend std::istream &operator>>(std::istream &o, Grid<CellT> &grid);
    template <typename CellT> friend std::ostream &operator<<(std::ostream &o, const Grid<CellT> &grid);

    bool operator==(const Grid &rhs) const { return w == rhs.w && h == rhs.h && cells == rhs.cells; }
};

}

#include "grid.cpp"

#endif
