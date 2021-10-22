#ifndef __numberSwap__
#define __numberSwap__

#include <fstream>
#include "cipher.h"
using namespace std;
// numberSwap structure.
class NumberSwap: public Cipher {
public:
    virtual ~NumberSwap() {}
    // Inputting numberSwap.
    virtual void In(ifstream &stream);
    // Creating random numberSwap.
    virtual void InRnd();
    // Outputting numberSwap.
    virtual void Out(ofstream &stream);
private:
    short encryptedScript[10000];
    int table[26];
};






#endif // __numberSwap__