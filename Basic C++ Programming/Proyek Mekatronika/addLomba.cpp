#include "addLomba.h"

struct lomba {
    int maxPeserta;
    int harga;
    string nama;
    string spec;
};
extern lomba arrayLOMBA[];                   //Extern = mendeklarasi ulang variabel global
extern int dataa, i;

void addLomba::addLombaCP()
{
    cout << "=====================================================================" << endl;
    cout << "                        Mekatronika Cup 2023                       " << endl;
    cout << "=====================================================================" << endl;
    cout << "Berapa lomba yang ingin ditambahkan : ";
    cin >> newLomba;
    cout << endl;

    for (i = dataa; i < dataa + newLomba; i++)              //menambah lomba
    {

        cout << "Nama Lomba " << i + 1 << "      : ";
        cin >> arrayLOMBA[i].nama;
        cout << "Kategori Lomba    : ";
        cin >> arrayLOMBA[i].spec;
        cout << "Maksimal Peserta  : ";
        cin >> arrayLOMBA[i].maxPeserta;
        cout << "Biaya Pendaftaran : ";
        cin >> arrayLOMBA[i].harga;
        cout << endl;
    }
    dataa = i;
    cout << "Lomba sudah diupdate." << endl;
    Sleep(3000);
}
