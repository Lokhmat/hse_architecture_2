#ifndef __container__
#define __container__

#include "cipher.h"

//------------------------------------------------------------------------------
// container.h - contains data type,
// describes normal data container
//------------------------------------------------------------------------------
class Container {
public:
    Container(int s);

    ~Container();

    // Input from specified stream.
    void In(ifstream &ifst);

    // Generate container and fill it randomly.
    void InRnd(int size);

    // Print container to a specified stream.
    void Out(ofstream &ofst);

    // Sort container according to the task.
    void CocktailSort();

private:
    void Clear();    // Clear container data.
    int len; // Current length.
    Cipher **storage;
    int size;
};

#endif
