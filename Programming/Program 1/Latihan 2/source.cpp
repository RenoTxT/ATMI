#include <iostream>
#include <cmath>

using namespace std;

//global variabel
char yt;
double luas, keliling, volume;
const double PHI = 3.14159265;
const char samadengan[100]="=======================================================";

//judul utama pada program
void judul_utama() {
	system("Color B5");
	cout << samadengan << endl << "\tKalkulator Layang-layang & Tabung" << endl << samadengan;
}

//judul layangan
void judul_layangan() {
	system("Color E4");
	cout << samadengan <<endl<<"\tKalkulator Layang - Layang" <<endl<< samadengan;
}

//judul tabung
void judul_tabung() {
	system("Color 0A");
	cout << samadengan << endl << "\tKalkulator Volume Tabung" << endl << samadengan<<endl<<endl;
}

//penghitung keliling layang-layang
double kelilinglayang(double a, double c) {
	keliling = 2 * (a + c);
	return keliling;
}

//penghitung luas layang-layang
double luaslayang(double d1,double d2) {
	luas = (d1 * d2)/2;
	return luas;
}

//penghitung volume tabung
double volumetabung(double jari_jari, double tinggi) {
	volume = PHI * pow(jari_jari, 2) * tinggi;
	return volume;
}

//tampilan dan inputan keliling layang-layang
void kelilinglayanglayang() {
	system("cls"); //clear layar

	//input sisi a dan c
	cout << samadengan << "\n\t\tPenghitung Keliling Layang-Layang" << endl << samadengan << endl;
	double a, c;
	cout << endl;
	cout << "Masukan sisi a\t= ";
	cin >> a;

	cout << "Masukan sisi c\t= ";
	cin >> c;

	//memanggil perhitungan kelilinglayang
	kelilinglayang(a, c);

	//hasil return perhitungan kelilinglayang
	cout << endl << samadengan << endl << endl << "Hasil Keliling = " << keliling << endl << endl << samadengan << endl;
}

//tampilan dan inputan luas layang layang
void luaslayanglayang() {
	system("cls"); //clear layar
	cout << samadengan << "\n\t\tPenghitung Luas Layang-Layang" << endl << samadengan << endl;
	double d1, d2;

	cout << "\nMasukan diagonal 1\t= ";
	cin >> d1;

	cout << "Masukan diagonal 2\t= ";
	cin >> d2;
	cout << endl << samadengan << endl;

	//memanggil perhitungan luaslayang
	luaslayang(d1, d2);

	//hasil return perhitungan luaslayang
	cout << "\nHasil Luas Layang-layang = " << luas << endl << endl << samadengan << endl;
}

//tampilan dan inputan kalkulator layang-layang
void kalkulator_layangan() {
tanya_layang:
	system("cls"); //clear layar

	//lokal variabel untuk switch option
	string layangan;

	//memanggil judul
	judul_layangan();

	//opsi switch
	cout << "\n\nPilih 'keliling' atau 'luas'\t: ";
	cin >> layangan;
	cout << endl << samadengan << endl;

	switch (layangan[0]) {
	case 'k':
		//memanggil fungsi keliling layang-layang
		kelilinglayanglayang();
		break;
	case 'l':
		//memanggil fungsi luas layang-layang
		luaslayanglayang();
		break;
	default:
		cout << endl << "INVALID INPUT!" << endl;
		goto tanya_layang;
	}
}

//tampilan dan inputan kalkulator tabung
void kalkulator_tabung() {
	system("cls"); //clear layar
	
	//deklarasi variabel
	double jari_jari, tinggi;

	//judul tabung
	judul_tabung();

	//input jari jari dan tinggi
	cout << "Masukan jari-jari\t= ";
	cin >> jari_jari;
	cout << "Masukan tinggi\t\t= ";
	cin >> tinggi;
	cout << endl<<samadengan<<endl;

	//memanggil fungsi volume tabung
	volumetabung(jari_jari, tinggi);
	//output hasil perhitungan
	cout << endl<<"Hasil Volume Tabung\t\t= " << volume<<endl<<endl<<samadengan;
}

//main program
int main()
{
awal:
	system("cls"); //clear layar

	//judul utama
	judul_utama();

	//lokal variable untuk switch option layang/tabung
	int tipe;
	cout << endl << "1. Kalkulator Layang - layang" << endl << "2. Kalkulator Volume Tabung" << endl<<"Opsi\t: ";
	cin >> tipe;
	cout << endl << samadengan << endl;

	switch (tipe) {
	case 1:
		kalkulator_layangan();
		goto tanya;
	case 2:
		kalkulator_tabung();
		goto tanya;
	default:
		cout << "Invalid input";
		goto awal;
	}
tanya:
	//input untuk mengulang/mengakhiri program
	cout << endl << "Coba Ya atau Tidak " << endl;
	cout << "Masukkan Data Lagi (y/t) ?  ";
	cin >> yt;
	cout << endl;
	if (yt == 'Y' || yt == 'y') {
		goto awal;
	}
	if (yt == 'T' || yt == 't') {
		goto akhir;
	}
akhir:
	system("cls"); //clear layar
	cout << "Thanks for using this Calculator."<<endl<<"GOOD BYE!"<<endl;
	return 0;
}
