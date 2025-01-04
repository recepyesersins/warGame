// Oyun.h
#ifndef OYUN_H
#define OYUN_H

#include "Oyuncu.h"
#include "Dusman.h"
#include "Mermi.h"
#include <cstdlib>
#include <conio.h>
#include <windows.h>
#include <ctime>
#include <vector>
#include <iostream>
using namespace std;

// Oyun sınıfı tüm her şeyi yönetir
class Oyun {
private:
    Oyuncu oyuncu;
    Dusman dusman;
    vector<Mermi> mermiler;
    char girdi;
    int atisBekleme;
    const int atisHizi;
    bool oyunDevamEdiyor;

public:
    Oyun() : oyuncu(2, 8), dusman(32, rand() % 16 + 2), atisBekleme(0), atisHizi(10), girdi('\0'), oyunDevamEdiyor(true) {}

void calistir() {
    while (oyunDevamEdiyor) {
        girdiyiIsle();
        guncelle();
        ciz();
        Sleep(75); // Oyun döngüsü gecikmesi
    }
    cout << "Oyun Bitti! Cikmak icin herhangi bir tusa basin." << endl;
    _getch(); // Oyunun bitiş mesajını görmek için bekle
}


private:
    void girdiyiIsle() {
        if (_kbhit()) {
            girdi = _getch();
            switch (girdi) {
                case 'w': oyuncu.yukariHareketEt(); break;
                case 's': oyuncu.asagiHareketEt(); break;
                case ' ': mermiAt(); break;
                case 'q': exit(0);
            }
        }
    }

void mermiAt() {
    mermiler.emplace_back(oyuncu.alX() + 1, oyuncu.alY());
}


    void guncelle() {
    oyuncu.guncelle();
    dusman.guncelle();

    if (dusman.ekranDisindaMi()) {
        dusman = Dusman(32, rand() % 16 + 2); // Dusman yeniden oluştur
    }

    if (dusman.alX() <= 0) {
        oyunDevamEdiyor = false; // Oyun biter
        return;
    }

    for (size_t i = 0; i < mermiler.size();) {
        mermiler[i].guncelle();

        // Mermi düşmanla çarpıştı mı?
        if ((mermiler[i].alX() >= dusman.alX() && mermiler[i].alX() <= dusman.alX() + 1) &&
            (mermiler[i].alY() == dusman.alY())) {
            mermiler.erase(mermiler.begin() + i); // Çarpışan mermiyi sil
            dusman = Dusman(32, rand() % 16 + 2); // Yeni düşman oluştur
        } else if (mermiler[i].ekranDisindaMi()) {
            mermiler.erase(mermiler.begin() + i); // Ekran dışındaki mermiyi kaldır
        } else {
            i++;
        }
    }

    if (atisBekleme > 0) atisBekleme--;
}

    void ciz() {
        system("cls"); // Ekranı temizle
        cout << "Cikmak icin Q, hareket icin W/S, ates etmek için BOSLUK'a basin." << endl;
        for (int y = 0; y < 20; ++y) {
            for (int x = 0; x < 34; ++x) {
                if (x == 0 || x == 33 || y == 0 || y == 19) {
                    cout << "-"; // Çerçeve
                } else if (x == oyuncu.alX() && y == oyuncu.alY()) {
                    cout << ">"; // Oyuncu
                } else if (x == dusman.alX() && y == dusman.alY()) {
                    cout << "<"; // Dusman
                } else {
                    bool mermiVar = false;
                    for (const auto& mermi : mermiler) {
                        if (x == mermi.alX() && y == mermi.alY()) {
                            cout << "o"; // Mermi
                            mermiVar = true;
                            break;
                        }
                    }
                    if (!mermiVar) {
                        cout << " "; // Boşluk
                    }
                }
            }
            cout << endl;
        }

    }
};


#endif