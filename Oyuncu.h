// Oyuncu.h
#ifndef OYUNCU_H
#define OYUNCU_H

#include "OyunNesnesi.h"

class Oyuncu : public OyunNesnesi {
public:
    Oyuncu(int baslangicX, int baslangicY) : OyunNesnesi(baslangicX, baslangicY) {}

    void yukariHareketEt() {
        if (y > 1) y--;
    }

    void asagiHareketEt() {
        if (y < 18) y++;
    }

    void guncelle() override {
    }
};

#endif
