#ifndef __cipher__
#define __cipher__

#include "rnd.h"
#include "string"
using namespace std;


// Cipher class.
class Cipher {
protected:
    static Random rnd20;
    static Random rnd3;
public:
    string decryptedScript;
    virtual ~Cipher() {};
    // Ввод обобщенной фигуры
    static Cipher *StaticIn(ifstream &ifdt);
    // Ввод обобщенной фигуры
    virtual void In(ifstream &ifdt) = 0;
    // Случайный ввод обобщенной фигуры
    static Cipher *StaticInRnd();
    // Виртуальный метод ввода случайной фигуры
    virtual void InRnd() = 0;
    // Вывод обобщенной фигуры
    virtual void Out(ofstream &ofst) = 0;
    // Comparable value of Cipher.
    static double getComparable(Cipher* r);
    // Generate random decrypted string
    void generateRndDecrypted();
    // Count sum of codes in a string
    static int countSum(string line);
};

#endif //__cipher__