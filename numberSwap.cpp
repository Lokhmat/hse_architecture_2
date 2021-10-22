#include "numberSwap.h"
#include "cipher.h"
#include <fstream>
#include <string>

using namespace std;

// Inputting numberSwap from stream(read only rule and open string).
void NumberSwap::In(ifstream &stream) {
    stream >> decryptedScript;
    char l;
    short r;
    for (int i = 0; i < 26; i++) {
        stream >> l >> r;
        table[l - 97] = r;
    }
    for (int i = 0; i < decryptedScript.length(); i++) {
        encryptedScript[i] = table[decryptedScript[i] - 97];
    }
}


// Generating random numberSwap.
void NumberSwap::InRnd() {
    this->generateRndDecrypted();
    for (int i = 0; i < 26; i++) {
        table[i] = rand() % 1000;
    }
    for (int i = 0; i < decryptedScript.length(); i++) {
        encryptedScript[i] = table[decryptedScript[i] - 97];
    }
}


// Outputting numberSwap to specified stream.
void NumberSwap::Out(ofstream &stream) {
    stream << "PointerSwap: \n" << "Decrypted: " << decryptedScript << "\n" << "Encrypted: ";
    for (int i = 0; encryptedScript[i] != 0; i++) {
        stream << encryptedScript[i] << " ";
    }
    stream << "\n";
    stream << "Table of intersection of symbols\n";
    for (int i = 0; i < 26; i++) {
        stream << (char) (i + 97) << " " << table[i] << "\n";
    }
    stream << "Comparable value: " << Cipher::getComparable(this) << "\n";
}
