#include <iostream>
#include <cmath>

double xmax, hmax, radian, sudut, kecepatan, g = 10;
const double PI = 3.14159265;
char yt;
const char samadengan[75] = "==========================================================================";
using namespace std;

//menghitung konversi sudut ke radian dan sin2 untuk hmax
void rumus() {
	radian = sudut * PI / 180;
	xmax = ((pow(kecepatan, 2) * sin(2 * radian)) / g);
	hmax = (pow(kecepatan, 2) * pow(sin(radian), 2)) / (2 * g);
}

void inputan() {
	//masukan kecepatan awal
	cout << "Masukan kecepatan awal (m/s)\t: ";
	cin >> kecepatan;

	//masukan derajat
	cout << "Masukan sudut elevasi (derajat)\t: ";
	cin >> sudut;
	cout << endl << samadengan << endl << endl;
}

int main()
{	
	//color 0 for background A for text
	system("Color E4");

//awal program looping
awal: 
	//judul program
	cout << samadengan << endl<<"\t\tKalkulator Penghitung Gerak Parabola"<<endl<< samadengan << endl<<endl;

	//memanggil fungsi input
	inputan();

	//memanggil fungsi rumus
	rumus();

	//menampilkan hasil perhitungan
	cout << "Jarak maksimum (xmax)\t\t: " << xmax << " meter" << endl;
	cout << "Ketinggian maksimum (hmax)\t: " << hmax << " meter" << endl<<endl<<samadengan<<endl;

	//opsi untuk mengulang y/n
	cout << endl<< "Coba Ya atau Tidak " << endl;
	cout << "Masukkan Data Lagi (y/n) ?  ";
	cin >> yt;

	//jika Y/y maka kembali ke awal program looping, Jika N/n maka program akan berakhir dengan return 0
	if (yt == 'Y' || yt == 'y') { 
		cout << endl;
		goto awal;
	}
	if (yt == 'N' || yt == 'n') { 
		goto akhir;
	}

//akhir program looping
akhir: 
	return 0;
}