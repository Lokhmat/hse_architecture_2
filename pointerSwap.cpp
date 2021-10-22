#include <cstdlib>
#include <set>
#include "pointerSwap.h"
#include "cipher.h"
#include <iostream>

using namespace std;

// Inputting pointerSwap from file.
void PointerSwap::In(ifstream &stream) {
    // Here we should read only open string and a rule to encrypt.
    // Decrypted string we could generate on our own.
    stream >> decryptedScript;
    char l, r;
    for (int i = 0; i < 26; i++) {
        stream >> l >> r;
        if (l != i + 97) {
            cout << "Give sorted table of symbols as input";
            return;
        }
        table[i].first = i + 97;
        table[i].second = r;
    }
    for (int i = 0; i < decryptedScript.length(); i++) {
        encryptedScrypt += table[decryptedScript[i] - 97].second;
    }
}


// Generating random pointerSwap.
void PointerSwap::InRnd() {
    this->generateRndDecrypted();
    encryptedScrypt = "";
    set<char> alphabet;
    for (int i = 0; i < 26; i++) {
        alphabet.insert(i + 97);
    }
    for (int i = 0; i < 26; i++) {
        table[i].first = (char) (i + 97);
        auto it = begin(alphabet);
        advance(it, rand() % alphabet.size());
        table[i].second = *it;
        alphabet.erase(it);
    }
    for (int i = 0; i < decryptedScript.length(); i++) {
        encryptedScrypt += table[decryptedScript[i] - 97].second;
    }
}


// Outputting pointerSwap to specified stream.
void PointerSwap::Out(ofstream &stream) {
    stream << "PointerSwap: \n" << "Decrypted: " << decryptedScript << "\n" << "Encrypted: " << encryptedScrypt << "\n";
    for (int i = 0; i < 26; i++) {
        stream << table[i].first << " " << table[i].second << "\n";
    }
    stream << "Comparable value: " << Cipher::getComparable(this) << "\n";
}
