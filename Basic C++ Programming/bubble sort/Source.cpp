#include <iostream>

using namespace std;

// Deklarasi fungsi-fungsi
void selectionSort(int arr[], int size);
void insertionSort(int arr[], int size);
void bubbleSort(int arr[], int size);
void printArray(const int arr[], int size);

int main() {
    const int size = 6;
    int arrSelection[size] = { 5, 2, 9, 1, 5, 6 };
    int arrInsertion[size] = { 5, 2, 9, 1, 5, 6 };
    int arrBubble[size] = { 5, 2, 9, 1, 5, 6 };

    // Selection Sort
    cout << "Selection Sort:" << std::endl;
    selectionSort(arrSelection, size);
    printArray(arrSelection, size);

    // Insertion Sort
    cout << "Insertion Sort:" << std::endl;
    insertionSort(arrInsertion, size);
    printArray(arrInsertion, size);

    // Bubble Sort
    cout << "Bubble Sort:" << std::endl;
    bubbleSort(arrBubble, size);
    printArray(arrBubble, size);

    return 0;
}

// Definisi fungsi-fungsi
void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void printArray(const int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << std::endl;
}
