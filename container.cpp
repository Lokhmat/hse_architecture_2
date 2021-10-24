#include "container.h"
#include <fstream>
#include <iostream>


using namespace std;

// Constructor of container.
Container::Container(int s) {
    len = 0;
    size = s;
    storage = new Cipher *[s];
}

// Container destructor.
Container::~Container() {
    Clear();
    delete[] storage;
}

// Clear container and it's memory.
void Container::Clear() {
    for (int i = 0; i < len; i++) {
        delete storage[i];
    }
    len = 0;
}

// Input container from specified stream.
void Container::In(ifstream &ifst) {
    while (!ifst.eof()) {
        if ((storage[len] = Cipher::StaticIn(ifst)) != nullptr) {
            len++;
        } else {
            cout << "Your input file is not in correct format(or empty) check it please\n"
            << "Output could or could not be correct \n"<< "Stopping program... \n";
            return;
        }
    }
}

// Generate container and fill it randomly.
void Container::InRnd(int s) {
    if (s > size) {
        s = size;
    }
    while (len < s) {
        if ((storage[len] = Cipher::StaticInRnd()) != nullptr) {
            len++;
        }
    }
}

// Outputting container into specified stream.
void Container::Out(ofstream &ofst) {
    ofst << "Container contains " << len << " elements.\n";
    for (int i = 0; i < len; i++) {
        ofst << i << ": ";
        storage[i]->Out(ofst);
    }
}

// Cocktail sort implementation for container
void Container::CocktailSort() {
    bool flag = true;
    Cipher *temp;
    int n = len;
    int start = 0, end = n - 1;
    while (flag) {
        flag = false;
        // Scan from left to right as bubble sort.
        for (int i = start; i < end; i++) {
            if (Cipher::getComparable(storage[i]) > Cipher::getComparable(storage[i + 1])) {
                temp = storage[i];
                storage[i] = storage[i + 1];
                storage[i + 1] = temp;
                flag = true;
            }
        }
        if (!flag) {
            // if nothing has changed simply break the loop.
            break;
        }
        flag = false;
        // Decrease the end pointer.
        end--;
        // Scan from right to left as bubble sort again.
        for (int i = end - 1; i >= start; i--) {
            if (Cipher::getComparable(storage[i]) > Cipher::getComparable(storage[i + 1])) {
                temp = storage[i];
                storage[i] = storage[i + 1];
                storage[i + 1] = temp;
                flag = true;
            }
        }
        start++;
    }
}