//------------------------------------------------------------------------------
// main.cpp - Main func for full program.
//------------------------------------------------------------------------------

#include <fstream>
#include <cstdlib> // rand() and srand()
#include <ctime>   // time()
#include <cstring>
#include <stdio.h>
#include "container.h"
#include <iostream>

void errMessage1() {
    printf("incorrect command line!\n"
           "  Waited:\n"
           "     command -f infile outfile01 outfile02\n"
           "  Or:\n"
           "     command -n number outfile01 outfile02\n");
}

void errMessage2() {
    printf("incorrect qualifier value!\n"
           "  Waited:\n"
           "     command -f infile outfile01 outfile02\n"
           "  Or:\n"
           "     command -n number outfile01 outfile02\n");
}

// Program main function.
int main(int argc, char *argv[]) {
    if (argc != 5) {
        errMessage1();
        return 1;
    }

    printf("Start\n");

    Container *c = new Container(10000);
    try {
        if (!strcmp(argv[1], "-f")) {
            std::ifstream stream(argv[2]);
            c->In(stream);
        } else if (!strcmp(argv[1], "-n")) {
            int size = atoi(argv[2]);
            if ((size < 1) || (size > 10000)) {
                printf("incorrect number of objects = %d. Set 0 < number <= 10000\n", size);
                return 3;
            }
            // Random container generation.
            c->InRnd(size);
        } else {
            errMessage2();
            return 2;
        }
    }
    catch (std::exception e) {
        std::cout << e.what();
        return 3;
    }

    // Container output to file.
    std::ofstream outStream1(argv[3]);
    outStream1 << "Filled container:\n";
    c->Out(outStream1);

    // The 2nd part of task.
    std::ofstream outStream2(argv[4]);
    c->CocktailSort();
    outStream2 << "Sorted container:" << "\n";
    c->Out(outStream2);

    printf("Stop\n");
    return 0;
}
