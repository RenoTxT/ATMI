#include "editLomba.h"

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
editLomba:                                            //mencari lomba yang akan di edit
    cout << "Masukan Nama lomba yang akan di edit : ";
    cin >> cariLomba;
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
            switch (pilih)
            {
            case 1:                                           //mengubah yang apa ni?
                cout << endl;
                cout << "Nama : ";
                cin >> arrayLOMBA[i].nama;
                system("cls");
                cout << "1. Nama             :" << arrayLOMBA[i].nama << endl;
                cout << "2. Kategori         :" << arrayLOMBA[i].spec << endl;
                cout << "3. Maksimal Peserta :" << arrayLOMBA[i].maxPeserta << endl;
                cout << "4. Biaya Lomba      :" << arrayLOMBA[i].harga << endl << endl;
                cout << "Lomba sudah diupdate" << endl;
                Sleep(3000);
                Sleep(2000);
                return;
                break;

            case 2:
                cout << endl;
                cout << "Kategori : ";
                cin >> arrayLOMBA[i].spec;
                system("cls");
                cout << "1. Nama             :" << arrayLOMBA[i].nama << endl;
                cout << "2. Kategori         :" << arrayLOMBA[i].spec << endl;
                cout << "3. Maksimal Peserta :" << arrayLOMBA[i].maxPeserta << endl;
                cout << "4. Biaya Lomba      :" << arrayLOMBA[i].harga << endl << endl;
                cout << "Lomba sudah diupdate" << endl;
                Sleep(3000);
                Sleep(2000);
                return;
                break;

            case 3:
                cout << endl;
                cout << "Maksimal Peserta : ";
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
                break;

            case 4:
                cout << endl;
                cout << "Biaya Lomba : ";
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
                break;

            case 5:
                return;
                break;

            default:
                goto editLomba;

            }
        }
    }
}
