#pragma once
#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <fstream>
#include <conio.h>
#include <string>

using namespace std;

class lombaPage
{
public:
	void lombaPageCP();
    string cariLomba;
    int pilih;
    char key,yt;

    int generateRandomValue(int minRange, int maxRange) {
        // Inisialisasi seed untuk fungsi rand()
        srand(static_cast<unsigned int>(time(nullptr)));

        // Menghasilkan nilai acak dalam rentang [minRange, maxRange]
        int randomValue = rand() % (maxRange - minRange + 1) + minRange;

        return randomValue;
    }
};