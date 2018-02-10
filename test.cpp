#include "life.h"
#include "grid.h"

#include <iostream>
#include <fstream>

void test() {
    Cellular::LifeGame game("glider.in", 50);
    game.Run();
    game.Save("glider.out");
    
    Cellular::LifeGrid out_grid;
    Cellular::LifeGrid ref_grid;
    
    std::ifstream("glider.out") >> out_grid;
    std::ifstream("glider.ref") >> ref_grid;
    
    std::cout << (out_grid == ref_grid ? "PASSED" : "FAILED") << std::endl;
}

int main(int argc, char **argv)
{
    test();
    return 0;
}
