// File: Koperasi.h

#ifndef KOPERASI_H
#define KOPERASI_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class Mahasiswa {
private:
    std::string NIM;
    std::string password;
    int saldo;

public:
    Mahasiswa(const std::string& nim, const std::string& pass);
    void displayTabungan();
    void displaySaldo();
    void tarikUang();
    int getSaldo() const;
    std::string getNIM() const;
    void setSaldo(int newSaldo);
};

class Koperasi {
private:
    std::vector<Mahasiswa> daftarMahasiswa;

public:
    void tambahMahasiswa(const Mahasiswa& mahasiswa);
    void tampilkanDataMahasiswa();
    void ubahDataMahasiswa();
    void inputTabungan();
    void tampilkanTotalSaldo();
    void exportTotalSaldoToFile();
    void hapusMahasiswa();
    Mahasiswa* loginMahasiswa(const std::string& nim, const std::string& pass);
    void menuAdmin();
    void menuMahasiswa(Mahasiswa* mahasiswa);
};

#endif // KOPERASI_H
