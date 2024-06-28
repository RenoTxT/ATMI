#include "menuAdmin.h"           
#include "addLomba.h"
#include "editLomba.h"
#include "pesertaLomba.h"
#include "hapusLomba.h"

addLomba aL;
editLomba eL;
pesertaLomba pL;
hapusLomba hL;

struct lomba {
    int maxPeserta;
    int harga;
    string nama;
    string spec;
};
extern lomba arrayLOMBA[];               //Extern = mendeklarasi ulang variabel global
extern int dataa;

void menuAdmin::menuAdminCP()                        //Menu admin
{
mnAdmin:
    system("cls");
    cout << "|````````````````````````````````````````````````````````````````````|" << endl;
    cout << "                        Mekatro 55                                 " << endl;
    cout << "|____________________________________________________________________|" << endl;
    cout << "|--------------------------------------------------------------------|" << endl;

    cout << "|        LOMBA" << "       |    KATEGORI" << "     |    SLOT" << "     |     HARGA     |" << endl;
    cout << "|____________________________________________________________________|" << endl;

    //untuk menggeser inputan agar rapi
    for (int i = 0; i < dataa; ++i)
    {
        cout << "|" << left << setw(20) << arrayLOMBA[i].nama << "|      " << setw(11) << arrayLOMBA[i].spec << "|     " << setw(7) << arrayLOMBA[i].maxPeserta << "|     " << setw(10) << arrayLOMBA[i].harga << "|" << endl;
    }

    cout << "|--------------------------------------------------------------------|" << endl;
    cout << "1. Tambah Lomba" << endl;
    cout << "2. Edit Lomba" << endl;
    cout << "3. Lihat Peserta Lomba" << endl;
    cout << "4. Hapus Lomba" << endl;
    cout << "5. Mengganti Nama Event" << endl;
    cout << "6. Keluar" << endl << endl;
    cout << "Pilih : ";
    cin >> pilih;



    switch (pilih)
    {
    case 1:
        system("cls");
        aL.addLombaCP();
        goto mnAdmin;
        break;

    case 2:
        eL.editLombaCP();
        goto mnAdmin;
        break;

    case 3:
        pL.pesertaLombaCP();
        goto mnAdmin;
        break;

    case 4:
        hL.hapusLombaCP();
        goto mnAdmin;
        break;

    case 5:
        return;
    }
}
