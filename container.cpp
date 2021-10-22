#include "container.h"
#include <fstream>

//------------------------------------------------------------------------------
// container_Constr.cpp - содержит функции обработки контейнера
//------------------------------------------------------------------------------

#include "container.h"

//------------------------------------------------------------------------------
// Конструктор контейнера
Container::Container(int s){
    len = 0;
    size = s;
    storage = new Cipher*[s];
}

//------------------------------------------------------------------------------
// Деструктор контейнера
Container::~Container() {
    Clear();
    delete[] storage;
}

//------------------------------------------------------------------------------
// Очистка контейнера от элементов (освобождение памяти)
void Container::Clear() {
    for(int i = 0; i < len; i++) {
        delete storage[i];
    }
    len = 0;
}

//------------------------------------------------------------------------------
// Ввод содержимого контейнера из указанного потока
void Container::In(ifstream &ifst) {
    while(!ifst.eof()) {
        if((storage[len] = Cipher::StaticIn(ifst)) != nullptr) {
            len++;
        }
    }
}

//------------------------------------------------------------------------------
// Случайный ввод содержимого контейнера
void Container::InRnd(int s) {
    if(s > size) {
        s = size;
    }
    while(len < s) {
        if((storage[len] = Cipher::StaticInRnd()) != nullptr) {
            len++;
        }
    }
}

//------------------------------------------------------------------------------
// Вывод содержимого контейнера в указанный поток
void Container::Out(ofstream &ofst) {
    ofst << "Container contains " << len << " elements.\n";
    for(int i = 0; i < len; i++) {
        ofst << i << ": ";
        storage[i]->Out(ofst);
    }
}

// Cocktail sort implementation for container
void Container::CocktailSort(){
    bool flag = true;
    Cipher *temp;
    int n = len;
    int start = 0, end = n-1;
    while(flag){
        flag = false;
        for(int i = start; i<end; i++){ //scan from left to right as bubble sort
            if(Cipher::getComparable(storage[i]) > Cipher::getComparable(storage[i+1])){
                temp = storage[i];
                storage[i] = storage[i+1];
                storage[i+1] = temp;
                flag = true;
            }
        }
        if(!flag){ //if nothing has changed simply break the loop
            break;
        }
        flag = false;
        end--; //decrease the end pointer
        for(int i = end - 1; i >= start; i--){ //scan from right to left
            if(Cipher::getComparable(storage[i]) > Cipher::getComparable(storage[i+1])){
                temp = storage[i];
                storage[i] = storage[i+1];
                storage[i+1] = temp;
                flag = true;
            }
        }
        start++;
    }
}