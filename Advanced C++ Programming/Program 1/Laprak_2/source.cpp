#include <iostream>
#include <Windows.h>
#include "Kalkulator.h"


using namespace std;

int main() {
	system("color F0");
	double x = 0.0;
	double y = 0.0;
	double hasil = 0.0;
	char operasi = '+';
	cout << "Aplikasi Kalkulator Sederhana" << endl << endl;
	cout << "Silahkan pilih operasi perhitungan. Format: a+b | a-b | a*b | a/b" << endl;

	Kalkulator k;
	while (true) {
		cin >> x >> operasi >> y;
		hasil = k.Hitung(x, operasi, y);
		cout << "Hasil " << "dari " << x << operasi << y << " adalah " << hasil << endl;
	}
	
	cin.get();
	return 0;
}