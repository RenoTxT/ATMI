#pragma once
#include <string>
using namespace std;

class user
{
public:
    string username; // Menyimpan username
    string password; // Menyimpan password
    string kodePemesanan;  // Menyimpan kode pemesanan unik
    int kelas;
    time_t waktuMulai;  // Menyimpan waktu mulai pemesanan
    int jamMulai;       // Menyimpan jam mulai pemesanan
    int jamBerhenti;    // Menyimpan jam berhenti pemesanan
    user(const string& u, const string& p) : username(u), password(p), kelas(-1), waktuMulai(0), jamMulai(0), jamBerhenti(0) {}//objek user dengan beberapa atribut seperti yang tercantum
    // const string & digunakan untuk membuat referensi konstan ke objek string
    string generateUniqueCode();// fungsi untuk membuat kode pemesanan
    string addLeadingZero(int number);// fungsi untuk menambahkan nol di depan angka jika angka kurang dari 10.
};

