#ifndef OYUN_NESNESI_H
#define OYUN_NESNESI_H

#include <iostream>
#include <string>

class OyunNesnesi {
protected:
    int x, y; // Nesnenin konumu
    char sembol; // Nesneyi temsil eden sembol
public:
    OyunNesnesi(int x, int y, char sembol) : x(x), y(y), sembol(sembol) {}

    virtual void ciz() const {
        std::cout << sembol;
    }

    virtual void hareketEt(int dx, int dy) {
        x += dx;
        y += dy;
    }

    int konumX() const { return x; }
    int konumY() const { return y; }
    virtual ~OyunNesnesi() = default;
};

#endif