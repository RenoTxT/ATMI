#include <iostream>  //Sebagai standar input-output di c++ (cout cin)
#include <Windows.h> //menyediakan fungsi-fungsi untuk interaksi dengan sistem operasi Windows.
#include <iomanip>   //Mengatur beberapa aspek dari output, seperti lebar bidang, presisi, dll. (setw)
#include <fstream>   //Pembuatan file txt
#include <conio.h>   //Digunakan pada sistem Windows dan menyediakan fungsi-fungsi konsol.(getch)
#include <string>    //Penggunaan tipe data string
#include <iomanip>

#include "adminPage.h"	//menu Admin
#include "userPage.h"	//menu User
#include "directorPage.h" //menu Director
#include "systemPage.h"	//menu Sistem
#include "titlePage.h" //menu title

using namespace std;

systemPage sP;
titlePage tP;
adminPage aP;
userPage uP;
directorPage dP;

//login function checking
int kondisi_login,dataa,i,kondisi;
int choose;
//menyimpan string kode
string huruf[2] = { "A","B" };
string angka[10] = { "1","2","3","4","5","6","7","8","9","10" };
int arraygabunganint;
string combination[100];

//funtion untuk menyimpan array
struct tiketing {
	string tujuan;
	int jumlah_kursi = 0;
	string tanggal;
	string waktu;
	double harga = 0;
};
tiketing arrayTIKETING[100];

int beli_tiket;
int main() {
	mainsystem:
	while (true) {
		tP.titlePageCP();
		sP.systemPageCP();
		if (kondisi_login != 0) {
			break;
		}
	}
	
	if (kondisi_login == 1) {
		aP.adminPageCP();
		goto mainsystem;
	}
	else if (kondisi_login == 2) {
		uP.userPageCP();
		goto mainsystem;
	}
	else if (kondisi_login == 3) {
		dP.directorPageCP();
		goto mainsystem;
	}
}