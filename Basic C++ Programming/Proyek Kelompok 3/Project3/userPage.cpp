#include "userPage.h"
#include "lombaPage.h"
#include "isiFormulir.h"

lombaPage lP;
isiFormulir iF;

void userPage::userPageCP()
{                                          //Menu utama user
usPage:
    system("cls");
    cout << "===================================================================" << endl;
    cout << "                        Mekatro 55                                 " << endl;
    cout << "===================================================================" << endl;
    cout << "                           1. Daftar Lomba                         " << endl;
    cout << "                           2. Isi Formulir                         " << endl;
    cout << "                           3. Kembali                              " << endl;
    cout << "===================================================================" << endl << endl;
    cout << "Pilih : ";
    cin >> pilih;

    switch (pilih)
    {
    case 1:
        system("cls");       //Membeli kode redeem
        lP.lombaPageCP();
        goto usPage;
        break;

    case 2:
        system("cls");
        iF.isiFormulirCP();     //Mengisi formulir
        goto usPage;
        break;

    case 3:
        system("cls");
        return;
        break;
    }
}
