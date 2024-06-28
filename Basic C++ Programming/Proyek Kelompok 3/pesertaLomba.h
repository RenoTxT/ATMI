//Header Program
#pragma once
#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <conio.h>

// Statement untuk mengakses identifier
using namespace std;

// Kelas lomba yang di definisikan memiliki data public yang dapat diakses dimana saja
class pesertaLomba
{
public:
    void pesertaLombaCP();
    string cariLomba;
    int  pilih;
    char key;
};

