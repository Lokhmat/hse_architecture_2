#ifndef __cycleSwap__
#define __cycleSwap__

#include <string>
#include <fstream>
#include "cipher.h"

using namespace std;

// cycleSwap structure.
class CycleSwap: public Cipher {
public:
    virtual ~CycleSwap() {}
    // Ввод параметров прямоугольника из файла
    virtual void In(ifstream &ifst);
    // Случайный ввод параметров прямоугольника
    virtual void InRnd();
    // Вывод параметров прямоугольника в форматируемый поток
    virtual void Out(ofstream &ofst);


private:
    int n;
    string encryptedScript;
};

#endif // __cycleSwap__