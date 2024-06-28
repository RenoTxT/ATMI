#include "hapusLomba.h"
struct lomba {
    int maxPeserta;
    int harga;
    string nama;
    string spec;
};
extern lomba arrayLOMBA[];
extern int dataa;

void hapusLomba::hapusLombaCP()
{
    string lombaCari;
    cout << "Masukkan Nama Lomba yang akan dihapus: ";
    cin >> lombaCari;

    // Cari lomba berdasarkan nama lomba
    int index = -1;
    for (int i = 0; i < dataa; ++i) {
        if (arrayLOMBA[i].nama == lombaCari) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        // Geser data ke belakang untuk menutup celah yang kosong
        for (int i = index; i < dataa - 1; ++i) {
            arrayLOMBA[i] = arrayLOMBA[i + 1];
        }
        // Mengurangi jumlah data
        dataa--;
        cout << "Lomba berhasil dihapus." << endl;
    }
    else {
        cout << "Lomba " << lombaCari << " tidak ditemukan." << endl;
    }

    Sleep(2000);
}
