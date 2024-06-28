//Header Program
#include "hapusLomba.h"

//Definisi Variabel dalam struktur
struct lomba {
    int maxPeserta;
    int harga;
    string nama;
    string spec;
};

// Extern = mendeklarasi ulang variabel yang berada di Source.CPP
extern lomba arrayLOMBA[];
extern int dataa;

//Fungsi untuk menghapus lomba
void hapusLomba::hapusLombaCP()
{
    //Deklarasi Variabel lokal
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

    //proses menghapus data jika ditemukan nama lomba yang akan dihapus
    if (index != -1) {
        // Geser data ke belakang untuk menutup celah yang kosong
        for (int i = index; i < dataa - 1; ++i) {
            arrayLOMBA[i] = arrayLOMBA[i + 1];
        }
        // Mengurangi jumlah data
        dataa--;
        cout << "Lomba berhasil dihapus." << endl;
    }
    //Feedback jika nama lomba tidak ditemukan
    else {
        cout << "Lomba " << lombaCari << " tidak ditemukan." << endl;
    }

    Sleep(2000);
}
