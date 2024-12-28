#ifndef DUSMAN_H
#define DUSMAN_H

#include "OyunNesnesi.h"

class Dusman : public OyunNesnesi {
public:
    Dusman(int x, int y) : OyunNesnesi(x, y, 'E') {}

    void solaHareketEt() {
        x--; // Düşman sola hareket eder
    }

    bool vurulmaKontrol(int mermiX, int mermiY) const {
        return (x == mermiX && y == mermiY); // Çarpışma kontrolü
    }
};

#endif