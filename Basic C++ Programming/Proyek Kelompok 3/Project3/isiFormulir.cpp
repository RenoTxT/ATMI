#include "isiFormulir.h"

struct lomba {
    int maxPeserta;
    int harga;
    string nama;
    string spec;
};
extern lomba arrayLOMBA[];
extern int dataa, redeemku, redeemCode, j, k;            //Extern = mendeklarasi ulang variabel global

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
extern peserta arrayPSR[];


void isiFormulir::isiFormulirCP()
{
    ofstream myFile;
isiForm:
    system("cls");
    cout << "Pastikan kamu sudah membeli kode redeem dan mempunyai kodenya";
    Sleep(2000);
    system("cls");

    cout << "=====================================================================" << endl;
    cout << "                         Mekatronika Cup 2023                        " << endl;
    cout << "=====================================================================" << endl;
    cout << "---------------------------------------------------------------------" << endl;

    cout << "|            LOMBA" << "           |     KATEGORI" << "     |       HARGA" << "       |" << endl;
    cout << "---------------------------------------------------------------------" << endl;

    for (int i = 0; i < dataa; ++i)
    {
        cout << "|" << left << setw(28) << arrayLOMBA[i].nama << "|      " << setw(12) << arrayLOMBA[i].spec << "|       " << setw(10) << arrayLOMBA[i].harga << "  |";
        cout << endl;
    }
    cout << "---------------------------------------------------------------------" << endl;
    cout << "K . Kembali" << endl << endl;
    cout << "Mau mendaftar lomba apa? : ";
    cin >> cariLomba;                                                   // menccari lomba yang akan di daftar
    if (cariLomba == "k" || cariLomba == "K")
    {
        return;
    }

    for (int i = 0; i < dataa; ++i) {
        if (arrayLOMBA[i].nama == cariLomba) {
            system("cls");
            cout << "Masukan kode redeem : ";
            cin >> redeemku;
            system("cls");
            if (redeemku == redeemCode && redeemku < (((i + 2) * 1000) - 1) && redeemku >(i + 1) * 1000)
            {
                cout << "ISINYA PELAN PELAN YAH, DATA GA BISA DI UBAH";
                Sleep(3000);
                system("cls");
                cout << "===================================================================" << endl;
                cout << "                        Mekatronika Cup 2023                       " << endl;
                cout << "===================================================================" << endl;
                cout << "|                              " << setw(30) << arrayLOMBA[i].nama << "     |" << endl;
                cout << "===================================================================" << endl;
                cout << "Nama Tim                 : ";
                cin >> arrayPSR[k].namaTim;
                cout << "Nama Sekolah             : ";                      //memasukan data peserta lomba
                cin >> arrayPSR[k].sekolah;
                cout << "Nama Peserta 1           : ";
                cin >> arrayPSR[k].nama1;
                cout << "Nama Peserta 2           : ";
                cin >> arrayPSR[k].nama2;
                cout << "Nama Peserta 3           : ";
                cin >> arrayPSR[k].nama3;
                cout << "Nomor Telepon (wakil)    : ";
                cin >> arrayPSR[k].telponNo;
                cout << "Alamat email (wakil)     : ";
                cin >> arrayPSR[k].email;
                arrayPSR[k].lombaApa = arrayLOMBA[i].nama;

                myFile.open(arrayPSR[k].lombaApa + "-" + arrayPSR[k].namaTim + " data.txt", ios::trunc);
                myFile << "---------------------------------------------" << endl;
                myFile << "           --MEKATRONIKA CUP 2023--          " << endl;
                myFile << "                 DATA PESERTA                " << endl;           //print data peserta untuk admin
                myFile << "---------------------------------------------" << endl;
                myFile << left << setw(20) << "Lomba               :   " << setw(23) << arrayPSR[k].lombaApa << endl;
                myFile << left << setw(20) << "Nama Tim            :   " << setw(23) << arrayPSR[k].namaTim << endl;
                myFile << left << setw(20) << "Nama Sekolah        :   " << setw(23) << arrayPSR[k].sekolah << endl;
                myFile << left << setw(20) << "Nomor Telepon       :   " << setw(23) << arrayPSR[k].telponNo << endl;
                myFile << left << setw(20) << "Alamat Email        :   " << setw(23) << arrayPSR[k].email << endl;
                myFile << left << setw(20) << "Nama Peserta 1      :   " << setw(23) << arrayPSR[k].nama1 << endl;
                myFile << left << setw(20) << "Nama Peserta 2      :   " << setw(23) << arrayPSR[k].nama2 << endl;
                myFile << left << setw(20) << "Nama Peserta 3      :   " << setw(23) << arrayPSR[k].nama3 << endl << endl;

                time_t rawTime;
                time(&rawTime);
                struct tm timeInfo;
                localtime_s(&timeInfo, &rawTime);
                char buffer[80];
                strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &timeInfo);
                myFile << "\t     " << buffer << endl;
                myFile << "-----------------------------------------------" << endl;
                myFile.close();


                cout << "Press space to continue..";
                while (1) {
                    key = _getch();

                    if (key == ' ') {
                        k++;
                        j++;
                        redeemCode = 0123;
                        goto akhir;
                        break;
                    }
                }

            }

            else
            {
                cout << "Kode Redeem atau Pemilihan Lomba Salah!" << endl;
                cout << "Pastikan Kode Redeem dan Pemilihan Lomba Benar!" << endl;
                Sleep(3000);
                return;
            }
        }
    }
akhir:
    cout << endl << "Data Terkirim.";
    Sleep(2000);
    return;

}