#include "PaintBallReservation.h"
#include <fstream>
#include <sstream>

using namespace std;


void PaintBalldReservation::login()
{
    cout << "====================================" << endl;
    cout << "|           WELCOME TO             |" << endl;
    cout << "|     PaintBall Battle Ground      |" << endl;
    cout << "|    Politeknik ATMI Surakarta     |" << endl;
    cout << "====================================" << endl;
    cout << "|--------------Login---------------|" << endl;
    cout << "|_Username: ";
    string username;
    cin >> username;

    cout << "|_Password: ";
    string password = getHiddenInput();

    if (isAdmin(username, password)) {
        system("cls");
        adminMenu();
    }
    else if (isUser(username, password)) {
        system("cls");
        userMenu();
    }
    else {
        system("cls");
        cout << "Login gagal. Username atau password salah. Coba lagi" << endl;
        Sleep(2000);
        system("cls");
        login();
    }

}

bool PaintBalldReservation::isAdmin(const string& username, const string& password)
{
    return (username == "admin" && password == admin.password);
}

bool PaintBalldReservation::isUser(const string& username, const string& password)
{
    for (const user& user : users) //const User& user: Mendeklarasikan variabel user yang bertipe const User&. Ini adalah loop berbasis rentang (range-based loop) yang digunakan untuk mengiterasi melalui setiap elemen dalam vector users. const menunjukkan bahwa variabel user tidak dapat diubah nilainya selama iterasi.
        //: users : Menunjukkan bahwa loop akan melakukan iterasi terhadap setiap elemen dalam vector users.
    {
        if (user.username == username && user.password == password) {
            return true;
        }
    }
    return false;
}

void PaintBalldReservation::adminMenu()
{
int choice;
do {
    system("cls");
    cout << "  =======================================" << endl;
    cout << "  =========== ADMIN INTERFACE ===========" << endl;
    cout << "  =======================================" << endl;
    cout << "  | 1. Data Menu                        |\n";
    cout << "  |-------------------------------------|" << endl;
    cout << "  | 2. Mendaftarkan Pelanggan               |\n";
    cout << "  |-------------------------------------|" << endl;
    cout << "  | 3. Melihat Daftar Pelanggan         |\n";
    cout << "  |-------------------------------------|" << endl;
    cout << "  | 4. Lihat dan Print Stok Kelas       |\n";
    cout << "  |-------------------------------------|" << endl;
    cout << "  | 5. Melihat Status Kelas             |\n";
    cout << "  |-------------------------------------|" << endl;
    cout << "  | 6. Hapus Pemesanan                  |\n";
    cout << "  |-------------------------------------|" << endl;
    cout << "  | 0. Keluar                           |\n";
    cout << "  =======================================\n" << endl << endl;
    cout << "Pilih menu: ";
    cin >> choice;

    switch (choice) {
    case 1:
        system("cls");
        editDataMenu(); 
        break;
    case 2:
        system("cls");
        registerUser();
        break;
    case 3:
        system("cls");
        lihatDaftarUser(); 
        break;
    case 4:
        system("cls");
        lihatPrintStokKelas();
        break;
    case 5:
        system("cls");
        lihatStatusPemesanan();
        break;
    case 6:
        system("cls");
        hapusPemesanan();
        break;
    case 0:
        system("cls");
        login();
        break;
    }

} while (choice != 0);
}

void PaintBalldReservation::userMenu()
{
    system("cls");
    int choice;
    do {
        cout << "  ======================================" << endl;
        cout << "  ==== Customer or Member Interface ====" << endl;
        cout << "  ======================================" << endl;
        cout << "  | 1. Melihat Stok kelas              |\n";
        cout << "  |------------------------------------|" << endl;
        cout << "  | 2. Memesan kelas                   |\n";
        cout << "  |------------------------------------|" << endl;
        cout << "  | 0. Keluar                          |\n";
        cout << "  |------------------------------------|" << endl;
        cout << "  ======================================" << endl;
        cout << "Pilih menu: ";
        cin >> choice;

        switch (choice) {
        case 1:
            system("cls");
            lihatStokKelas();
            break;
        case 2:
            system("cls");
            pesanKelas();
            break;
        case 0:
            system("cls");
            login();
            break;
        }
    } while (choice != 0);
}

