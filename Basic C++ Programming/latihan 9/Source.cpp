// File: Main.cpp

#include "Koperasi.h"

int main() {
    char yt;
    Koperasi koperasi;

awal:
    std::cout << "Coba Ya atau Tidak " << std::endl;

    std::cout << std::endl << std::endl;

    std::cout << "Masukkan Data Lagi (y/t) ?  ";
    std::cin >> yt;
    std::cout << std::endl;
    if (yt == 'Y' || yt == 'y') {
        goto awal;
    }
    if (yt == 'T' || yt == 't') {
        goto akhir;
    }
akhir:

    return 0;
}
