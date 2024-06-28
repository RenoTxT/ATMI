#pragma once
#include <iostream>  //Sebagai standar input-output di c++ (cout cin)
#include <Windows.h> //menyediakan fungsi-fungsi untuk interaksi dengan sistem operasi Windows.
#include <iomanip>   //Mengatur beberapa aspek dari output, seperti lebar bidang, presisi, dll. (setw)
#include <conio.h>   //Digunakan pada sistem Windows dan menyediakan fungsi-fungsi konsol.(getch)
#include <string>    //Penggunaan tipe data string

using namespace std;

class systemPage
{
public:
	void systemPageCP();
	void systemMenuAdmin1CP();
	void systemMenuUserCP();
	void systemMenuDirectorCP();

	const string username1 = "ADMIN", password1 = "123456", username2 = "USER", password2 = "678910", username3 = "director", password3 = "111213";
	string username, password;

};
