#include <cstdlib>
#include <set>
#include "pointerSwap.h"
#include "cipher.h"
#include <iostream>
using namespace std;
// Inputting pointerSwap.
void PointerSwap::In(ifstream &stream) {
    stream >> decryptedScript;
    char l, r;
    for(int i = 0; i < 26; i++){
        stream >> l >> r;/*
        if(l != i+97){
            cout << "Give sorted table of symbols as input";
            throw exception();
        }*/
        table[i].first = i+97;
        table[i].second = r;
    }
    for(int i = 0; i < decryptedScript.length(); i++){
        encryptedScrypt += table[decryptedScript[i]-97].second;
    }
}


// Creating random pointerSwap.
void PointerSwap::InRnd() {
    this->generateRndDecrypted();
    encryptedScrypt = "";
    set<char> alphabet;
    for(int i = 0; i < 26; i++){
        alphabet.insert(i+97);
    }
    for (int i = 0; i < 26; i++) {
        table[i].first = (char)(i+97);
        auto it = begin(alphabet);
        advance(it, rand() % alphabet.size());
        table[i].second = *it;
        alphabet.erase(it);
    }
    for(int i = 0; i < decryptedScript.length(); i++){
        encryptedScrypt += table[decryptedScript[i]-97].second;
    }
}


// Outputting pointerSwap.
void PointerSwap::Out(ofstream &stream) {
    stream << "PointerSwap: \n" << "Decrypted: " << decryptedScript << "\n" << "Encrypted: " << encryptedScrypt << "\n";
    for(int i = 0; i < 26; i++){
        stream << table[i].first << " " << table[i].second << "\n";
    }
    stream << "Comparable value: " << Cipher::getComparable(this) << "\n";
}
