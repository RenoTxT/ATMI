#include "adminEdit.h"

struct tiketing {
    string tujuan;
    int jumlah_kursi = 0;
    string tanggal;
    string waktu;
    double harga = 0;
};

extern tiketing arrayTIKETING[];
extern int dataa, i;

int pilihData;
string cariData;

void adminEdit::adminEditCP() {


    cout << "===============================================================================================" << endl;
    cout << "                                           Mekatronika Cup 2023                        " << endl;
    cout << "===============================================================================================" << endl;
    cout << "|     TUJUAN     " << "|    JUMLAH KURSI     " << "|     TANGGAL     " << "|     WAKTU     " << "|     HARGA      " << "|" << endl;
    cout << "-----------------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < dataa; ++i)
    {
        cout << "|" << left << setw(16) << arrayTIKETING[i].tujuan << "|     " << setw(15) << arrayTIKETING[i].jumlah_kursi << "|" << setw(15) << arrayTIKETING[i].tanggal << "  |" << setw(15) << arrayTIKETING[i].waktu << "  |" << setw(15) << arrayTIKETING[i].harga <<"k" << "  |";
        cout << endl;
    }
    cout << endl;
    cout << "---------------------------------------------------------------------" << endl;
    cout << "Masukan Tujuan Kereta yang akan diedit\t: ";
    cin >> cariData;
    for (int i = 0; i < dataa; ++i) {
        if (arrayTIKETING[i].tujuan == cariData) {
            system("cls");
            cout << "Mau edit yang mana ? (1-5)" << endl << endl;
            cout << "1. Tujuan\t:" << arrayTIKETING[i].tujuan << endl;
            cout << "2. Jumlah Kursi\t: " << arrayTIKETING[i].jumlah_kursi << endl;
            cout << "3. Tanggal\t: " << arrayTIKETING[i].tanggal << endl;
            cout << "4. Waktu\t: " << arrayTIKETING[i].waktu << endl;
            cout << "5. Harga\t: " << arrayTIKETING[i].harga << endl;
            cout << "6. Keluar" << endl;
            cout << "Pilih : ";
            cin >> pilihData;
            switch (pilihData)
            {
            case 1:                                           //mengubah yang apa ni?
                cout << endl;
                cout << "Tujuan\t: ";
                cin >> arrayTIKETING[i].tujuan;
                system("cls");
                cout << "1. Tujuan\t:" << arrayTIKETING[i].tujuan << endl;
                cout << "2. Jumlah Kursi\t: " << arrayTIKETING[i].jumlah_kursi << endl;
                cout << "3. Tanggal\t: " << arrayTIKETING[i].tanggal << endl;
                cout << "4. Waktu\t: " << arrayTIKETING[i].waktu << endl;
                cout << "5. Harga\t: " << arrayTIKETING[i].harga << endl;
                cout << "Data sudah diupdate" << endl;
                Sleep(3000);
                Sleep(2000);
                break;

            case 2:
                cout << endl;
                cout << "Jumlah Kursi\t: ";
                cin >> arrayTIKETING[i].jumlah_kursi;
                system("cls");
                cout << "1. Tujuan\t:" << arrayTIKETING[i].tujuan << endl;
                cout << "2. Jumlah Kursi\t: " << arrayTIKETING[i].jumlah_kursi << endl;
                cout << "3. Tanggal\t: " << arrayTIKETING[i].tanggal << endl;
                cout << "4. Waktu\t: " << arrayTIKETING[i].waktu << endl;
                cout << "5. Harga\t: " << arrayTIKETING[i].harga << endl;
                cout << "Data sudah diupdate" << endl;
                Sleep(2000);
                return;

            case 3:
                cout << endl;
                cout << "Tanggal\t: ";
                getline(cin, arrayTIKETING[i].tanggal);
                system("cls");
                cout << "1. Tujuan\t:" << arrayTIKETING[i].tujuan << endl;
                cout << "2. Jumlah Kursi\t: " << arrayTIKETING[i].jumlah_kursi << endl;
                cout << "3. Tanggal\t: " << arrayTIKETING[i].tanggal << endl;
                cout << "4. Waktu\t: " << arrayTIKETING[i].waktu << endl;
                cout << "5. Harga\t: " << arrayTIKETING[i].harga << endl;
                cout << "Data sudah diupdate" << endl;
                Sleep(2000);
                return;

            case 4:
                cout << endl;
                cout << "Waktu\t: ";
                getline(cin,arrayTIKETING[i].waktu);
                system("cls");
                cout << "1. Tujuan\t:" << arrayTIKETING[i].tujuan << endl;
                cout << "2. Jumlah Kursi\t: " << arrayTIKETING[i].jumlah_kursi << endl;
                cout << "3. Tanggal\t: " << arrayTIKETING[i].tanggal << endl;
                cout << "4. Waktu\t: " << arrayTIKETING[i].waktu << endl;
                cout << "5. Harga\t: " << arrayTIKETING[i].harga << endl;
                cout << "Data sudah diupdate" << endl;
                Sleep(2000);
                return;
            case 5:
                cout << endl;
                cout << "Harga\t: ";
                cin >> arrayTIKETING[i].harga;
                system("cls");
                cout << "1. Tujuan\t:" << arrayTIKETING[i].tujuan << endl;
                cout << "2. Jumlah Kursi\t: " << arrayTIKETING[i].jumlah_kursi << endl;
                cout << "3. Tanggal\t: " << arrayTIKETING[i].tanggal << endl;
                cout << "4. Waktu\t: " << arrayTIKETING[i].waktu << endl;
                cout << "5. Harga\t: " << arrayTIKETING[i].harga << endl;
                cout << "Data sudah diupdate" << endl;
                Sleep(2000);
                return;
            case 6:
                return;

            default:
                cout << "Invalid input, mohon masukan dengan benar!" << endl;
                Sleep(3000);
                system("cls");
                adminEditCP();
            }
        }
        else {
            cout << "data tidak ditemukan" << endl;
            system("cls");
        }
    }
}