void PaintBalldReservation::registerUser()
{
    cout << "  ======================================" << endl;
    cout << "  =            Mendaftarkan            =" << endl;
    cout << "  =    Customer or Member Interface    =" << endl;
    cout << "  ======================================" << endl;
    string username, password;
    cout << "Masukkan username baru: ";
    cin >> username;

    cout << "Masukkan password baru: ";
    cin >> password;

    users.push_back(user(username, password));
    cout << endl << endl;
    cout << "User berhasil didaftarkan." << endl;
    Sleep(1000);
    system("cls");
}

void PaintBalldReservation::editDataMenu()
{

    //  pengeditan data menu oleh admin
    cout << "  ======================================" << endl;
    cout << "  =            Paket  Kelas            =" << endl;
    cout << "  =       PaintBall Battle Ground      =" << endl;
    cout << "  =      Politeknik ATMI Surakarta     =" << endl;
    cout << "  ======================================" << endl;
    cout << "001 . KELAS REGULER " << endl;
    cout << "Fasilitas :  " << endl;
    cout << "Berapa fasilitas? = ";
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> fasilitasReg[i];
    }
    cout << "========================================" << endl;
    cout << endl;

    cout << "002 . KELAS GOLD " << endl;
    cout << "Fasilitas :  " << endl;
    cout << "Berapa fasilitas? = ";
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> fasilitasGold[i];
    }
    cout << "========================================" << endl;
    cout << endl;

    cout << "003 . KELAS PREMIUM " << endl;
    cout << "Fasilitas :  " << endl;
    cout << "Berapa fasilitas? = ";
    cin >> n;
    for (int i = 0; i < n; ++i) {

        cin >> fasilitasPrem[i];
    }
    cout << "========================================" << endl;
    cout << endl;


    cout << "========================================" << endl;
    cout << "-          List Harga Bermain          -" << endl;
    cout << "-        PaintBall Battle Ground       -" << endl;
    cout << "-       Politeknik ATMI Surakarta      -" << endl;
    cout << "========================================" << endl;
    cout << "KELAS REGULER perjam = Rp  ";
    cin >> hargaReguler;
    cout << "=--------------------------------------=" << endl;
    cout << "KELAS GOLD    perjam = Rp  ";
    cin >> hargaGold;
    cout << "=--------------------------------------=" << endl;
    cout << "KELAS PREMIUM perjam = Rp  ";
    cin >> hargaPremium;
    cout << "========================================" << endl;
    cout << endl;
    cout << "========================================" << endl;
    cout << "-          Stok Kelas Bermain          -" << endl;
    cout << "-        PaintBall Battle Ground       -" << endl;
    cout << "-       Politeknik ATMI Surakarta      -" << endl;
    cout << "========================================" << endl;
    cout << "Stok Kelas Reguler: ";
    cin >> stokReguler;
    cout << "=--------------------------------------=" << endl;
    cout << "Stok Kelas Gold: ";
    cin >> stokGold;
    cout << "=--------------------------------------=" << endl;
    cout << "Stok Kelas Premium: ";
    cin >> stokPremium;
    cout << "========================================" << endl;

    
}

void PaintBalldReservation::lihatStatusPemesanan()
{
    cout << "========================================" << endl;
    cout << "-           Status Pemesanan           -" << endl;
    cout << "-        PaintBall Battle Ground       -" << endl;
    cout << "-       Politeknik ATMI Surakarta      -" << endl;
    cout << "========================================" << endl;
    ifstream inFile("informasi_pemesanan.txt"); // Membuka file informasi_pemesanan.txt
    string line;

    // Membaca dan menampilkan setiap baris dari file
    while (getline(inFile, line)) {
        cout << line << endl;

        // Menyimpan data kode pemesanan saja ke dalam vector untuk digunakan di menu hapusPemesanan
        istringstream iss(line);
        string kodePemesanan, kelas;
        if (iss >> kodePemesanan >> kelas) {
            kodePemesananList.push_back(kodePemesanan);
        }
    }


    inFile.close(); // Menutup file setelah selesai membaca

    cout << "----------------------------------------" << endl << endl;


    char yt;
    cout << "Kembali ke Menu?(y/t)" << endl;
    cin >> yt;
    cout << endl;
    if (yt == 'Y' || yt == 'y') {
        system("cls");
        adminMenu();
    }
    if (yt == 'T' || yt == 't') {
        system("cls");
        login();
    }
}

