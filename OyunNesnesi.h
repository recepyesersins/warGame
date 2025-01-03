// OyunNesnesi.h
#ifndef OYUNNESNESI_H
#define OYUNNESNESI_H

class OyunNesnesi {
protected:
    int x, y;
public:
    OyunNesnesi(int baslangicX, int baslangicY) : x(baslangicX), y(baslangicY) {}
    virtual ~OyunNesnesi() {}
    virtual void guncelle() = 0;
    int alX() const { return x; }
    int alY() const { return y; }
};

#endif