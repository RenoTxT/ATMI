#include "systemPage.h"

extern int kondisi_login;

void systemPage::systemPageCP() {
	cout << "Username\t: "; cin >> username;
	cout << "Password\t: ";
	password = "";
	char ch;                     //Memasukan Password jadi * dan cek benar atau salah
	while (true)
	{
		ch = _getch();

		if (ch == 13)
			break;

		if (ch == 8)
		{
			if (!password.empty())
			{
				cout << "\b \b";
				password.pop_back();
			}
		}
		else
		{
			cout << '*';
			password += ch;
		}
	}
	if (username == username1 && password == password1) {
		system("cls");
		cout << "Login berhasil sebagai ADMIN" << endl;
		Sleep(2000);
		system("cls");
		kondisi_login = 1;
	}
	else if (username == username2 && password == password2) {
		system("cls");
		cout << "Login berhasil sebagai USER" << endl;
		Sleep(2000);
		system("cls");
		kondisi_login = 2;
	}
	else if (username == username3 && password == password3) {
		system("cls");
		cout << "Login berhasil sebagai DIRECTOR" << endl;
		Sleep(2000);
		system("cls");
		kondisi_login = 3;
	}
	else {
		system("cls");
		cout << "username atau password yang anda masukan salah" << endl;
		Sleep(2000);
		system("cls");
	}
}

void systemPage::systemMenuAdmin1CP() {
	cout << "                      1. Input Data" << endl;
	cout << "                      2. Edit Data" << endl;
	cout << "                      3. Delete Data" << endl;
	cout << "                      4. Cetak Data" << endl;
	cout << "                      5. Back" << endl;
	cout << "=====================================================================" << endl << endl;
	cout << "Pilih : ";
}

void systemPage::systemMenuUserCP() {
	cout << "                      1. Beli Tiket" << endl;
	cout << "                      2. Keluar" << endl;
	cout << "=====================================================================" << endl << endl;
	cout << "Pilih : ";
}

void systemPage::systemMenuDirectorCP() {
	cout << "                      1. Cek Penjualan" << endl;
	cout << "                      2. Cetak Laporan" << endl;
	cout << "                      3. Keluar" << endl;
	cout << "=====================================================================" << endl << endl;
	cout << "Pilih : ";
}