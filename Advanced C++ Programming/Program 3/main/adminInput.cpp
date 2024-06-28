#include "adminInput.h"
#include "titlePage.h"

titlePage tpaI;

struct tiketing {
	string tujuan;
	int jumlah_kursi = 0;
	string tanggal;
	string waktu;
	double harga = 0;
	string kursi;
};
extern tiketing arrayTIKETING[];


extern string combination[100];
extern int dataa, i;
extern string angka[2];
extern string huruf[2];
extern int kondisi, arraygabunganint;


int jumlah_kursinya;



void adminInput::adminInputCP() {
	tpaI.titleAdminCP();
	cout << "Berapa tiket yang ingin ditambahkan : ";
	cin >> tiket;
	cout << endl;
	system("cls");
	//make function loading task
	cout << "sedang membuat data, mohon ditunggu";
	cout << ".";
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << ".";
	//.function loading
	//titleInput

	//.titleInput

	system("cls");
	for (i = dataa; i < dataa + tiket;i++) {
		cout << "Tujuan Kereta"<< "\t: ";
		cin >> arrayTIKETING[i].tujuan;
		cout << "Tanggal\t: ";
		cin.ignore();
		getline(cin,arrayTIKETING[i].tanggal);
		cout << "Jumlah Kursi\t: ";
		cin >> arrayTIKETING[i].jumlah_kursi;
		cout << "Waktu\t: ";
		cin.ignore();
		getline(cin, arrayTIKETING[i].waktu);
		cout << "Harga\t: ";
		cin >> arrayTIKETING[i].harga;
		cout << endl;
	}

	dataa = i;
	cout << "data telah ditambahkan"<<endl;
	Sleep(2000);
}
