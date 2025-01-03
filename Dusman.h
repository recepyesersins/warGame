// Dusman.h
#ifndef DUSMAN_H
#define DUSMAN_H

#include "OyunNesnesi.h"

class Dusman : public OyunNesnesi {
public:
    Dusman(int baslangicX, int baslangicY) : OyunNesnesi(baslangicX, baslangicY) {}

    void guncelle() override {
        x--;
    }

    bool ekranDisindaMi() const {
        return x < 0;
    }
};

#endif