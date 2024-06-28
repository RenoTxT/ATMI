#include <iostream>  //Sebagai standar input-output di c++ (cout cin)
#include <Windows.h> //menyediakan fungsi-fungsi untuk interaksi dengan sistem operasi Windows.
#include <iomanip>   //Mengatur beberapa aspek dari output, seperti lebar bidang, presisi, dll. (setw)
#include <conio.h>   //Digunakan pada sistem Windows dan menyediakan fungsi-fungsi konsol.(getch)
#include <string>    //Penggunaan tipe data string
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
		cout << "Login berhasil sebagai ADMIN"<<endl;
		Sleep(2000);
		system("cls");
		kondisi_login = 1;
	}
	else if (username == username2 && password == password2) {
		system("cls");
		cout << "Login berhasil sebagai User"<<endl;
		Sleep(2000);
		system("cls");
		kondisi_login = 2;
	}
	else {
		system("cls");
		cout << "username atau password yang anda masukan salah"<<endl;
		Sleep(2000);
		system("cls");
	}
}

void systemPage::systemMenuAdmin1CP() {
	cout << "                   1. Menu Pendaftaran (user)" << endl;
	cout << "                   2. Login Admin" << endl;
	cout << "                   3. Keluar" << endl;
	cout << "===================================================================" << endl << endl;
	cout << "Pilih : ";
}