#ifndef __pointerSwap__
#define __pointerSwap__


#include <fstream>
#include "cipher.h"

using namespace std;

//------------------------------------------------------------------------------
// pointerSwap.h - Class implements letter to letter cipher. Inherited from cipher.
//------------------------------------------------------------------------------
class PointerSwap : public Cipher {
public:
    virtual ~PointerSwap() {}

    // Inputting pointerSwap from stream.
    virtual void In(ifstream &stream);

    // Generating random pointerSwap.
    virtual void InRnd();

    // Outputting pointerSwap to stream.
    virtual void Out(ofstream &stream);

private:
    string encryptedScrypt;
    // Pairs of exchanging symbols.
    pair<char, char> table[26];
};


#endif // __pointerSwap__