// kalkulator.cpp

#include "kalkulator.h"

double Kalkulator::tambah(double a, double b) {
    return a + b;
}

double Kalkulator::kurang(double a, double b) {
    return a - b;
}

double Kalkulator::kali(double a, double b) {
    return a * b;
}

double Kalkulator::bagi(double a, double b) {
    if (b != 0) {
        return a / b;
    }
    else {
        // Handle division by zero
        return 0;
    }
}
