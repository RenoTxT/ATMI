#include "pesertaLomba.h"

struct peserta {
    string namaTim;
    string nama1;
    string nama2;
    string nama3;
    string telponNo;
    string email;
    string lombaApa;
    string sekolah;
};
extern peserta arrayPSR[];          //Extern = mendeklarasi ulang variabel global
extern int j, k;
void pesertaLomba::pesertaLombaCP()
{
    //melihat peserta lomba apa?
    cout << endl << "Masukan Nama lomba yang akan dilihat pesertanya : ";
    cin >> cariLomba;
    k = 0;
    int z = 1;
    for (int k = 0; k < j; k++) {
        if (arrayPSR[k].lombaApa == cariLomba) {
            cout << "Nama Tim " << z << "      : " << arrayPSR[k].namaTim << endl;          //menampilkan seluruh data peserta lomba
            cout << "Nama Sekolah    : " << arrayPSR[k].sekolah << endl;
            cout << "Nomor Telepon   : " << arrayPSR[k].telponNo << endl;
            cout << "Alamat email    : " << arrayPSR[k].email << endl;
            cout << "Nama Peserta 1  : " << arrayPSR[k].nama1 << endl;
            cout << "Nama Peserta 2  : " << arrayPSR[k].nama2 << endl;
            cout << "Nama Peserta 3  : " << arrayPSR[k].nama3 << endl << endl;
            z++;
        }
    }
    if (arrayPSR[k].lombaApa != cariLomba)
    {
        cout << endl << "Belum ada peserta lomba " << cariLomba << endl << endl;       //Belum ada peserta
    }
    k = j;
    cout << "Press Space to Continue...";

    while (1) {
        key = _getch();

        if (key == ' ') {
            // Kembali ke menu admin
            return;
            break;
        }
    }

    cin >> pilih;
}
