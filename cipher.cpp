#include <cstdlib>
#include <fstream>
#include <set>
#include <iostream>
// Inputting cipher.
#include "numberSwap.h"
#include "cycleSwap.h"
#include "pointerSwap.h"
//------------------------------------------------------------------------------
Random Cipher::rnd20(1, 20);
Random Cipher::rnd3(1,3);

//------------------------------------------------------------------------------
// Ввод параметров обобщенного шифра из файла
Cipher* Cipher::StaticIn(ifstream &ifst) {
    int k = 0;
    ifst >> k;
    Cipher *sp = nullptr;
    switch(k) {
        case 1:
            sp = new CycleSwap;
            break;
        case 2:
            sp = new NumberSwap;
            break;
        case 3:
            sp = new PointerSwap;
            break;
        default:
            return sp;
    }
    sp->In(ifst);
    return sp;
}

// Случайный ввод обобщенной фигуры
Cipher *Cipher::StaticInRnd() {
    auto k = Cipher::rnd3.Get();
    Cipher* sp = nullptr;
    switch(k) {
        case 1:
            sp = new CycleSwap;
            break;
        case 2:
            sp = new NumberSwap;
            break;
        case 3:
            sp = new PointerSwap;
            break;
    }
    sp->InRnd();
    return sp;
}



// Count punctuation signs in char[].
int Cipher::countSum(string line) {
    int count = 0;
    for (int i = 0; i < line.length(); i++) {
        count += line[i];
    }
    return count;
}

// Comparable value of cipher.
double Cipher::getComparable(Cipher* r) {
    int len = r->decryptedScript.length();
    int sum = countSum(r->decryptedScript);
    if (len == 0) {
        return 1;
    }
    return (double)sum / len;

}

void Cipher::generateRndDecrypted() {
    decryptedScript = "";
    for (int i = 0; i < rand() % 10000; i++) {
        decryptedScript += 'a' + rand() % 26;
    }
}