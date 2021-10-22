#ifndef __numberSwap__
#define __numberSwap__

#include <fstream>
#include "cipher.h"

using namespace std;

//------------------------------------------------------------------------------
// numberSwap.h - Implements cipher of changing letters to number (inherited from cipher).
//------------------------------------------------------------------------------
class NumberSwap : public Cipher {
public:
    virtual ~NumberSwap() {}

    // Inputting numberSwap from stream.
    virtual void In(ifstream &stream);

    // Generating random numberSwap.
    virtual void InRnd();

    // Outputting numberSwap to stream.
    virtual void Out(ofstream &stream);

private:
    short encryptedScript[10000];
    // Table of exchanging (i's letter of alphabet to i's short)
    short table[26];
};


#endif // __numberSwap__