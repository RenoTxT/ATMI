#include "kalkulator.h"
#include <cmath>

double xmax, hmax, radian, sudut, kecepatan, g = 10, keliling, luas, volume;
const double PI = 3.14159265;

using namespace std;


double Maximal::xMax(double kecepatan, double sudut) {
	radian = sudut * PI / 180;
	xmax = ((pow(kecepatan, 2) * sin(2 * radian)) / g);
	return xmax;
}

double Maximal::hMax(double kecepatan, double sudut) {
	hmax = (pow(kecepatan, 2) * pow(sin(radian), 2)) / (2 * g);
	return hmax;
}

//penghitung keliling layang-layang
double Maximal::kelilinglayang(double a, double c) {
	keliling = 2 * (a + c);
	return keliling;
}

//penghitung luas layang-layang
double Maximal::luaslayang(double d1, double d2) {
	luas = (d1 * d2) / 2;
	return luas;
}

//penghitung volume tabung
double Maximal::volumetabung(double jari_jari, double tinggi) {
	volume = PI * pow(jari_jari, 2) * tinggi;
	return volume;
}