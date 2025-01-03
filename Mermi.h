// Mermi.h
#ifndef MERMI_H
#define MERMI_H

#include "OyunNesnesi.h"

class Mermi : public OyunNesnesi {
public:
    Mermi(int baslangicX, int baslangicY) : OyunNesnesi(baslangicX, baslangicY) {}

    void guncelle() override {
        x += 2;
    }

    bool ekranDisindaMi() const {
        return x > 33;
    }
};

#endif