void PaintBalldReservation::lihatDaftarUser()
{
    cout << "========================================" << endl;
    cout << "-                Daftar                -" << endl;
    cout << "-           Cutomer or Member          -" << endl;
    cout << "-        PaintBall Battle Ground       -" << endl;
    cout << "-       Politeknik ATMI Surakarta      -" << endl;
    cout << "========================================" << endl;
    for (const user& user : users) {
        cout << "| " << user.username << "  " << user.password << " " << endl;
    }
    cout << "--------------------------------" << endl << endl;

    char yt;
    cout << "Kembali ke Menu?(y/t)" << endl;
    cin >> yt;
    cout << endl;
    if (yt == 'Y' || yt == 'y') {
        system("cls");
        adminMenu();
    }
    if (yt == 'T' || yt == 't') {
        system("cls");
        login();
    }
}

void PaintBalldReservation::lihatPrintStokKelas()
{
    cout << "========================================" << endl;
    cout << "-                Daftar                -" << endl;
    cout << "-            Stok Kelas Pada           -" << endl;
    cout << "-        PaintBall Battle Ground       -" << endl;
    cout << "-       Politeknik ATMI Surakarta      -" << endl;
    cout << "========================================" << endl;
    cout << "Stok Kelas Reguler\t:" << stokReguler << endl;
    cout << "=--------------------------------------=" << endl;
    cout << "Stok Kelas Gold   \t:" << stokGold << endl;
    cout << "=--------------------------------------=" << endl;
    cout << "Stok Kelas Premium\t:" << stokPremium << endl;
    cout << "========================================" << endl;
    ofstream outFile("stok_meja.txt");
    outFile << "========================================" << endl;
    outFile << "-                Daftar                -" << endl;
    outFile << "-            Stok Kelas Pada           -" << endl;
    outFile << "-        PaintBall Battle Ground       -" << endl;
    outFile << "-       Politeknik ATMI Surakarta      -" << endl;
    outFile << "========================================" << endl;
    outFile << "Stok Kelas Reguler\t:" << stokReguler << endl;
    outFile << "=--------------------------------------=" << endl;
    outFile << "Stok Kelas Gold   \t: " << stokGold << endl;
    outFile << "=--------------------------------------=" << endl;
    outFile << "Stok Kelas Premium\t: " << stokPremium << endl << endl;
    outFile << "========================================" << endl;
    outFile.close();

    cout << "Data stok kelas berhasil diprint ke dalam file 'stok_kelas.txt'" << endl;

    char yt;
    cout << "Kembali ke Menu?(y/t)" << endl;
    cin >> yt;
    cout << endl;
    if (yt == 'Y' || yt == 'y') {
        system("cls");
        adminMenu();
    }
    if (yt == 'T' || yt == 't') {
        system("cls");
        login();
    }
}

void PaintBalldReservation::lihatStokKelas()
{
    cout << "========================================" << endl;
    cout << "-                Daftar                -" << endl;
    cout << "-            Stok Kelas Pada           -" << endl;
    cout << "-        PaintBall Battle Ground       -" << endl;
    cout << "-       Politeknik ATMI Surakarta      -" << endl;
    cout << "========================================" << endl;
    cout << "Stok Kelas Reguler\t:" << stokReguler << endl;
    cout << "=--------------------------------------=" << endl;
    cout << "Stok Kelas Gold   \t:" << stokGold << endl;
    cout << "=--------------------------------------=" << endl;
    cout << "Stok Kelas Premium\t:" << stokPremium << endl;
    cout << "========================================" << endl;

    char yt;
    cout << "Kembali ke Menu?(y/t)" << endl;
    cin >> yt;
    cout << endl;
    if (yt == 'Y' || yt == 'y') {
        system("cls");
        userMenu();
    }
    if (yt == 'T' || yt == 't') {
        system("cls");
        login();
    }
}

