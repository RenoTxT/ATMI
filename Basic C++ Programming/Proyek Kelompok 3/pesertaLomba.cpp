//Header Program
#include "pesertaLomba.h"

// Definisi Variabel dalam Structure
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

//Extern = mmendeklarasi ulang variabel yang berada di Source.CPP
extern peserta arrayPSR[];          
extern int j, k;

//Fungsi pengisian data peserta
void pesertaLomba::pesertaLombaCP()
{
    //Pemilihan lomba untuk Peserta lomba 
    cout << endl << "Masukan Nama lomba yang akan dilihat pesertanya : ";
    cin >> cariLomba;
    k = 0;
    int z = 1;
    //Proses pengisian data peserta ke dalam arrayPSR
    for (int k = 0; k < j; k++) 
    {
        //menampilkan seluruh data peserta lomba yang harus diisikan
        if (arrayPSR[k].lombaApa == cariLomba) 
        {
            cout << "Nama Tim " << z << "      : " << arrayPSR[k].namaTim << endl;          
            cout << "Nama Sekolah    : " << arrayPSR[k].sekolah << endl;
            cout << "Nomor Telepon   : " << arrayPSR[k].telponNo << endl;
            cout << "Alamat email    : " << arrayPSR[k].email << endl;
            cout << "Nama Peserta 1  : " << arrayPSR[k].nama1 << endl;
            cout << "Nama Peserta 2  : " << arrayPSR[k].nama2 << endl;
            cout << "Nama Peserta 3  : " << arrayPSR[k].nama3 << endl << endl;
            z++;
        }
    }
    //Statement jika salah menginputkan nama lomba
    if (arrayPSR[k].lombaApa != cariLomba)
    {
        //feedback
        cout << endl << "Belum ada peserta lomba " << cariLomba << endl << endl;       
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
