// File: Koperasi.cpp

#include "Koperasi.h"

Mahasiswa::Mahasiswa(const std::string& nim, const std::string& pass)
    : NIM(nim), password(pass), saldo(0) {}

void Mahasiswa::displayTabungan() {
    // Tampilkan tabungan dari bulan Januari - Juni
    // Implementasikan sesuai kebutuhan
}

void Mahasiswa::displaySaldo() {
    std::cout << "Saldo saat ini: " << saldo << std::endl;
}

void Mahasiswa::tarikUang() {
    // Implementasi penarikan uang
}

int Mahasiswa::getSaldo() const {
    return saldo;
}

std::string Mahasiswa::getNIM() const {
    return NIM;
}

void Mahasiswa::setSaldo(int newSaldo) {
    saldo = newSaldo;
}

void Koperasi::tambahMahasiswa(const Mahasiswa& mahasiswa) {
    daftarMahasiswa.push_back(mahasiswa);
}

void Koperasi::tampilkanDataMahasiswa() {
    // Implementasi tampilkan data mahasiswa
}

void Koperasi::ubahDataMahasiswa() {
    // Implementasi ubah data mahasiswa
}

void Koperasi::inputTabungan() {
    // Implementasi input tabungan
}

void Koperasi::tampilkanTotalSaldo() {
    // Implementasi tampilkan total saldo
}

void Koperasi::exportTotalSaldoToFile() {
    // Implementasi export total saldo ke file .txt
}

void Koperasi::hapusMahasiswa() {
    // Implementasi fungsi hapus mahasiswa
}

Mahasiswa* Koperasi::loginMahasiswa(const std::string& nim, const std::string& pass) {
    // Implementasi login mahasiswa
    return nullptr;
}

void Koperasi::menuAdmin() {
    // Implementasi menu admin
}

void Koperasi::menuMahasiswa(Mahasiswa* mahasiswa) {
    // Implementasi menu mahasiswa
}
