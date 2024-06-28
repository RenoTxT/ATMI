#include "koperasi.h"
#include <iostream>
#include <algorithm>

const int MAX_PESERTA = 100;

Mahasiswa pesertaKoperasi[MAX_PESERTA];
int jumlahPeserta = 0;
std::string choice;

std::string toLower(const std::string& str) {
    std::string namaBawah = str;
    std::transform(namaBawah.begin(), namaBawah.end(), namaBawah.begin(), ::tolower);
    return namaBawah;
}

void tambahPeserta() {
    // Implementasi tambahPeserta()
}

void tampilkanDataPeserta() {
    // Implementasi tampilkanDataPeserta()
}

// Implementasi fungsi-fungsi lainnya
