#include <iostream>
#include <fstream>
#include <algorithm>
#include "tambahPeserta.h" // Include the header file for tambahPeserta

using namespace std;

// Structure to store participant data
struct Mahasiswa {
    string nama;
    int nim;
    double saldo;
};

// Global variable declarations
const int MAX_PESERTA = 100;
Mahasiswa pesertaKoperasi[MAX_PESERTA];
int jumlahPeserta = 0;
string choice;

// Function declarations
void tambahPeserta();
void tampilkanDataPeserta();
void ubahDataPeserta();
void inputTabungan();
void tampilkanTotalSaldo();
void exportDataSaldo();
void fungsiHapus();
void menu();

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
            cout << "Invalid choice!" << endl;
        }
    }
    catch (const invalid_argument& e) {
        cout << "Invalid input! Please enter a number." << endl;
    }

mid:
    cout << "\nDo you want to go back to the main menu? (y/n): ";
    cin >> yt;
    cout << endl;
    if (yt == 'Y' || yt == 'y') {
        system("cls");
        goto awal;
    }
    else if (yt == 'N' || yt == 'n') {
        goto akhir;
    }
    else {
        system("cls");
        cout << "Incorrect input" << endl;
        goto mid;
    }

akhir:
    return 0;
}

// Other functions can be found in the previous implementation.
