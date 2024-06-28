#include "adminPage.h"
#include "titlePage.h"
#include "systemPage.h"
#include "adminInput.h"
#include "adminEdit.h"
#include "adminDelete.h"

titlePage tAP;
systemPage sAP;
adminInput aIP;
adminEdit aEP;
adminDelete aDP;


struct tiketing {
    string tujuan;
    int jumlah_kursi = 0;
    string tanggal;
    string waktu;
    double harga = 0;
    string kursi;
};
extern int dataa;
extern tiketing arrayTIKETING[];


using namespace std;
extern int kondisi_login;
extern int opsi_selesai;

extern int choose;

void adminPage::adminPageCP() {
    tAP.titleAdminCP();
    sAP.systemMenuAdmin1CP();
    cin >> choose;

    // Compare choose with character literals
    if (choose == 1) {
        system("cls");
        aIP.adminInputCP();
        choose = 0;
        system("cls");
        adminPageCP();
    }
    else if (choose == 2) {
        system("cls");
        aEP.adminEditCP();
        choose = 0;
        system("cls");
        adminPageCP();
    }
    else if (choose == 3) {
        system("cls");
        aDP.adminDeleteCP();
        choose = 0;
        system("cls");
        adminPageCP();
    }
    else if (choose == 4) {
        ofstream myFile;
        myFile.open("stok.txt", ios::trunc);
        myFile << fixed << setprecision(2);                            //Cetak nota untuk user, terdapat redeeem code

        myFile << "---------------------------------------------" << endl;
        myFile << "         ---TOKO YGGDRASIL---               " << endl;
        myFile << "               NOTA PEMBAYARAN                " << endl;
        myFile << "---------------------------------------------" << endl;
        for (int i = 0; i < dataa; ++i)
        {
            myFile << "Tujuan  : "<< arrayTIKETING[i].tujuan << " - " << arrayTIKETING[i].jumlah_kursi << endl << endl;
        }
        myFile << "=============================================" << endl;

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
        system("cls");
        cout << "cetak telah berhasil";
        system("cls");
    }
    else if (choose == 5) {
        system("cls");
    }
    else {
        cout << "Invalid choice." << endl;
        choose = 0;
        system("cls");
        adminPageCP();
    }

}