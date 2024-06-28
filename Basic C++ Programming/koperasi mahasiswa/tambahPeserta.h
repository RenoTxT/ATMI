#pragma once
#include <iostream>
#include <string>
#include <algorithm>

// Structure to store participant data
struct Mahasiswa {
    std::string nama;
    int nim;
    double saldo;
};

class tambahPeserta {
public:
    // Declare the function to add a participant
    void tambahPesertaCP(Mahasiswa pesertaKoperasi[], int& jumlahPeserta, const int MAX_PESERTA);
};
