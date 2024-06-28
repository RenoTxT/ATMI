#include "kalkulator.h" //panggil class
#include <iostream> //library pada c++

using namespace std;

int main() {
    Maximal hitungan; // panggil class yang berada di header kalkulator lalu beri nama variabel

    double velocity, angle; //buat variabel untuk diberikan ke class di header
    cout << "Masukan Kecepatan: ";
    cin >> velocity;

    cout << "Masukan Sudut Eleasi: ";
    cin >> angle;

    double xmax = hitungan.xMax(velocity, angle); //memanggil fungsi class dengan input data variabel velocity dan angle
    double hmax = hitungan.hMax(velocity, angle); //dimana velocity dan angle ini akan dikirim ke class Maksimum

    cout << "Maximal Range (xmax): " << xmax << endl; 
    cout << "Maximal Height (hmax): " << hmax << endl;

    return 0;
}
