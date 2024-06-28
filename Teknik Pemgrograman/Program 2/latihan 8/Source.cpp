// main.cpp

#include <iostream>
#include "kalkulator.h"

using namespace std;

int main() {
    char yt;

    do {

        system("cls");
        cout << "Pilih operasi:\n"
            << "1. xMax\n"
            << "2. hMax\n"
            << "3. Kali\n"
            << "4. Bagi\n"
            << "5. Luas Layang-Layang\n"
            << "6. Keliling Layang-Layang\n"
            << "7. Volume Tabung\n";

        int choice;
        cout << "Masukkan nomor operasi yang diinginkan: ";
        cin >> choice;
        cout << endl;


        double result;

        double kecepatan, sudut;
        switch (choice) {
        case 1:
            cout << "Angka pertama : ";
            cin >> kecepatan;
            cout << "Angka kedua   : ";
            cin >> sudut;
            result = 
            break;
        case 2:
            cout << "Angka pertama : ";
            cin >> a;
            cout << "Angka kedua   : ";
            cin >> b;
            result = kalkulatorLayangLayang.kurang(a, b);
            break;
        case 3:
            cout << "Angka pertama : ";
            cin >> a;
            cout << "Angka kedua   : ";
            cin >> b;
            result = kalkulatorLayangLayang.kali(a, b);
            break;
        case 4:
            cout << "Angka pertama : ";
            cin >> a;
            cout << "Angka kedua   : ";
            cin >> b;
            result = kalkulatorLayangLayang.bagi(a, b);
            break;
        case 5:
            cout << "D1 : ";
            cin >> a;
            cout << "D2 : ";
            cin >> b;
            result = kalkulatorLayangLayang.luasLayangLayang(a, b);
            break;
        case 6:
            cout << "D1 : ";
            cin >> a;
            cout << "D2 : ";
            cin >> b;
            result = kalkulatorLayangLayang.kelilingLayangLayang(a, b);
            break;
        case 7:
            cout << "Diamter : ";
            cin >> a;
            cout << "Tinggi  : ";
            cin >> b;
            result = kalkulatorTabung.volumeTabung(a, b);
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
