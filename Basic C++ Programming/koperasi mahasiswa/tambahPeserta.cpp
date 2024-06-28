#include "tambahPeserta.h"
#include <iostream>
#include <algorithm>
using namespace std;

// External declaration of variables declared in the main file
extern int jumlahPeserta;
extern const int MAX_PESERTA;
extern Mahasiswa pesertaKoperasi[];

// Function to convert a string to lowercase
string toLower(const string& str) {
    string namaBawah = str;
    transform(namaBawah.begin(), namaBawah.end(), namaBawah.begin(), ::tolower);
    return namaBawah;
}

// Implementation of the function to add a participant
void tambahPeserta::tambahPesertaCP() {
    if (jumlahPeserta < MAX_PESERTA) {
        // Clear the newline character left in the input buffer
        cin.ignore();

        // Input participant's name (case-insensitive)
        cout << "Enter Participant's Name: ";
        getline(cin, pesertaKoperasi[jumlahPeserta].nama);

        // Convert the name to lowercase to ensure uniqueness
        string lowerCaseName = toLower(pesertaKoperasi[jumlahPeserta].nama);

        // Check for the uniqueness of the name
        for (int i = 0; i < jumlahPeserta; ++i) {
            string participantName = toLower(pesertaKoperasi[i].nama);
            if (participantName == lowerCaseName) {
                cout << "Sorry, the entered name is already in use. Please try again." << endl;
                return; // Exit the function if the name is already in use
            }
        }

        // If the name is unique, proceed to enter the participant's ID (NIM)
        cout << "Enter Participant's ID (NIM): ";
        cin >> pesertaKoperasi[jumlahPeserta].nim;

        // Check if the ID (NIM) is already in use
        for (int i = 0; i < jumlahPeserta; ++i) {
            if (pesertaKoperasi[i].nim == pesertaKoperasi[jumlahPeserta].nim) {
                cout << "Sorry, the entered ID (NIM) is already in use. Please try again." << endl;
                return; // Exit the function if the ID (NIM) is already in use
            }
        }

        // Initialize the balance and increment the participant count
        pesertaKoperasi[jumlahPeserta].saldo = 0;
        jumlahPeserta++;
        cout << "Participant successfully added!" << endl;
    }
    else {
        cout << "The participant's cooperative is already full!" << endl;
    }
}
