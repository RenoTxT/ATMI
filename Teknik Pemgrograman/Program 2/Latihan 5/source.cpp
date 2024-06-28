#include <iostream>
#include <array>
#include <algorithm>
#include <string>

using namespace std;

char samadengan[100] = "=====================", yt;
const int jumlahMahasiswa = 8, jumlahProdi = 6, jumlahJenjang = 2; //constanta ditulis dengan huruf besar
array<string, jumlahMahasiswa> nim;
array<string, jumlahMahasiswa> nama, prodiMahasiswa, jenjangMahasiswa;
string namaCari, nim_index_sekarang, nama_index_sekarang;
array<string, jumlahProdi> prodi = { "TMI", "TMK", "TPM", "RTM", "PM", "TRMK" };
array<string, jumlahJenjang> jenjang = { "D3", "D4" };
int found, opsi;


void inputdata() {
    system("cls");
    for (int i = 0; i < jumlahMahasiswa; i++) {
        cout << "Data Mahasiswa ke-" << i + 1 << endl << samadengan << samadengan << endl;
        cout << "Masukan NIM Mahasiswa\t: ";
        cin >> nim[i];
        cout << "Masukan Nama Mahasiswa\t: ";
        cin >> nama[i];
        cout << endl;
        if (nim[i] >= "20221001" && nim[i] <= "20221099") {
            prodiMahasiswa[i] = prodi[0]; // TMI
            jenjangMahasiswa[i] = jenjang[0];
        }
        else if (nim[i] >= "20222001" && nim[i] <= "20222099") {
            prodiMahasiswa[i] = prodi[1]; // TMK
            jenjangMahasiswa[i] = jenjang[0];
        }
        else if (nim[i] >= "20223001" && nim[i] <= "20223099") {
            prodiMahasiswa[i] = prodi[2]; // TPM
            jenjangMahasiswa[i] = jenjang[0];
        }
        else if (nim[i] >= "20224001" && nim[i] <= "20224099") {
            prodiMahasiswa[i] = prodi[3]; // RTM
            jenjangMahasiswa[i] = jenjang[1];
        }
        else if (nim[i] >= "20225001" && nim[i] <= "20225099") {
            prodiMahasiswa[i] = prodi[4]; // PM
            jenjangMahasiswa[i] = jenjang[1];
        }
        else if (nim[i] >= "20226001" && nim[i] <= "20226099") {
            prodiMahasiswa[i] = prodi[5]; // TRMK
            jenjangMahasiswa[i] = jenjang[1];
        }
        else {
            cout << "NIM tidak valid" << endl;
            i--; // repeat input for invalid nim
        }
    }
    cout << samadengan << samadengan << endl;
    for (int i = 0; i < jumlahMahasiswa; i++) {
        cout << nim[i] << "\t" << nama[i] << "\t" << prodiMahasiswa[i] << "\t" << jenjangMahasiswa[i] << endl;
    }
    cout << samadengan << samadengan << endl;

}

void sortdatamahasiswa() {
    cout << "   Data Mahasiswa Politeknik ATMI" << endl << samadengan << samadengan << endl;
    for (int i = 0; i < jumlahMahasiswa; i++) {
        nim_index_sekarang = nim[0];
        nama_index_sekarang = nama[0];

        for (int j = 1; j < jumlahMahasiswa; j++) {
            if (nim_index_sekarang > nim[j]) {
                nim[j - 1] = nim[j];
                nama[j - 1] = nama[j];

                nim[j] = nim_index_sekarang;
                nama[j] = nama_index_sekarang;
            }
            else {
                nim_index_sekarang = nim[j];
                nama_index_sekarang = nama[j];
            }
        }
        if (nim[i] >= "20221001" && nim[i] <= "20221099") {
            prodiMahasiswa[i] = prodi[0]; // TMI
            jenjangMahasiswa[i] = jenjang[0];
        }
        else if (nim[i] >= "20222001" && nim[i] <= "20222099") {
            prodiMahasiswa[i] = prodi[1]; // TMK
            jenjangMahasiswa[i] = jenjang[0];
        }
        else if (nim[i] >= "20223001" && nim[i] <= "20223099") {
            prodiMahasiswa[i] = prodi[2]; // TPM
            jenjangMahasiswa[i] = jenjang[0];
        }
        else if (nim[i] >= "20224001" && nim[i] <= "20224099") {
            prodiMahasiswa[i] = prodi[3]; // RTM
            jenjangMahasiswa[i] = jenjang[1];
        }
        else if (nim[i] >= "20225001" && nim[i] <= "20225099") {
            prodiMahasiswa[i] = prodi[4]; // PM
            jenjangMahasiswa[i] = jenjang[1];
        }
        else if (nim[i] >= "20226001" && nim[i] <= "20226099") {
            prodiMahasiswa[i] = prodi[5]; // TRMK
            jenjangMahasiswa[i] = jenjang[1];
        }
        else {
            cout << "NIM tidak valid" << endl;
        }
    }
    system("cls");
    cout << "\t\tData Mahasiswa ATMI" << endl << samadengan << samadengan << endl;
    for (int i = 0; i < jumlahMahasiswa; i++) {
        cout << nim[i] << "\t" << nama[i] << "\t" << prodiMahasiswa[i] << "\t" << jenjangMahasiswa[i] << endl;
    }
    cout << "Kembali ke Menu (y/t) ?  ";
    cin >> yt;
    cout << endl;

}

void judulstart() {
    system("cls");
    cout << "       Data Mahasiswa Politeknik ATMI" << endl << samadengan << samadengan << endl;
    cout << "1. Input Data Mahasiswa" << endl;
    cout << "2. Urutkan Daftar Mahasiswa" << endl;
    cout << "3. Exit Program" << endl;
    cout << "pilihan anda: ";
    cin >> opsi;
}

int main() {
awal:
    judulstart();
    switch (opsi) {
    case 1:
    inputan:
        inputdata();
        cout << "Kembali ke Menu (y/t) ?  ";
        cin >> yt;
        cout << endl;
        if (yt == 'Y' || yt == 'y') {
            goto awal;
        }
        if (yt == 'T' || yt == 't') {
            goto sorting;
        }
    case 2:
    sorting:
        sortdatamahasiswa();
        if (yt == 'Y' || yt == 'y') {
            goto awal;
        }
        if (yt == 'T' || yt == 't') {
            goto sorting;
        }
    case 3:
        goto akhir;
    default:
        cout << "invalid input" << endl;
        goto awal;
    }
akhir:
    system("cls");
    cout << "Sampai Jumpa" << endl;
    return 0;
}