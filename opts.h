#ifndef OPTS_H
#define OPTS_H

#include <unistd.h>

struct Opts {
    std::string input_file;
    std::string output_file;
    std::string log_file;
    int max_gen {};

    static Opts &Instance() { static Opts opts; return opts; }
    
    void Reset(int argc, char **argv) {
        int opt;
        while ((opt = getopt(argc, argv, "i:o:g:l:")) != -1) {
            switch (opt) {
            case 'i': input_file = optarg;         break;
            case 'o': output_file = optarg;        break;
            case 'l': log_file = optarg;           break;
            case 'g': max_gen = std::stoi(optarg); break;
            }
        }
    }
private:
    Opts() = default;
};

#endif
