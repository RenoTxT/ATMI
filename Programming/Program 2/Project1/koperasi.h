#ifndef KOPERASI_H
#define KOPERASI_H

#include <string>

struct Mahasiswa {
    std::string nama;
    int nim;
    double saldo;
};

extern Mahasiswa pesertaKoperasi[];
extern int jumlahPeserta;
extern std::string choice;

std::string toLower(const std::string& str);
void tambahPeserta();
void tampilkanDataPeserta();
void ubahDataPeserta();
void inputTabungan();
void tampilkanTotalSaldo();
void exportDataSaldo();
void fungsiHapus();
void menu();

#endif // KOPERASI_H
