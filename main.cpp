// main.cpp
#include "Oyun.h"

int main() {
    srand(static_cast<unsigned>(time(0)));
    Oyun oyun;
    oyun.calistir();
    return 0;
}