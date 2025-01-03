// Oyun.h
#ifndef OYUN_H
#define OYUN_H

#include "Oyuncu.h"
#include "Dusman.h"
#include "Mermi.h"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
#include <ctime>

class Oyun {
private:
    Oyuncu oyuncu;
    Dusman dusman;
    std::vector<Mermi> mermiler;
    char girdi;
    int atisBekleme;
    const int atisHizi;

public:
    Oyun() : oyuncu(2, 8), dusman(32, rand() % 16 + 2), atisBekleme(0), atisHizi(10), girdi('\0') {}

    void calistir() {
        while (true) {
            girdiyiIsle();
            guncelle();
            ciz();
            Sleep(75);
        }
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
        if (atisBekleme == 0) {
            mermiler.emplace_back(oyuncu.alX() + 1, oyuncu.alY());
            atisBekleme = atisHizi;
        }
    }

    void guncelle() {
        oyuncu.guncelle();
        dusman.guncelle();

        if (dusman.ekranDisindaMi()) {
            dusman = Dusman(32, rand() % 16 + 2);
        }

        for (size_t i = 0; i < mermiler.size();) {
            mermiler[i].guncelle();

            if ((mermiler[i].alX() >= dusman.alX() && mermiler[i].alX() <= dusman.alX() + 1) &&
                (mermiler[i].alY() == dusman.alY())) {
                mermiler.erase(mermiler.begin() + i);
                dusman = Dusman(32, rand() % 16 + 2);
            } else if (mermiler[i].ekranDisindaMi()) {
                mermiler.erase(mermiler.begin() + i);
            } else {
                i++;
            }
        }

        if (atisBekleme > 0) atisBekleme--;
    }

    void ciz() {
        system("cls");
        std::cout << "Cikmak icin Q, hareket icin W/S, ates etmek icin BOSLUK'a basin." << std::endl;
        for (int y = 0; y < 20; ++y) {
            for (int x = 0; x < 34; ++x) {
                if (x == 0 || x == 33 || y == 0 || y == 19) {
                    std::cout << "[]";
                } else if (x == oyuncu.alX() && y == oyuncu.alY()) {
                    std::cout << ">";
                } else if (x == dusman.alX() && y == dusman.alY()) {
                    std::cout << "<";
                } else {
                    bool mermiVar = false;
                    for (const auto& mermi : mermiler) {
                        if (x == mermi.alX() && y == mermi.alY()) {
                            std::cout << "o";
                            mermiVar = true;
                            break;
                        }
                    }
                    if (!mermiVar) {
                        std::cout << " ";
                    }
                }
            }
            std::cout << std::endl;
        }
    }
};

#endif