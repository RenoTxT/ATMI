#include "tambahPeserta.h"
#include <string>
#include <algorithm>

using namespace std;

extend jumlahPeserta;
extend MAX_PESERTA;

void tambahPeserta::tambahPesertaCP() {
    if (jumlahPeserta < MAX_PESERTA) {
        // Clear the newline character left in the input buffer
        cin.ignore();

        //case-insensitive
        cout << "Masukkan Nama Mahasiswa: ";
        getline(cin, pesertaKoperasi[jumlahPeserta].nama);

        string namaBesar = toLower(pesertaKoperasi[jumlahPeserta].nama);

        for (int i = 0; i < jumlahPeserta; ++i) {
            string MahasiswaNama = toLower(pesertaKoperasi[i].nama);
            if (MahasiswaNama == namaBesar) {
                cout << "Maaf, nama yang dimasukkan sudah terpakai. Silakan coba lagi." << endl;
                return; // Exit the function
            }
        }

        // If the name is not in use, proceed to enter NIM
        cout << "Masukkan NIM Mahasiswa: ";
        cin >> pesertaKoperasi[jumlahPeserta].nim;

        // Check if the NIM is already in use
        for (int i = 0; i < jumlahPeserta; ++i) {
            if (pesertaKoperasi[i].nim == pesertaKoperasi[jumlahPeserta].nim) {
                cout << "Maaf, NIM yang dimasukkan sudah terpakai. Silakan coba lagi." << endl;
                return; // Exit the function
            }
        }

        pesertaKoperasi[jumlahPeserta].saldo = 0;
        jumlahPeserta++;
        cout << "Peserta berhasil ditambahkan!" << endl;
    }
    else {
        cout << "Koperasi Mahasiswa sudah penuh!" << endl;
    }
}