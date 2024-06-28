//Header Program
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
class lombaPage
{
public:
    void lombaPageCP();
    string cariLomba;
    int pilih;
    char key, yt;

    int generateRandomValue(int minRange, int maxRange) {
        // Inisialisasi nilai acak yang berubah setiap pemanggilan program
        srand(static_cast<unsigned int>(time(nullptr)));

        // Menghasilkan nilai acak dalam rentang tertentu [minRange, maxRange]
        int randomValue = rand() % (maxRange - minRange + 1) + minRange;

        return randomValue;
    }
}; 
