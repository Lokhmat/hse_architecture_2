#ifndef __pointerSwap__
#define __pointerSwap__


#include <fstream>
#include "cipher.h"
using namespace std;
// pointerSwap structure.
class PointerSwap: public Cipher {
public:
    virtual ~PointerSwap() {}
    // Inputting pointerSwap.
    virtual void In(ifstream &stream);
    // Creating pointerSwap.
    virtual void InRnd();
    // Outputting random pointerSwap.
    virtual void Out(ofstream &stream);
private:
    string encryptedScrypt;
    std::pair<char, char> table[26];
};





#endif // __pointerSwap__