// Header Program
#include "addLomba.h"
#include <string>

// Definisi Variabel dalam struktur
struct lomba {
    int maxPeserta;
    int harga;
    string nama;
    string spec;
};

// Extern = mendeklarasi ulang variabel yang berada di Source.CPP
extern lomba arrayLOMBA[];                   
extern int dataa, i;

// Fungsi untuk menambahkan lomba
void addLomba::addLombaCP() {
    cout << "=====================================================================" << endl;
    cout << "-------------------------- BAR COMPETITION 24' ----------------------" << endl;
    cout << "=====================================================================" << endl;
    cout << "Berapa lomba yang ingin ditambahkan : ";
    cin >> newLomba;
    cout << endl;

    cin.ignore();

    //Proses untuk mengisikan bentuk lomba ke dalam Array (arrayLOMBA)
    for (i = dataa; i < dataa + newLomba; i++) {
        cout << "Nama Lomba " << i + 1 << "      : ";
        getline(cin, arrayLOMBA[i].nama);  // Membaca semua kalimat beserta spasi
        cout << "Kategori Lomba    : ";
        getline(cin, arrayLOMBA[i].spec);
        cout << "Maksimal Peserta  : ";
        cin >> arrayLOMBA[i].maxPeserta;
        cout << "Biaya Pendaftaran : ";
        cin >> arrayLOMBA[i].harga;
        cout << endl;
        cin.ignore();  // Ignore the newline character left in the input buffer
    }
    //Feedback jika lomba sudah diinputkan
    dataa = i;
    cout << "Lomba sudah diupdate." << endl;
    Sleep(3000);
}
