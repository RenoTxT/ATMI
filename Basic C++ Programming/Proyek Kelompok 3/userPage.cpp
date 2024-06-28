// Header Program
#include "userPage.h"
#include "lombaPage.h"
#include "isiFormulir.h"

//Definisi class dengan nama
lombaPage lP;
isiFormulir iF;

//Fungsi untuk userpage
void userPage::userPageCP()
{                                          //Menu utama user
usPage:
    system("cls");
    cout << "===================================================================" << endl;
    cout << "                         BAR COMPETITION 24'                       " << endl;
    cout << "===================================================================" << endl;
    cout << "                           1. Daftar Lomba                         " << endl;
    cout << "                           2. Isi Formulir                         " << endl;
    cout << "                           3. Kembali                              " << endl;
    cout << "===================================================================" << endl << endl;
    cout << "Pilih : ";
    cin >> pilih;

    switch (pilih)
    {

     //Membeli kode redeem / Mendaftar lomba
    case 1:
        system("cls");       
        lP.lombaPageCP();
        goto usPage;
        break;

     //Mengisi formulir
    case 2:
        system("cls");
        iF.isiFormulirCP();     
        goto usPage;
        break;

    case 3:
        system("cls");
        return;
        break;
    }
}
