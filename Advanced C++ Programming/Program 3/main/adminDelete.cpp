#include "adminDelete.h"

struct tiketing {
    string tujuan;
    int jumlah_kursi = 0;
    string tanggal;
    string waktu;
    double harga = 0;
};

extern tiketing arrayTIKETING[];
extern int dataa, i;

void adminDelete::adminDeleteCP() {
    cout << "Masukkan Data yang akan dihapus: (masukan tujuan kereta)";
    cin >> dataCari;

    int index = -1;
    for (int i = 0; i < dataa; ++i) {
        if (arrayTIKETING[i].tujuan == dataCari) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        // Geser data ke belakang untuk menutup celah yang kosong
        for (int i = index; i < dataa - 1; ++i) {
            arrayTIKETING[i] = arrayTIKETING[i + 1];
        }
        // Mengurangi jumlah data
        dataa--;
        cout << "Data berhasil dihapus." << endl;
    }
    else {
        cout << "Data " << dataCari << " tidak ditemukan." << endl;
    }

    Sleep(2000);
}
