// Header program
#pragma once
#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <fstream>
#include <conio.h>
#include <string>

// Statement untuk mengakses identifier
using namespace std;

// Kelas lomba yang di definisikan memiliki data public yang dapat diakses dimana saja
class isiFormulir
{
public:
    void isiFormulirCP();
    string cariLomba;
    int pilih;
    char key;
};
