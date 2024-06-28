#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

const int MAX_PESERTA = 100;
string choice;

struct Mahasiswa {
    string nama;
    int nim;
    double saldo;
};

Mahasiswa pesertaKoperasi[MAX_PESERTA];
int jumlahPeserta = 0;

// Function to convert a string to lowercase
string toLower(const string& str) {
    string namaBawah = str;
    transform(namaBawah.begin(), namaBawah.end(), namaBawah.begin(), ::tolower);
    return namaBawah;
}


void tambahPeserta() {
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


void tampilkanDataPeserta() {
    // Sort the data based on the name
    system("cls");
    cout << "========== KOPERASI MAHASISWA ==========\n";
    for (int i = 0; i < jumlahPeserta; ++i) {
        cout << "Nama: " << pesertaKoperasi[i].nama << "\tNIM: " << pesertaKoperasi[i].nim
            << "\tSaldo: " << pesertaKoperasi[i].saldo << endl;
    }
    cout << "========================================\n";
}

void ubahDataPeserta() {
    int nim;
    cout << "Masukkan NIM Mahasiswa yang ingin diubah datanya: ";
    cin >> nim;
    for (int i = 0; i < jumlahPeserta; ++i) {
        if (pesertaKoperasi[i].nim == nim) {
            cout << "Masukkan Nama Mahasiswa baru: ";
            cin >> pesertaKoperasi[i].nama;
            cout << "Data Mahasiswa berhasil diubah!" << endl;
            return;
        }
    }
    cout << "NIM Mahasiswa tidak ditemukan!" << endl;
}

void inputTabungan() {
    int nim;
    cout << "Masukkan NIM Mahasiswa untuk input tabungan: ";
    cin >> nim;

    for (int i = 0; i < jumlahPeserta; ++i) {
        if (pesertaKoperasi[i].nim == nim) {
            cout << "Masukkan tabungan untuk " << pesertaKoperasi[i].nama << " (bulan Januari): ";
            cin >> pesertaKoperasi[i].saldo;

            for (int j = 2; j <= 6; ++j) {
                cout << "Masukkan tabungan untuk " << pesertaKoperasi[i].nama << " (bulan " << j << "): ";
                int tabungan;
                cin >> tabungan;
                pesertaKoperasi[i].saldo += tabungan;
            }

            cout << "Tabungan berhasil diinput untuk " << pesertaKoperasi[i].nama << " dengan NIM " << nim << "!" << endl;
            return; // Exit the function once input is done for the corresponding NIM
        }
    }

    // If NIM is not found
    cout << "NIM Mahasiswa tidak ditemukan!" << endl;
}


void tampilkanTotalSaldo() {
    int totalSaldo = 0;
    for (int i = 0; i < jumlahPeserta; ++i) {
        totalSaldo += pesertaKoperasi[i].saldo;
    }
    cout << "Total Saldo Semua Peserta: " << totalSaldo << endl;
}

void exportDataSaldo() {
    ofstream outputFile("saldo_peserta.txt");
    for (int i = 0; i < jumlahPeserta; ++i) {
        outputFile << "Nama: " << pesertaKoperasi[i].nama << "\tNIM: " << pesertaKoperasi[i].nim
            << "\tSaldo: " << pesertaKoperasi[i].saldo << endl;
    }
    outputFile.close();
    cout << "Data berhasil diexport ke saldo_peserta.txt" << endl;
}

void fungsiHapus() {
    int nim;
    cout << "Masukkan NIM Mahasiswa yang ingin dihapus dari koperasi: ";
    cin >> nim;
    for (int i = 0; i < jumlahPeserta; ++i) {
        if (pesertaKoperasi[i].nim == nim) {
            for (int j = i; j < jumlahPeserta - 1; ++j) {
                pesertaKoperasi[j] = pesertaKoperasi[j + 1];
            }
            jumlahPeserta--;
            cout << "Mahasiswa dengan NIM " << nim << " berhasil dihapus dari koperasi!" << endl;
            return;
        }
    }
    cout << "NIM Mahasiswa tidak ditemukan!" << endl;
}

void menu() {
    cout << "========== KOPERASI MAHASISWA ==========\n";
    cout << "1. Tambah Peserta\n"
        << "2. Tampilkan Data\n"
        << "3. Ubah Data\n"
        << "4. Input Tabungan Peserta\n"
        << "5. Total Saldo\n"
        << "6. Export File\n"
        << "7. Hapus Data\n"
        << "========================================\n";
    
    cout << "Pilih menu (1-7): ";
    cin >> choice;
    cout << "========================================\n";
    cout << endl;
}

int main() {
    char yt;

awal:
    menu();

    try {
        switch (stoi(choice)) {
        case 1:
            tambahPeserta();
            break;
        case 2:
            tampilkanDataPeserta();
            break;
        case 3:
            ubahDataPeserta();
            break;
        case 4:
            inputTabungan();
            break;
        case 5:
            tampilkanTotalSaldo();
            break;
        case 6:
            exportDataSaldo();
            break;
        case 7:
            fungsiHapus();
            break;
        default:
            cout << "Pilihan tidak valid!" << endl;
        }
    }
    catch (const invalid_argument& e) {
        cout << "Input tidak valid! Harap masukkan angka." << endl;
    }

mid:
    cout << "\nApakah ingin kembali ke menu utama? (y/t): ";
    cin >> yt;
    cout << endl;
    if (yt == 'Y' || yt == 'y') {
        system("cls");
        goto awal;
    }
    else if (yt == 'T' || yt == 't') {
        goto akhir;
    }
    else {
        system("cls");
        cout << "Input yang anda masukkan salah" << endl;
        goto mid;
    }

akhir:
    return 0;
}
