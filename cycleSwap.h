#ifndef __cycleSwap__
#define __cycleSwap__

#include <string>
#include <fstream>
#include "cipher.h"

using namespace std;

//------------------------------------------------------------------------------
// cycleSwap.h - Implements Caesar cipher(inherited from cipher).
//------------------------------------------------------------------------------
class CycleSwap : public Cipher {
public:
    virtual ~CycleSwap() {}

    // Input cipher from stream.
    virtual void In(ifstream &ifst);

    // Random generating of CycleSwap cipher
    virtual void InRnd();

    // Outputting CycleSwap to stream.
    virtual void Out(ofstream &ofst);


private:
    int n;
    string encryptedScript;
};

#endif // __cycleSwap__