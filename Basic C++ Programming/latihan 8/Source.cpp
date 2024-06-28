// main.cpp

#include <iostream>
#include "kalkulator.h"

Maximal kalkulator;

using namespace std;

double a, c, d1, d2, jari_jari, tinggi;

int main() {
    char yt;

    do {

        system("cls");
        cout << "Pilih operasi:\n"
            << "1. xMax\n"
            << "2. hMax\n"
            << "3. Keliling Layang-Layang\n"
            << "4. Luas Layang-Layang\n"
            << "5. Volume Tabung\n";

        int choice;
        cout << "Masukkan nomor operasi yang diinginkan: ";
        cin >> choice;
        cout << endl;


        double result;

        double kecepatan, sudut;
        switch (choice) {
        case 1:
            cout << "Kecepatan : ";
            cin >> kecepatan;
            cout << "Sudut     : ";
            cin >> sudut;
            result = kalkulator.xMax(kecepatan, sudut);
            break;
        case 2:
            cout << "Kecepatan : ";
            cin >> kecepatan;
            cout << "Sudut     : ";
            cin >> sudut;
            result = kalkulator.hMax(kecepatan, sudut);
            break;
        case 3:
            cout << "Diagonal 1   : ";
            cin >> a;
            cout << "Diagonal 2   : ";
            cin >> c;
            result = kalkulator.kelilinglayang(a, c);
            break;
        case 4:
            cout << "Diagonal 1   : ";
            cin >> d1;
            cout << "Diagonal 2   : ";
            cin >> d2;
            result = kalkulator.luaslayang(d1, d2);
            break;
        case 5:
            cout << "Jari - jari : ";
            cin >> jari_jari;
            cout << "Tinggi      : ";
            cin >> tinggi;
            result = kalkulator.volumetabung(jari_jari, tinggi);
            break;
        case 6:
    
            break;
        default:
            cout << "Operasi tidak valid." << endl;
            continue; // Skip the rest of the loop and start again
        }

        cout << endl;
        cout << "Hasil operasi: " << result << endl;

        cout << endl;
        cout << "Apakah ingin kembali ke menu utama? (y/t): ";
        cin >> yt;
        cout << endl;
    } while (yt == 'Y' || yt == 'y');
    return 0;
}