void PaintBalldReservation::pesanKelas()
{
    cout << "========================================" << endl;
    cout << "-                Daftar                -" << endl;
    cout << "-           Pesan Stok Kelas           -" << endl;
    cout << "-        PaintBall Battle Ground       -" << endl;
    cout << "-       Politeknik ATMI Surakarta      -" << endl;
    cout << "========================================" << endl;
    cout << "Stok Kelas Reguler\t:" << stokReguler << endl;
    cout << "=--------------------------------------=" << endl;
    cout << "Stok Kelas Gold\t:" << stokGold << endl;
    cout << "=--------------------------------------=" << endl;
    cout << "Stok Kelas Premium\t:" << stokPremium << endl;
    cout << "========================================" << endl;

    cout << "001 . KELAS REGULER " << endl;
    cout << "Fasilitas :  " << endl;
    for (int i = 0; i < n; ++i) {
        cout << fasilitasReg[i] << endl;
    }
    cout << endl;
    cout << "002 . KELAS GOLD " << endl;
    cout << "Fasilitas :  " << endl;
    for (int i = 0; i < n; ++i) {
        cout << fasilitasGold[i] << endl;
    }
    cout << endl;
    cout << "003 . KELAS PREMIUM " << endl;
    cout << "Fasilitas :  " << endl;
    for (int i = 0; i < n; ++i) {
        cout << fasilitasPrem[i] << endl;
    }
    cout << endl;
    cout << "========================================" << endl;
    cout << "-                Daftar                -" << endl;
    cout << "-            List Harga Kelas          -" << endl;
    cout << "-        PaintBall Battle Ground       -" << endl;
    cout << "-       Politeknik ATMI Surakarta      -" << endl;
    cout << "========================================" << endl;
    cout << "KELAS REGULER perjam \t= Rp " << hargaReguler << endl;
    cout << "KELAS GOLD    perjam \t= Rp " << hargaGold << endl;
    cout << "KELAS PREMIUM perjam \t= Rp " << hargaPremium << endl << endl;
    cout << "PILIH KELAS (isi sesuai kode Kelas 001/002/003) : ";
    int choice;
    cin >> choice;

    int selectedStock;
    switch (choice) {
    case 001:
        selectedStock = stokReguler;
        break;
    case 002:
        selectedStock = stokGold;
        break;
    case 003:
        selectedStock = stokPremium;
        break;
    default:
        cout << "Pilihan tidak valid." << endl;
        return;
    }
    if (selectedStock > 0) {
        time_t now = time(0);
        tm ltm;
        localtime_s(&ltm, &now);

        int year = 1900 + ltm.tm_year;
        int month = 1 + ltm.tm_mon;
        int day = ltm.tm_mday;
        int hour = ltm.tm_hour;
        int minute = ltm.tm_min;

        cout << "Tanggal: " << day << "/" << month << "/" << year << endl;
        cout << "Waktu: " << hour << ":" << minute << endl;

        int halfPrice;
        switch (choice) {
        case 001:
            halfPrice = hargaReguler / 2;
            break;
        case 002:
            halfPrice = hargaGold / 2;
            break;
        case 003:
            halfPrice = hargaPremium / 2;
            break;
        }

        cout << "Masukkan tanggal pemesanan (dd/mm/yyyy): ";
        string tanggalPemesanan;
        cin >> tanggalPemesanan;

        cout << "Masukkan jam mulai (hanya tulis jam saja)= ";
        int jamMulai;
        cin >> jamMulai;

        cout << "Masukkan jam berhenti (hanya tulis jam saja)= ";
        int jamBerhenti;
        cin >> jamBerhenti;


        int pembayaranAwal = halfPrice * (jamBerhenti - jamMulai);


        cout << "Pembayaran awal: Rp " << pembayaranAwal << endl << endl;

        cout << "Masukkan nominal pembayaran: ";
        int payment;
        cin >> payment;

        if (payment >= halfPrice) {
            sisaPembayaran = payment - pembayaranAwal;
            system("cls");
            // Pemesanan berhasil
            cout << "Pemesanan berhasil. Silakan Tunjukkan Kode Pemesanan pada nota saat datang" << endl << endl;

            // Kurangi stok kelas
            switch (choice) {
            case 1:
                stokReguler--;
                break;
            case 2:
                stokGold--;
                break;
            case 3:
                stokPremium--;
                break;
            }
            // Simpan waktu mulai, jam mulai, dan jam berhenti pemesanany

            users.back().kelas = choice;
            users.back().waktuMulai = now;
            users.back().jamMulai = jamMulai;
            users.back().jamBerhenti = jamBerhenti;

            users.back().kodePemesanan = users.back().generateUniqueCode();

            // Menampilkan informasi pemesanan
            cout << "\nInformasi Pemesanan:" << endl;
            cout << "Kode Pemesanan: " << users.back().kodePemesanan << endl;
            cout << "Kelas: 00" << users.back().kelas << endl;
            cout << "Tanggal Pemesanan: " << tanggalPemesanan << endl;
            cout << "Jam Mulai: " << users.back().jamMulai << ":00" << endl;
            cout << "Jam Berhenti: " << users.back().jamBerhenti << ":00" << endl;
            cout << "Sisa Pembayaran: Rp " << sisaPembayaran << endl;

            // Simpan informasi pemesanan ke dalam file
            ofstream outFile("informasi_pemesanan.txt", ios::app); // ios::app untuk menambahkan ke file yang sudah ada
            outFile << "Kode Pemesanan: " << users.back().kodePemesanan << endl;
            outFile << "Kelas: 00" << users.back().kelas << endl;
            outFile << "Tanggal Pemesanan: " << tanggalPemesanan << endl;
            outFile << "Jam Mulai: " << users.back().jamMulai << ":00" << endl;
            outFile << "Jam Berhenti: " << users.back().jamBerhenti << ":00" << endl;
            outFile << "Sisa Pembayaran: Rp " << sisaPembayaran << endl;
            outFile << "------------------------" << endl;

            outFile.close(); // Tutup file setelah menulis


        }
        else {
            cout << "Pemesanan gagal. Nominal pembayaran kurang dari harga." << endl << endl;
        }
    }
    else {
        cout << "Stok Kelas PaintBall untuk kelas ini sudah habis. Silahkan pilih Kelas lain." << endl << endl;
    }
    char yt;
    cout << endl << endl;
    cout << "Kembali ke Menu?(y/t)" << endl;
    cin >> yt;
    cout << endl;
    if (yt == 'Y' || yt == 'y') {
        system("cls");
        userMenu();
    }
    if (yt == 'T' || yt == 't') {
        system("cls");
        login();
    }

}


