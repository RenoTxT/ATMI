//Header Program
#include "menuAdmin.h"           
#include "addLomba.h"
#include "editLomba.h"
#include "pesertaLomba.h"
#include "hapusLomba.h"

//Definisi void kelas yang dipakai
addLomba aL;
editLomba eL;
pesertaLomba pL;
hapusLomba hL;

//Extern = mmendeklarasi ulang variabel yang berada di Source.CPP
struct lomba {
    int maxPeserta;
    int harga;
    string nama;
    string spec;
};

//Extern = mendeklarasi ulang variabel global
extern lomba arrayLOMBA[];
extern int dataa;

//Fungsi Menu Admin
void menuAdmin::menuAdminCP()                        
{
mnAdmin:
    system("cls");
    cout << "|````````````````````````````````````````````````````````````````````|" << endl;
    cout << "|------------------------- BAR COMPETITION 24' ----------------------|" << endl;
    cout << "|____________________________________________________________________|" << endl;
    cout << "|--------------------------------------------------------------------|" << endl;

    cout << "|        LOMBA" << "       |    KATEGORI" << "     |    SLOT" << "     |     HARGA     |" << endl;
    cout << "|____________________________________________________________________|" << endl;

    //untuk menggeser inputan agar rapi sesuai dengan kolom section
    for (int i = 0; i < dataa; ++i)
    {
        cout << "|" << left << setw(20) << arrayLOMBA[i].nama << "|      " << setw(11) << arrayLOMBA[i].spec << "|     " << setw(7) << arrayLOMBA[i].maxPeserta << "|     " << setw(10) << arrayLOMBA[i].harga << "|" << endl;
    }

    // Pilihan dalam menu Admin
    cout << "|--------------------------------------------------------------------|" << endl;
    cout << "1. Tambah Lomba" << endl;
    cout << "2. Edit Lomba" << endl;
    cout << "3. Lihat Peserta Lomba" << endl;
    cout << "4. Hapus Lomba" << endl;
    cout << "5. Keluar" << endl << endl;
    cout << "Pilih : ";
    cin >> pilih;

    //Pembagian tiap pilihan menu
    switch (pilih)
    {
    case 1: //Menampilkan void program CPP addLomba
        system("cls");
        aL.addLombaCP();
        goto mnAdmin;
        break;

    case 2: //Menampilkan void program CPP editLomba
        eL.editLombaCP();
        goto mnAdmin;
        break;

    case 3: //Menampilkan void program CPP pesertaLomba
        pL.pesertaLombaCP();
        goto mnAdmin;
        break;

    case 4: //Menampilkan void program CPP hapusLomba
        hL.hapusLombaCP();
        goto mnAdmin;
        break;

    case 5:
        return;
    }
}
