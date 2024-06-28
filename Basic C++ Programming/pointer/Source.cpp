#include <iostream>
#include <cmath>

using namespace std;

// Fungsi untuk mengkuadratkan sebuah angka menggunakan pointer
void kuadratPointer(int num, int* result, int* address) {
    *result = num * num;  // Mengkuadratkan angka dan menyimpan hasil ke variabel yang ditunjuk oleh pointer result
    *address = reinterpret_cast<int>(result); // Mendapatkan alamat dari pointer result dan menyimpannya ke variabel yang ditunjuk oleh pointer address
}

// Fungsi untuk menghitung akar kuadrat sebuah angka menggunakan reference
void akarKuadratReference(int num, int& result, int& address) {
    result = sqrt(num);  // Menghitung akar kuadrat angka dan menyimpan hasil ke variabel yang dirujuk oleh reference result
    address = reinterpret_cast<int>(&result); // Mendapatkan alamat dari reference result dan menyimpannya ke variabel yang dirujuk oleh reference address
}

// Fungsi untuk menampilkan input, alamat, dan output
void displayResult(int num, int result, int address) {
    cout << "Input: " << num << endl;
    cout << "Address: " << address << endl;
    cout << "Output: " << result << endl << endl;
}

int main() {
    char yt;

awal:
    cout << "Coba Ya atau Tidak " << endl;

    int num;
    cout << "Masukkan angka: ";
    cin >> num;

    int resultPointer, addressPointer;
    kuadratPointer(num, &resultPointer, &addressPointer);

    int resultReference, addressReference;
    akarKuadratReference(resultPointer, resultReference, addressReference);

    // Menampilkan hasil menggunakan pointer
    cout << "Kuadrat menggunakan pointer:" << endl;
    displayResult(num, resultPointer, addressPointer);

    // Menampilkan hasil menggunakan reference
    cout << "Akar kuadrat menggunakan reference:" << endl;
    displayResult(resultPointer, resultReference, addressReference);

    // Looping
    cout << "Masukkan Data Lagi (y/t) ?  ";
    cin >> yt;
    cout << endl;
    if (yt == 'Y' || yt == 'y') {
        system("cls"); //membersihkan layar
        goto awal;
    }
    if (yt == 'T' || yt == 't') {
        goto akhir;
    }

akhir:
    return 0;
}
