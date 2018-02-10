#ifndef EVOL_CPP
#define EVOL_CPP

#include "evol.h"

#include <algorithm>
#include <thread>
#include <vector>

namespace Cellular {

template <typename CellType>
void DeterministicEvolution<CellType>::NextGeneration(Grid<CellType> &grid)
{
    Grid<CellType> tmp(grid.W(), grid.H());
    const int n_threads = std::min(unsigned(grid.H()), std::max(std::thread::hardware_concurrency(), 1u));
    const int incr = grid.H() / n_threads;
    std::vector<std::thread> ths;

    for (int t = 0; t < n_threads; ++t) {
        const auto start = t * incr;
        const auto end = std::min(start + incr, grid.H());

        ths.emplace_back([this, start, end, &tmp, &grid]() {
            for (int i = start; i < end; ++i) {
                for (int j = 0; j < grid.W(); ++j) {
                    tmp.SetAt(i, j, NextCell(grid.At(i, j), Neighbours(i, j, grid)));
                }
            }
        });
    }
    std::for_each(std::begin(ths), std::end(ths), [](auto& th) { th.join(); });
    grid.swap(tmp);
}

template <typename CellType>
typename CellType::Array MooreEvolution<CellType>::Neighbours(int i, int j, const Grid<CellType> &grid) const
{
    typename CellType::Array neighs;
    for (auto k : { i - 1, i, i + 1 }) {
        for (auto l : { j - 1, j, j + 1 }) {
            if (k != i || l != j) {
                if (grid.Inside(k, l)) {
                    neighs.push_back(grid.At(k, l));
                }
            }
        }
    }
    return neighs;
}

template <typename CellType>
typename CellType::Array NeumanEvolution<CellType>::Neighbours(int i, int j, const Grid<CellType> &grid) const
{
    typename CellType::Array neighs;
    for (auto k : { i - 1, i + 1 }) {
        if (grid.Inside(k, j)) {
            neighs.push_back(grid.At(k, j));
        }
    }
    for (auto k : { j - 1, j + 1 }) {
        if (grid.Inside(i, k)) {
            neighs.push_back(grid.At(i, k));
        }
    }
    return neighs;
}

}

#endif
