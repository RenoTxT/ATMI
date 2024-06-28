#include "lombaPage.h"

struct lomba {
    int maxPeserta;
    int harga;
    string nama;
    string spec;
};
extern lomba arrayLOMBA[];                                //Extern = mendeklarasi ulang variabel global
extern int dataa, bayar, redeemCode;

void lombaPage::lombaPageCP()
{
    ofstream myFile;
lombaPg:
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
    cout << endl;
    cout << "---------------------------------------------------------------------" << endl;
    cout << "K . Kembali" << endl << endl;
    cout << "Masukan Nama lomba yang akan di ikuti : ";
    cin >> cariLomba;
    if (cariLomba == "k" || cariLomba == "K")
    {
        return;
    }
    for (int i = 0; i < dataa; ++i) {
        if (arrayLOMBA[i].nama == cariLomba)
        {
            if (arrayLOMBA[i].maxPeserta > 0)                    //peraturan lomba
            {
                system("cls");
                cout << "===================================================================" << endl;
                cout << "                        Mekatronika Cup 2023                       " << endl;
                cout << "===================================================================" << endl;
                cout << "|                              " << setw(30) << arrayLOMBA[i].nama << "     |" << endl;
                cout << "===================================================================" << endl;
                cout << "Peraturan Lomba : " << endl;
                cout << "1. 1 Kelompok terdiri dari 3 orang Peserta" << endl;
                cout << "2. Peserta merupakan pelajar " << arrayLOMBA[i].spec << endl;
                cout << "3. Karya yang dilombakan merupakan karya asli dan tidak mengandung plagiarisme" << endl;
                cout << "4. Karya yang dilombakan belum pernah di publikasikan atau dilombakan. " << endl;
                cout << "5. Peserta wajib menaati peraturan yang ada" << endl;
                cout << "6. Bersedia membayar uang pendaftaran sebesar Rp " << arrayLOMBA[i].harga << endl;
                cout << "===============================" << endl << endl;
                cout << "Bayar sekarang ? (y/t) Rp " << arrayLOMBA[i].harga << endl;

            invoice:                                    //pembelian kode redeem
                cin >> yt;
                cout << endl;
                if (yt == 'Y' || yt == 'y') {
                    system("cls");
                    cout << "===================================================================" << endl;
                    cout << "                        Mekatronika Cup 2023                       " << endl;
                    cout << "===================================================================" << endl;
                    cout << "|                              " << setw(30) << arrayLOMBA[i].nama << "     |" << endl;
                    cout << "===================================================================" << endl << endl;
                    cout << "Bayar senilai Rp " << arrayLOMBA[i].harga << endl;

                    cout << "Bayar : Rp ";


                    cin >> bayar;
                    int kembali = bayar - arrayLOMBA[i].harga;
                    if (bayar >= arrayLOMBA[i].harga)
                    {
                        arrayLOMBA[i].maxPeserta = arrayLOMBA[i].maxPeserta - 1;
                        cout << endl << "Pembayaran Berhasil" << endl << endl;
                        cout << "Mohon Tunggu Sebentar" << endl;


                        Sleep(3000);

                        int minRange = (i + 1) * 1000;
                        int maxRange = (i + 2) * 1000 - 1;
                        redeemCode = generateRandomValue(minRange, maxRange); //membuat kode redeem setelah pembayaran

                        system("cls");
                        cout << "KODE REDEEM ANDA ADALAH : " << redeemCode << endl;
                        cout << "KODE INI DIGUNAKAN UNTUK MELAKUKAN PENGISIAN FORMULIR" << endl << endl;
                        cout << "*MOHON MENGINGAT KODE REDEEM YANG SUDAH DIBERIKAN, KARNA KAMI TIDAK AKAN MEMBERIKAN KODE REDEEM KEDUA KALINYA*" << endl << endl;

                        cout << " * Tata cara pendaftaran : *" << endl;
                        cout << "1. Silahkan melakukan transaksi pembelian tiket lomba" << endl;
                        cout << "2. Setelah sukses melakukan pembelian, silahkan mengisi formulir pendaftaran dengan menyertakan kode reedem" << endl << endl;
                        Sleep(1000);
                        cout << "Mencetak Struct Pembayaran" << endl;

                        string redeemcodest = to_string(redeemCode);

                        myFile.open(redeemcodest + " Nota Bayar.txt", std::ios::trunc);
                        myFile << fixed << setprecision(2);                              //Cetak nota untuk user, terdapat redeeem code

                        myFile << "---------------------------------------------" << endl;
                        myFile << "         ---MEKATRONIKA CUP 2023---               " << endl;
                        myFile << "               NOTA PEMBAYARAN                " << endl;
                        myFile << "---------------------------------------------" << endl;
                        myFile << "Pembayaran Lomba  : " << arrayLOMBA[i].nama << " - " << arrayLOMBA[i].spec << endl << endl;
                        myFile << "=============================================" << endl;
                        myFile << "Detail Pembayaran :" << endl;
                        myFile << setw(20) << "Biaya Pendaftaran: " << setw(20) << arrayLOMBA[i].harga << " IDR" << endl;
                        myFile << setw(20) << "Yang Dibayarkan: " << setw(20) << bayar << " IDR" << endl;
                        myFile << setw(20) << "Kembali: " << setw(20) << kembali << " IDR" << endl << endl;
                        myFile << "=============================================" << endl;
                        myFile << "NO REDEEM: " << redeemCode << "          ";

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

                        while (1) {
                            key = _getch();

                            if (key == ' ') {
                                return;
                                break;
                            }
                        }

                        cin >> pilih;
                    }

                    else if (bayar < arrayLOMBA[i].harga)
                    {
                        cout << endl << "Pembayaran gagal" << endl;
                        cout << "Saldo tidak mencukupi" << endl;               //Bayar kurang
                        cout << "Isi saldo dan coba kembali lagi" << endl << endl;
                        Sleep(3000);
                        cout << "coba lagi? (y/t)" << endl;
                        cin >> yt;
                        if (yt == 'Y' || yt == 'y') {
                            system("cls");
                            goto lombaPg;
                        }
                        else
                        {
                            return;
                        }



                    }


                }
                else if (yt == 'T' || yt == 't') {
                    return;
                }


            }
            else
            {
                system("cls");            //SLOT PENUH
                cout << endl << "Mohon maaf slot lomba sudah terpenuhi, coba lagi di tahun depan" << endl;
                Sleep(3000);
            }
        }
    }

}
