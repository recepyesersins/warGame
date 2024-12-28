#ifndef OYUNCU_H
#define OYUNCU_H

#include "OyunNesnesi.h"

class Oyuncu : public OyunNesnesi {
public:
    Oyuncu(int x, int y) : OyunNesnesi(x, y, '>') {}

    void atesEt() {
        std::cout << "Oyuncu ateş ediyor!" << std::endl;
    }
};

#endif