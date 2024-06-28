#include <iostream>  //Sebagai standar input-output di c++ (cout cin)
#include <Windows.h> //menyediakan fungsi-fungsi untuk interaksi dengan sistem operasi Windows.
#include <iomanip>   //Mengatur beberapa aspek dari output, seperti lebar bidang, presisi, dll. (setw)
#include <fstream>   //Pembuatan file txt
#include <conio.h>   //Digunakan pada sistem Windows dan menyediakan fungsi-fungsi konsol.(getch)
#include <string>    //Penggunaan tipe data string


#include "menuAdmin.h"                 //Memanggil header
#include "userPage.h"
userPage uP;                            //Inisialisasi header
menuAdmin mA;

using namespace std; 

int pilih;                                  //Deklarasi Variabel Global
const string id = "admin";
const string pw = "admin";
string idLogin, pwLogin;

struct lomba {
    int maxPeserta;
    int harga;
    string nama;
    string spec;
};
lomba arrayLOMBA[100];

struct peserta {
    string namaTim;
    string nama1;
    string nama2;
    string nama3;
    string telpNo;
    string email;
    string lombaApa;
};
peserta arrayPSR[100];

int dataa, redeemku, redeemCode, i, j, k, bayar;

void adminPage()                      //Login
{
adPage:
    system("cls");
    cout << "===================================================================" << endl;
    cout << "                        Mekatronika Cup 2023                       " << endl;
    cout << "===================================================================" << endl;
    cout << "                           ID    : ";
    cin >> idLogin;
    cout << "                        Password : ";
    pwLogin = "";


    char ch;                     //Memasukan Password jadi * dan cek benar atau salah
    while (true)
    {
        ch = _getch();

        if (ch == 13)
            break;

        if (ch == 8)
        {
            if (!pwLogin.empty())
            {
                cout << "\b \b";
                pwLogin.pop_back();
            }
        }
        else
        {
            cout << '*';
            pwLogin += ch;
        }
    }

    if (idLogin == id && pwLogin == pw)
    {
        cout << endl;
        cout << "\nLOGIN SUKSES";
        Sleep(2000);
        mA.menuAdminCP();
    }
    else if (idLogin == "ADMIN" && pwLogin == "ADMIN")
    {
        cout << endl;
        cout << "\nLOGIN SUKSES";
        Sleep(2000);
        mA.menuAdminCP();
    }
    else
    {
        cout << "\n                         ID atau Password salah";
        Sleep(2000);
        return;
    }
}


int main()                     //menu utama
{


    system("color F0");
    system("cls");
    cout << "===================================================================" << endl;
    cout << "                        Mekatronika Cup 2023                       " << endl;
    cout << "===================================================================" << endl;
    cout << "                   1. Menu Pendaftaran (user)" << endl;
    cout << "                   2. Login Admin" << endl;
    cout << "                   3. Keluar" << endl;
    cout << "===================================================================" << endl << endl;
    cout << "Pilih : ";
    cin >> pilih;

    switch (pilih)
    {
    case 1:      //User
        system("cls");
        cout << "* Tata cara pendaftaran : *" << endl;
        cout << "1. Silahkan melakukan transaksi pembelian tiket lomba" << endl;
        cout << "2. Setelah sukses melakukan pembelian, silahkan mengisi formulir pendaftaran dengan menyertakan nomor tiket" << endl;
        Sleep(4000);
        uP.userPageCP();
        break;

    case 2:       //admin
        system("cls");
        adminPage();
        break;

    case 3:
        return 0;

    default:
        main();
    }

    main();
}