// Header Program
#include "editLomba.h"
#include <iostream>
#include <limits>
#include <string>

// Statement untuk mengakses identifier
using namespace std;

//Definisi Variabel dalam Structure
struct lomba {
    int maxPeserta;
    int harga;
    string nama;
    string spec;
};

// Extern = mendeklarasi ulang variabel yang berada di Source.CPP
extern lomba arrayLOMBA[];
extern int dataa;

//Fungsi untuk mengubah-ubah lomba dari nama, kategori, maksimal peserta, harga
void editLomba::editLombaCP()
{
editLomba:
    cout << "Masukan Nama lomba yang akan di edit : ";

    // untuk membaca keseluruhan baris berserta spasinya
    getline(cin >> ws, cariLomba);

    //Proses penggantian data sesuai dengan yang dipilih
    for (int i = 0; i < dataa; ++i) 
    {
        if (arrayLOMBA[i].nama == cariLomba) 
        {
            system("cls");
            cout << "Mau edit yang mana ? (1-5)" << endl << endl;
            cout << "1. Nama             :" << arrayLOMBA[i].nama << endl;
            cout << "2. Kategori         :" << arrayLOMBA[i].spec << endl;
            cout << "3. Maksimal Peserta :" << arrayLOMBA[i].maxPeserta << endl;
            cout << "4. Biaya Lomba      :" << arrayLOMBA[i].harga << endl;
            cout << "5. Keluar" << endl;
            cout << "Pilih : ";
            cin >> pilih;

            // Pembagian dari masing-masing pilihan
            switch (pilih) {
            case 1: //Mengganti nama
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

            case 2: //Mengganti kategori
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

            case 3: //Mengganti Maksimal Peserta
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

            case 4: //Mengganti harga lomba
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
