#include "userPage.h"
#include "titlePage.h"
#include "systemPage.h"

struct tiketing {
	string tujuan;
	int jumlah_kursi = 0;
	string tanggal;
	string waktu;
	double harga = 0;
};
extern tiketing arrayTIKETING[100];
extern int beli_tiket;
double harga_diskon;
titlePage tpU;
systemPage spU;

char pilih;
char yt;
extern string combination[100];
double harga_benar;
extern int dataa, i;
extern int kondisi, arraygabunganint;
string cariLomba;
char key;
int jumlah_tiket_dibeli, bayar;

int systemBeli() {
    menuTiket:
    //title page

    //.title page

    cout << "ingin membeli berapa?" << endl << "Jumlah\t: ";
    cin >> jumlah_tiket_dibeli;

    if (jumlah_tiket_dibeli < 3) {
        cout << "jumlah tiket pembelian minimal 3!" << endl;
        systemBeli();
    }
    else {
        ofstream myFile;
        system("cls");
        cout << "=====================================================================" << endl;
        cout << "                         TOKO YGGDRASIL                        " << endl;
        cout << "=====================================================================" << endl;
        cout << "---------------------------------------------------------------------" << endl;

        cout << "|            TUJUAN" << "           |     TANGGAL" << "     |       HARGA" << "       |" <<"k" << endl;
        cout << "---------------------------------------------------------------------" << endl;

        for (int i = 0; i < dataa; ++i)
        {
            cout << "|" << left << setw(28) << arrayTIKETING[i].tujuan << "|      " << setw(12) << arrayTIKETING[i].tanggal << "|       " << setw(10) << arrayTIKETING[i].harga << "  |";
            cout << endl;
        }
        cout << endl;
        cout << "---------------------------------------------------------------------" << endl;
        cout << "K . Kembali" << endl << endl;
        cout << "Masukan tujuan yang akan di ikuti : ";
        cin >> cariLomba;
        if (cariLomba == "k" || cariLomba == "K")
        {
            goto menuTiket;
        }
        for (int i = 0; i < dataa; ++i) {
            if (arrayTIKETING[i].tujuan == cariLomba)
            {
                if (arrayTIKETING[i].jumlah_kursi > 0)                    //peraturan lomba
                {
                    system("cls");
                    cout << "===================================================================" << endl;
                    cout << "                        TOKO YGGRASIL                       " << endl;
                    cout << "===================================================================" << endl;
                    cout << "|                              " << setw(30) << arrayTIKETING[i].tujuan << "     |" << endl;
                    cout << "===================================================================" << endl;
                    cout << "Hasil Pembelian\t: " << endl;
                    cout << "Tujuan\t\t: " << arrayTIKETING[i].tujuan<< endl;
                    cout << "Tanggal\t\t: " << arrayTIKETING[i].tanggal<<endl;
                    cout << "Waktu\t\t: " << arrayTIKETING[i].waktu<<endl;
                    cout << "Harga\t\t: " << arrayTIKETING[i].harga<<"k" << endl;
                    cout << "Jumlah Tiket\t: " << jumlah_tiket_dibeli<< endl;
                    cout << "===============================" << endl << endl;
                    cout << "Bayar sekarang ? (y/t) Rp " << arrayTIKETING[i].harga*jumlah_tiket_dibeli <<"k" << endl;

                invoice:                                    //pembelian kode redeem
                    cin >> yt;
                    cout << endl;
                    if (yt == 'Y' || yt == 'y') {
                        system("cls");
                        cout << "===================================================================" << endl;
                        cout << "                        TOKO YGGDRASIL                       " << endl;
                        cout << "===================================================================" << endl;
                        cout << "|                              " << setw(30) << arrayTIKETING[i].tujuan << "     |" << endl;
                        cout << "===================================================================" << endl << endl;
                        if (arrayTIKETING[i].harga * jumlah_tiket_dibeli > 500) {
                            harga_diskon = (arrayTIKETING[i].harga * jumlah_tiket_dibeli)/2;
                            cout << "Diskon Rp " << harga_diskon << "k" << endl;
                            cout << "Bayar senilai Rp " << (arrayTIKETING[i].harga * jumlah_tiket_dibeli) - harga_diskon<< "k" << endl;
                            harga_benar = (arrayTIKETING[i].harga * jumlah_tiket_dibeli) - harga_diskon;
                        }
                        else {
                            harga_diskon = 0;
                            cout << "Bayar senilai Rp " << arrayTIKETING[i].harga * jumlah_tiket_dibeli << "k" << endl;
                            harga_benar = arrayTIKETING[i].harga * jumlah_tiket_dibeli;
                        }
                        
                        cout << "Bayar : Rp "<<"k";
                        cin >> bayar;
                        int kembali = bayar - harga_benar;
                        if (bayar >= harga_benar)
                        {
                            beli_tiket = jumlah_tiket_dibeli;
                            arrayTIKETING[i].jumlah_kursi = arrayTIKETING[i].jumlah_kursi - jumlah_tiket_dibeli;
                            cout << endl << "Pembayaran Berhasil" << endl << endl;
                            cout << "Mohon Tunggu Sebentar" << endl;


                            Sleep(3000);
                            cout << "Mencetak Struct Pembayaran" << endl;


                            myFile.open(" Nota Bayar.txt", std::ios::trunc);
                            myFile << fixed << setprecision(2);                            //Cetak nota untuk user, terdapat redeeem code

                            myFile << "---------------------------------------------" << endl;
                            myFile << "         ---TOKO YGGDRASIL---               " << endl;
                            myFile << "               NOTA PEMBAYARAN                " << endl;
                            myFile << "---------------------------------------------" << endl;
                            myFile << "Pembayaran Tiket  : " << arrayTIKETING[i].tujuan << " - " << arrayTIKETING[i].tanggal << endl << endl;
                            myFile << "=============================================" << endl;
                            myFile << "Detail Pembayaran :" << endl;
                            myFile << setw(20) << "Biaya: " << setw(20) << harga_benar << " k" << endl;
                            myFile << setw(20) << "Yang Dibayarkan: " << setw(20) << bayar << " k" << endl;
                            myFile << setw(20) << "Kembali: " << setw(20) << kembali << " k" << endl << endl;

                            time_t rawTime;
                            time(&rawTime);
                            struct tm timeInfo;
                            localtime_s(&timeInfo, &rawTime);
                            char buffer[80];
                            strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &timeInfo);
                            myFile << buffer << std::endl;

                            myFile << "---------------------------------------------" << std::endl;

                            myFile.close();
                            Sleep(3000);

                            cout << "Press Space to Continue...";

                                    break;
                              
                            cin >> pilih;
                        }

                        else if (bayar < harga_benar)
                        {
                            cout << endl << "Pembayaran gagal" << endl;
                            cout << "Saldo tidak mencukupi" << endl;               //Bayar kurang
                            cout << "Isi saldo dan coba kembali lagi" << endl << endl;
                            Sleep(3000);
                            cout << "coba lagi? (y/t)" << endl;
                            cin >> yt;
                            if (yt == 'Y' || yt == 'y') {
                                system("cls");
                                goto menuTiket;
                            }
                            else
                            {
                                goto menuTiket;
                            }



                        }


                    }
                    else if (yt == 'T' || yt == 't') {
                        goto menuTiket;
                    }


                }
                else
                {
                    system("cls");            //SLOT PENUH
                    cout << endl << "Mohon maaf kursi telah penuh" << endl;
                    Sleep(3000);
                }
            }
        }
    }
	return 0;
}

void userPage::userPageCP() {
	tpU.titleUserCP();
	spU.systemMenuUserCP();
	cin >> pilih;
	switch (pilih) {
	case 1:
		systemBeli();
		break;
	case 2:
		return;
	default:
		cout << "invalid input, mohon masukan pilihan yang tersedia" << endl;
		system("cls");
		Sleep(3000);
		userPageCP();
	}
}


