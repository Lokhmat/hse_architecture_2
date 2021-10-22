#ifndef __container__
#define __container__

//------------------------------------------------------------------------------
// container.h - contains data type,
// describes normal data container
//------------------------------------------------------------------------------

#include "cipher.h"

//------------------------------------------------------------------------------
// ПSimple container with usual array
class Container {
public:
    Container(int s);
    ~Container();

    // Ввод содержимого контейнера из указанного потока
    void In(ifstream &ifst);
    // Случайный ввод содержимого контейнера
    void InRnd(int size);
    // Вывод содержимого контейнера в указанный поток
    void Out(ofstream &ofst);
    // Вычисление суммы периметров всех фигур в контейнере
    void CocktailSort();
private:
    void Clear();    // Очистка контейнера от данных
    int len; // текущая длина
    Cipher** storage;
    int size;
};
#endif
