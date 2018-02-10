#ifndef EVOL_H
#define EVOL_H

#include "grid.h"
#include "cellular.h"

namespace Cellular {

template <typename CellType>
class DeterministicEvolution {
public:
    virtual ~DeterministicEvolution() = default;
    void NextGeneration(Grid<CellType> &grid);
private:
    virtual typename CellType::Array Neighbours(int x, int y, const Grid<CellType> &grid) const = 0;
    virtual CellType NextCell(const CellType &cell, const typename CellType::Array &neighs) const = 0;
};

template <typename CellType>
class MooreEvolution : public DeterministicEvolution<CellType> {
private:
    typename CellType::Array Neighbours(int x, int y, const Grid<CellType> &grid) const override;
    CellType NextCell(const CellType &cell, const typename CellType::Array &neighs) const override;
};

template <typename CellType>
class NeumanEvolution : public DeterministicEvolution<CellType> {
private:
    typename CellType::Array Neighbours(int x, int y, const Grid<CellType> &grid) const override;
    CellType NextCell(const CellType &cell, const typename CellType::Array &neighs) const override;
};

}

#include "evol.cpp"

#endif