void PaintBalldReservation::hapusPemesanan()
{
    cout << "\nMasukkan kode pemesanan yang akan dihapus: ";
    string kodePemesananToDelete;
    cin >> kodePemesananToDelete;

    ifstream inFile("informasi_pemesanan.txt");
    ofstream outFile("temp.txt");  // File sementara untuk menyimpan data tanpa kode pemesanan yang akan dihapus
    string line;

    bool found = false;  // Untuk menandai apakah kita menemukan kode pemesanan yang akan dihapus

    while (getline(inFile, line)) {
        // Jika line tidak mengandung kode pemesanan yang akan dihapus, salin ke file sementara
        if (line.find(kodePemesananToDelete) == string::npos) {
            outFile << line << endl;
        }
        else {
            // Jika line mengandung kode pemesanan yang akan dihapus, tandai sebagai ditemukan
            found = true;
        }
    }

    inFile.close();
    outFile.close();

    // Hapus file asli
    remove("informasi_pemesanan.txt");

    // Ubah nama file sementara menjadi nama file asli
    rename("temp.txt", "informasi_pemesanan.txt");

    if (found) {
        cout << "Pemesanan dengan kode " << kodePemesananToDelete << " SELESAI." << endl;
    }
    else {
        cout << "Kode pemesanan tidak ditemukan." << endl;
    }

    // Tambahkan opsi untuk kembali ke menu
    char yt;
    cout << endl << "Kembali ke Menu?(y/t)" << endl;
    cin >> yt;
    cout << endl;
    if (yt == 'Y' || yt == 'y') {
        system("cls");
        adminMenu();
    }
    if (yt == 'T' || yt == 't') {
        system("cls");
        login();
    }
}

string PaintBalldReservation::getHiddenInput()
{
    string password;
    char ch;
    while ((ch = _getch()) != 13) {  // 13 adalah ASCII untuk tombol Enter
        if (ch == 8) {  // 8 adalah ASCII untuk tombol backspace
            if (!password.empty()) {
                cout << "\b \b";  // Menghapus karakter sebelumnya di layar
                password.pop_back();  // Menghapus karakter dari string
            }
        }
        else {
            password.push_back(ch);
            _putch('*');  // Menampilkan karakter "*" sebagai ganti karakter sebenarnya
        }
    }
    cout << endl;
    return password;
}








