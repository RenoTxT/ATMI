//Header Program
#include "lombaPage.h"

// Definisi variabel ke dalam Structure
struct lomba {
    int maxPeserta;
    int harga;
    string nama;
    string spec;
};
//Extern = mmendeklarasi ulang variabel yang berada di Source.CPP
extern lomba arrayLOMBA[];                                
extern int dataa, bayar, redeemCode;

// Fungsi untuk menampilkan halaman lomba
void lombaPage::lombaPageCP()
{
    // Perintah untuk menuliskan form pada file myFile
    ofstream myFile;
lombaPg:
    system("cls");
    cout << "=====================================================================" << endl;
    cout << "                          BAR COMPETITION 24'                        " << endl;
    cout << "=====================================================================" << endl;
    cout << "---------------------------------------------------------------------" << endl;

    cout << "|            LOMBA" << "           |     KATEGORI" << "     |       HARGA" << "       |" << endl;
    cout << "---------------------------------------------------------------------" << endl;

    //Menampilkan hasil pengisian data ke dalam arrayLomba
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
            //Menampilkan peraturan lomba
            if (arrayLOMBA[i].maxPeserta > 0)                    
            {
                system("cls");
                cout << "===================================================================" << endl;
                cout << "                         BAR COMPETITION 24'                       " << endl;
                cout << "===================================================================" << endl;
                cout << "|                              " << setw(30) << arrayLOMBA[i].nama << "     |" << endl;
                cout << "===================================================================" << endl;
                cout << "Peraturan Lomba : " << endl;
                cout << "1. 1 Kelompok terdiri dari 3 orang Peserta" << endl;
                cout << "2. Peserta merupakan pelajar " << arrayLOMBA[i].spec << endl;
                cout << "3. Karya yang dilombakan merupakan karya asli dan tidak mengandung plagiarisme" << endl;
                cout << "4. Karya yang dilombakan belum pernah di publikasikan atau dilombakan. " << endl;
                cout << "5. Peserta wajib menaati syarat dan ketentuan" << endl;
                cout << "6. Bersedia membayar uang pendaftaran sebesar Rp " << arrayLOMBA[i].harga << endl;
                cout << "===============================" << endl << endl;
                cout << "Bayar sekarang ? (y/t) Rp " << arrayLOMBA[i].harga << endl;

                //Transaksi kode redeem
            invoice:                                    
                cin >> yt;
                cout << endl;
                if (yt == 'Y' || yt == 'y') {
                    system("cls");
                    cout << "===================================================================" << endl;
                    cout << "                         BAR COMPETITION 24'                       " << endl;
                    cout << "===================================================================" << endl;
                    cout << "|                              " << setw(30) << arrayLOMBA[i].nama << "     |" << endl;
                    cout << "===================================================================" << endl << endl;
                    cout << "Tagihan Rp " << arrayLOMBA[i].harga << endl;
                    cout << "Bayar : Rp ";
                    cin >> bayar;

                    //proses perhitungan kembalian uang
                    int kembali = bayar - arrayLOMBA[i].harga;
                    //Statement jika pembayaran berhasil
                    if (bayar >= arrayLOMBA[i].harga)
                    {
                        arrayLOMBA[i].maxPeserta = arrayLOMBA[i].maxPeserta - 1;
                        cout << endl << "Pembayaran Berhasil" << endl << endl;
                        cout << "Mohon Tunggu Sebentar" << endl;


                        Sleep(3000);
                        //membuat kode redeem setelah pembayaran
                        int minRange = (i + 1) * 1000;
                        int maxRange = (i + 2) * 1000 - 1;
                        redeemCode = generateRandomValue(minRange, maxRange); 

                        system("cls");
                        cout << "KODE REDEEM ANDA ADALAH : " << redeemCode << endl << endl;
                        cout << "KODE INI DIGUNAKAN UNTUK MELAKUKAN PENGISIAN FORMULIR" << endl << endl;
                        cout << "*MOHON MENGINGAT KODE REDEEM YANG SUDAH DIBERIKAN, KARNA KAMI TIDAK AKAN MEMBERIKAN KODE REDEEM KEDUA KALINYA*" << endl << endl;

                        cout << " * Tata cara pendaftaran : *" << endl;
                        cout << "1. Silahkan melakukan transaksi pembelian tiket lomba" << endl;
                        cout << "2. Setelah sukses melakukan pembelian, silahkan mengisi formulir pendaftaran dengan menyertakan kode reedem" << endl << endl;
                        Sleep(1800);
                        cout << "Mencetak Struk]] Pembayaran" << endl;

                        //Proses pencetakan struk pembayaran
                        string redeemcodest = to_string(redeemCode);
                        //Menuliskan nota ke file Nota Bayar.txt dideppannya tertampil kode redeem pada nama File
                        myFile.open(redeemcodest + " Nota Bayar.txt", std::ios::trunc);
                        myFile << fixed << setprecision(2);                          
                        //Isi struk pembayaran yang dicetak
                        myFile << "---------------------------------------------" << endl;
                        myFile << "          --- BAR COMPETITION 24'---         " << endl;
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

                        //Program pengambilan waktu
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
                    //Statement jika pembayran gagal
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
            //statement jika slot pendaftaran penuh
            else
            {
                system("cls");      
                cout << endl << "Mohon maaf slot lomba sudah terpenuhi, coba lagi di tahun depan" << endl;
                Sleep(3000);
            }
        }
    }

}
