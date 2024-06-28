#include "editLomba.h"
#include <iostream>
#include <limits>
#include <string>

using namespace std;  // Add this line to avoid using std::

struct lomba {
    int maxPeserta;
    int harga;
    string nama;
    string spec;
};
extern lomba arrayLOMBA[];
extern int dataa;

void editLomba::editLombaCP()
{
editLomba:
    cout << "Masukan Nama lomba yang akan di edit : ";

    // Read the entire line, including spaces
    getline(cin >> ws, cariLomba);

    for (int i = 0; i < dataa; ++i) {
        if (arrayLOMBA[i].nama == cariLomba) {
            system("cls");
            cout << "Mau edit yang mana ? (1-5)" << endl << endl;
            cout << "1. Nama             :" << arrayLOMBA[i].nama << endl;
            cout << "2. Kategori         :" << arrayLOMBA[i].spec << endl;
            cout << "3. Maksimal Peserta :" << arrayLOMBA[i].maxPeserta << endl;
            cout << "4. Biaya Lomba      :" << arrayLOMBA[i].harga << endl;
            cout << "5. Keluar" << endl;
            cout << "Pilih : ";
            cin >> pilih;

            switch (pilih) {
            case 1:
                cout << endl << "Nama : ";
                getline(cin >> ws, arrayLOMBA[i].nama);
                system("cls");
                cout << "1. Nama             :" << arrayLOMBA[i].nama << endl;
                cout << "2. Kategori         :" << arrayLOMBA[i].spec << endl;
                cout << "3. Maksimal Peserta :" << arrayLOMBA[i].maxPeserta << endl;
                cout << "4. Biaya Lomba      :" << arrayLOMBA[i].harga << endl << endl;
                cout << "Lomba sudah diupdate" << endl;
                Sleep(3000);
                Sleep(2000);
                return;

            case 2:
                cout << endl << "Kategori : ";
                getline(cin >> ws, arrayLOMBA[i].spec);
                system("cls");
                cout << "1. Nama             :" << arrayLOMBA[i].nama << endl;
                cout << "2. Kategori         :" << arrayLOMBA[i].spec << endl;
                cout << "3. Maksimal Peserta :" << arrayLOMBA[i].maxPeserta << endl;
                cout << "4. Biaya Lomba      :" << arrayLOMBA[i].harga << endl << endl;
                cout << "Lomba sudah diupdate" << endl;
                Sleep(3000);
                Sleep(2000);
                return;

            case 3:
                cout << endl << "Maksimal Peserta : ";
                cin >> arrayLOMBA[i].maxPeserta;
                system("cls");
                cout << "1. Nama             :" << arrayLOMBA[i].nama << endl;
                cout << "2. Kategori         :" << arrayLOMBA[i].spec << endl;
                cout << "3. Maksimal Peserta :" << arrayLOMBA[i].maxPeserta << endl;
                cout << "4. Biaya Lomba      :" << arrayLOMBA[i].harga << endl << endl;
                cout << "Lomba sudah diupdate" << endl;
                Sleep(3000);
                Sleep(2000);
                return;

            case 4:
                cout << endl << "Biaya Lomba : ";
                cin >> arrayLOMBA[i].harga;
                system("cls");
                cout << "1. Nama             :" << arrayLOMBA[i].nama << endl;
                cout << "2. Kategori         :" << arrayLOMBA[i].spec << endl;
                cout << "3. Maksimal Peserta :" << arrayLOMBA[i].maxPeserta << endl;
                cout << "4. Biaya Lomba      :" << arrayLOMBA[i].harga << endl << endl;
                cout << "Lomba sudah diupdate" << endl;
                Sleep(3000);
                Sleep(2000);
                return;

            case 5:
                return;
            }
        }
    }
}
