#ifndef __rnd__
#define __rnd__

#include <cstdlib>
#include <ctime>   // для функции time()

//------------------------------------------------------------------------------
// rnd.h - Random number generator in specified range.
//------------------------------------------------------------------------------

class Random {
public:
    Random(int f, int l) {
        if(f <= l) {
            first = f;
            last = l;
        } else {
            first = l;
            last = f;
        }
        // System clock as initializer
        srand(static_cast<unsigned int>(time(0)));
    }
    // Generating random number in range first last
    int Get() {
        return rand() % (last - first + 1) + first;
    }
private:
    int first;
    int last;
};

#endif //__rnd__
