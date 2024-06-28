#include <iostream>
#include <cmath>

using namespace std;

// Fungsi kuadrat menggunakan pointer
void kuadratPointer(int angka, int* hasil, int* address) {
    *hasil = angka * angka;
    *address = reinterpret_cast<int>(hasil);
}

// Fungsi akar kuadrat menggunakan reference
void akarKuadratRef(int angka, double& hasil, int& address) {
    hasil = sqrt(angka);
    address = reinterpret_cast<int>(&hasil);
}

int main() {
    char yt;
    int input;

awal:
    cout << "Masukkan angka: ";
    cin >> input;

    // Fungsi kuadrat
    int hasilKuadrat;
    int addressKuadrat;
    kuadratPointer(input, &hasilKuadrat, &addressKuadrat);

    cout << "Kuadrat dari " << input << " = " << hasilKuadrat << endl;
    cout << "Address pointer: " << addressKuadrat << endl << endl;

    // Fungsi akar kuadrat
    double hasilAkarKuadrat;
    int addressAkarKuadrat;
    akarKuadratRef(input, hasilAkarKuadrat, addressAkarKuadrat);

    cout << "Akar kuadrat dari " << input << " = " << hasilAkarKuadrat << endl;
    cout << "Address reference: " << addressAkarKuadrat << endl << endl;

    cout << "Coba Ya atau Tidak " << endl;
    cout << "Masukkan Data Lagi (y/t) ?  ";
    cin >> yt;
    cout << endl;

    if (yt == 'Y' || yt == 'y') {
        goto awal;
    }
    if (yt == 'T' || yt == 't') {
        goto akhir;
    }

akhir:
    return 0;
}
