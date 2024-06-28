#include <iostream>
#include <string>

using namespace std;

// Mendefinisikan struktur 'Mahasiswa'
struct Mahasiswa {
    string nama;
    int umur;
    double IPK;
};

int main() {
    // Mendeklarasikan variabel bertipe 'Mahasiswa'
    Mahasiswa mahasiswa1;

    // Mengisi data ke dalam variabel 'mahasiswa1'
    mahasiswa1.nama = "John Doe";
    mahasiswa1.umur = 20;
    mahasiswa1.IPK = 3.75;

    // Menampilkan informasi mahasiswa
    cout << "Nama: " << mahasiswa1.nama << endl;
    cout << "Umur: " << mahasiswa1.umur << " tahun" << endl;
    cout << "IPK: " << mahasiswa1.IPK << endl;

    return 0;
}
