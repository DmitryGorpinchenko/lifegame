#include "life.h"
#include "opts.h"

#include <iostream>

int main(int argc, char **argv)
{
    Opts::Instance().Reset(argc, argv);
    try {
        Cellular::LifeGame game(Opts::Instance().input_file, Opts::Instance().max_gen);
        game.Run();
        game.Save(Opts::Instance().output_file);
    } catch (...) {
        std::cout << "Something went wrong! May be your input file is invalid!" << std::endl;
    }
    return 0;
}
