#include <iostream>
#include "cycleSwap.h"

using namespace std;
// Inputting cycleSwap.
void CycleSwap::In(ifstream &stream) {
    stream >> decryptedScript >> n;
    for (int i = 0; i < decryptedScript.length(); i++) {
        encryptedScript += (((decryptedScript[i] - 97) + n) % 26) + 97;
    }
}


// Creating random cycleSwap.
void CycleSwap::InRnd() {
    this->generateRndDecrypted();
    encryptedScript = "";
    n = rand() % 100;
    for (int i = 0; i < decryptedScript.length(); i++) {
        encryptedScript += (((decryptedScript[i] - 97) + n) % 26) + 97;
    }
}


// Outputting cycleSwap.
void CycleSwap::Out(ofstream& stream) {
    stream << "PointerSwap: \n" << "Decrypted: " << decryptedScript << "\n"
    << "Encrypted: " << encryptedScript << "\n"<< "N = " << n << "\n";
    stream << "Comparable value: " << Cipher::getComparable(this) << "\n";
}
