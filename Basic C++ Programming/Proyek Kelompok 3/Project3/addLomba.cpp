#include "addLomba.h"
#include <string>

struct lomba {
    int maxPeserta;
    int harga;
    string nama;
    string spec;
};
extern lomba arrayLOMBA[];                   // Extern = mendeklarasi ulang variabel global
extern int dataa, i;

void addLomba::addLombaCP() {
    cout << "=====================================================================" << endl;
    cout << "                        Mekatronika Cup 2023                       " << endl;
    cout << "=====================================================================" << endl;
    cout << "Berapa lomba yang ingin ditambahkan : ";
    cin >> newLomba;
    cout << endl;

    cin.ignore();  // Ignore the newline character left in the input buffer

    for (i = dataa; i < dataa + newLomba; i++) {
        cout << "Nama Lomba " << i + 1 << "      : ";
        getline(cin, arrayLOMBA[i].nama);  // Read the whole line, including spaces
        cout << "Kategori Lomba    : ";
        getline(cin, arrayLOMBA[i].spec);
        cout << "Maksimal Peserta  : ";
        cin >> arrayLOMBA[i].maxPeserta;
        cout << "Biaya Pendaftaran : ";
        cin >> arrayLOMBA[i].harga;
        cout << endl;
        cin.ignore();  // Ignore the newline character left in the input buffer
    }
    dataa = i;
    cout << "Lomba sudah diupdate." << endl;
    Sleep(3000);
}
