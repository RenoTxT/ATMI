#include <iostream>

using namespace std;

// Fungsi untuk mencetak elemen-elemen array
void printArray(const int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << std::endl;
}

// Fungsi untuk menggandakan setiap elemen dalam array
void doubleArray(const int inputArr[], int size, int outputArr[]) {
    for (int i = 0; i < size; ++i) {
        outputArr[i] = inputArr[i] * 2;
    }
}

int main() {
    const int size = 5;
    int originalArr[size] = { 1, 2, 3, 4, 5 };
    int doubledArr[size];

    cout << "Original Array: ";
    printArray(originalArr, size);

    // Mengirim array ke fungsi untuk dioperasikan
    doubleArray(originalArr, size, doubledArr);

    cout << "Doubled Array : ";
    printArray(doubledArr, size);

    return 0;
}
