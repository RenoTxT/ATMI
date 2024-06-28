#include "Kalkulator.h"

double Kalkulator::Hitung(double x, char operasi, double y) {
	switch (operasi) {
	case'+':
		return x + y;
	case'-':
		return x - y;
	case'*':
		return x * y;
	case'/':
		return x / y;
	default:
		return 0.0;
	}
}