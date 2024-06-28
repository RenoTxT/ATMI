#include <iostream>
#include <array>
#include <algorithm>
#include <string>

using namespace std;
char samadengan[100] = "========================";


int main() {
	system("cls"); //clear console

	//lokal variabel
	char yn;
	const int jumlahBarang = 6;
	string nama_index_sekarang, kode_index_sekarang, namaCari;
	int stok_index_sekarang, opt, found;

	//array namabarang
	array<string, jumlahBarang> kodeBarang = { "A001","A002","A003","A004", "A005", "A006" };
	array <string, jumlahBarang> namaBarang = { "Sabun Mandi","Shampoo","Sikat Gigi","Minyak Goreng","Kecap","Gula" };

	//membuat default barang index 0-5 stok = 0
	int stokBarang[jumlahBarang];
	for (int i = 0; i < jumlahBarang; i++) {
		stokBarang[i] = 0;
	}
awal:
	//tampilan home dan switch case menu
	cout << "\t      Daftar Barang Di SpaceX" << endl << samadengan << samadengan << endl;
	cout << "1. Input Stok Barang" << endl;
	cout << "2. Daftar Barang" << endl;
	cout << "3. Urutkan Barang" << endl;
	cout << "4. Cari Barang" << endl;
	cout << "5. Exit Program" << endl;
	cout << "pilihan anda: ";
	cin >> opt;
	switch (opt) {

		//blok program input stok barang
	case 1:
		system("cls"); //clear console
		cout << samadengan << samadengan << endl << "\t\tInput Stok Barang" << endl << samadengan << samadengan << endl << endl;
		for (int i = 0; i < jumlahBarang; i++) {
			cout << kodeBarang[i]<<"\t| ";
			cout << namaBarang[i];
			cout << "\nStok\t= ";
			cin >> stokBarang[i];
			cout << endl;
		}

		//tanya apakah ingin kembali ke home
		cout << "Kembali ke Home? (y/t) ?  ";
		cin >> yn;
		cout << endl;
		if (yn == 'Y' || yn == 'y') {
			system("cls");
			goto awal;
		}
		if (yn == 'T' || yn == 't') {
			system("cls");
			goto case2;
		}

		//melihat daftar barang tanpa sorting list
	case2:
	case 2:

		system("cls"); //clear console

		//menampilkan daftar barang
		cout << samadengan << samadengan << endl << "\t\tDaftar Barang" << endl << samadengan << samadengan << endl << endl;
		for (int i = 0; i < jumlahBarang; i++) {
			cout << kodeBarang[i] <<"\t| " << namaBarang[i] << "\nStok\t: " << stokBarang[i] << "\n" << endl << "\n";
		}

		//tanya apakah ingin kembali ke home
		cout << "Kembali ke Home? (y/t) ?  ";
		cin >> yn;
		cout << endl;
		if (yn == 'Y' || yn == 'y') {
			system("cls");
			goto awal;
		}
		if (yn == 'T' || yn == 't') {
			system("cls");
			goto case2;
		}

		//melihat daftar barang yang tersorting sesuai dengan stok dari yang terkecil
	case 3:
	case3:
		system("cls"); //clear console

		//array bubble untuk sorting
		for (int i = 0; i < jumlahBarang; i++) {
			stok_index_sekarang = stokBarang[0];
			nama_index_sekarang = namaBarang[0];
			kode_index_sekarang = kodeBarang[0];

			for (int j = 1; j < jumlahBarang; j++) {
				if (stok_index_sekarang > stokBarang[j]) {
					stokBarang[j - 1] = stokBarang[j];
					namaBarang[j - 1] = namaBarang[j];
					kodeBarang[j - 1] = kodeBarang[j];

					stokBarang[j] = stok_index_sekarang;
					namaBarang[j] = nama_index_sekarang;
					kodeBarang[j] = kode_index_sekarang;
				}
				else {
					stok_index_sekarang = stokBarang[j];
					nama_index_sekarang = namaBarang[j];
					kode_index_sekarang = kodeBarang[j];
				}
			}
		}

		//menampilkan daftar barang setelah di sort
		cout << samadengan << samadengan << endl << "     Daftar Barang Berdasarkan Stok Terendah" << endl << samadengan << samadengan << endl << endl;
		for (int i = 0; i < jumlahBarang; i++) {
			cout << kodeBarang[i]<<"\t| " << namaBarang[i] << "\nStok\t: " << stokBarang[i] << "\n" << endl << "\n";
		}

		//tanya apakah ingin kembali ke home
		cout << "Kembali ke Home? (y/t) ?  ";
		cin >> yn;
		cout << endl;
		if (yn == 'Y' || yn == 'y') {
			system("cls");
			goto awal;
		}
		if (yn == 'T' || yn == 't') {
			system("cls");
			goto case3;
		}

	case 4:
	case4:
		system("cls"); //console clear

		//daftar barang
		for (int i = 0; i < jumlahBarang; i++) {
			cout << namaBarang[i] << endl;
		}

		//input barang yang dicari
		cout << samadengan << samadengan << endl << "\t\tCari Barang" << endl << samadengan << samadengan << endl << endl;
		cout << "Masukkan Nama Barang yang ingin dicari: ";
		cin >> namaCari;

		// Convert the search string to lowercase (or uppercase) for case-insensitive search
		transform(namaCari.begin(), namaCari.end(), namaCari.begin(), ::tolower);

		//deklarasi found = 1 untuk if else dibawah
		found = -1;

		for (int i = 0; i < jumlahBarang; i++) {
			string namaBarangLower = namaBarang[i];
			// Convert the item from the array to lowercase (or uppercase)
			transform(namaBarangLower.begin(), namaBarangLower.end(), namaBarangLower.begin(), ::tolower);

			if (namaBarangLower.find(namaCari) != string::npos) {
				found = i;
				break;
			}
		}

		//jika barang ditemukan maka found = index
		if (found != -1) {
			cout << "\nBarang yang ditemukan: \n"<<kodeBarang[found]<<"\t| " << namaBarang[found] << "\nStok\t: " << stokBarang[found] << endl << endl;
		}
		else {
			cout << "\nBarang tidak ditemukan." << endl;
		}

		//tanya apakah ingin kembali ke home
		cout << "Kembali ke Home? (y/t) ?  ";
		cin >> yn;
		cout << endl;
		if (yn == 'Y' || yn == 'y') {
			system("cls");
			goto awal;
		}
		if (yn == 'T' || yn == 't') {
			system("cls");
			goto case4;
		}
	case 5:
		goto akhir;
	}
	//akhir dari program
akhir:
	system("cls"); //clear console
	cout << endl << samadengan << endl << "      Terima Kasih\n   Sampai Jumpa[^_^]" << endl << samadengan << endl << endl;
	return 0;
}