#ifndef __cipher__
#define __cipher__

#include "rnd.h"
#include "string"

using namespace std;


//------------------------------------------------------------------------------
// cipher.h - Implements abstract cipher as base class for others.
//------------------------------------------------------------------------------
class Cipher {
protected:
    static Random rnd3;
public:
    string decryptedScript;

    virtual ~Cipher() {};

    // Input of abstract cipher.
    static Cipher *StaticIn(ifstream &ifdt);

    // Input of cipher.
    virtual void In(ifstream &ifdt) = 0;

    // Generate random abstract cipher.
    static Cipher *StaticInRnd();

    // Generate random cipher.
    virtual void InRnd() = 0;

    // Output cipher.
    virtual void Out(ofstream &ofst) = 0;

    // Comparable value of Cipher.
    static double getComparable(Cipher *r);

    // Generate random decrypted string.
    void generateRndDecrypted();

    // Count sum of codes in a string.
    static int countSum(string line);
};

#endif //__cipher__