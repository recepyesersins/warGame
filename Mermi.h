#ifndef MERMI_H
#define MERMI_H

#include "OyunNesnesi.h"

class Mermi : public OyunNesnesi {
public:
    Mermi(int x, int y) : OyunNesnesi(x, y, '*') {}

    void ileriHareketEt() {
        x++; // Mermi sağa hareket eder
    }
};

#endif