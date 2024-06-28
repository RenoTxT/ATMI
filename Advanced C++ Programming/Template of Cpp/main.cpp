#include <iostream>  //Sebagai standar input-output di c++ (cout cin)
#include <Windows.h> //menyediakan fungsi-fungsi untuk interaksi dengan sistem operasi Windows.
#include <iomanip>   //Mengatur beberapa aspek dari output, seperti lebar bidang, presisi, dll. (setw)
#include <fstream>   //Pembuatan file txt
#include <conio.h>   //Digunakan pada sistem Windows dan menyediakan fungsi-fungsi konsol.(getch)
#include <string>    //Penggunaan tipe data string

#include "adminPage.h"	//menu Admin
//#include "userPage.h"	//menu User
#include "systemPage.h"	//menu Sistem
#include "titlePage.h" //menu title

using namespace std;

systemPage sP;
titlePage tP;
adminPage aP;

//login function checking
int kondisi_login;

int main() {
	while (true) {
		tP.titlePageCP();
		sP.systemPageCP();
		if (kondisi_login != 0) {
			break;
		}
	}
	aP.adminPageCP();
}