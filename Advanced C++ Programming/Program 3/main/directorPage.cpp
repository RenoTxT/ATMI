#include "directorPage.h"
#include "titlePage.h"
#include "systemPage.h"

struct tiketing {
	string tujuan;
	int jumlah_kursi = 0;
	string tanggal;
	string waktu;
	double harga = 0;
	string kursi;
};

extern tiketing arrayTIKETING[];
extern int dataa;

extern int beli_tiket;

systemPage mD;
titlePage tpD;

void directorPage::directorPageCP() {
	tpD.titleDirectorCP();
	mD.systemMenuDirectorCP();
    system("cls");
    cout << "=====================================================================" << endl;
    cout << "                         TOKO YGGDRASIL                        " << endl;
    cout << "=====================================================================" << endl;
    cout << "---------------------------------------------------------------------" << endl;

    cout << "|            TUJUAN" << "           |     JUMLAH" << "     |       HARGA" << "       |" << endl;
    cout << "---------------------------------------------------------------------" << endl;
    for (int i = 0; i < dataa; ++i)
    {
        cout << "|" << left << setw(16) << arrayTIKETING[i].tujuan << "|     " << setw(15) << beli_tiket << "|"  << setw(15) << arrayTIKETING[i].harga*beli_tiket << "k" << "  |";
        cout << endl;
    }
}