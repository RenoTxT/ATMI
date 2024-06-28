#include "kalkulator.h"
#include <cmath>

double xmax, hmax, radian, sudut, kecepatan, g = 10;
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