#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <conio.h>
#include <ctime>
#include <windows.h>
#include <string>
#include "Admin.h"
#include "User.h"

using namespace std;

class PaintBalldReservation
{
private:
    vector<user> users;
    vector<string> kodePemesananList;
    Admin admin;//Mendeklarasikan objek admin dari kelas Admin
    int stokReguler;
    int stokGold;
    int stokPremium;
    int sisaPembayaran;
    int hargaReguler, hargaGold, hargaPremium;
public:
    PaintBalldReservation() : admin("admin"),stokReguler(5),stokGold(5),stokPremium(1),sisaPembayaran(0){}
    string fasilitasReg[50], fasilitasGold[50], fasilitasPrem[50];; //Mendeklarasikan tiga array string dengan nama fasilitasReg, fasilitasGold, dan fasilitasPrem
    int n;
    void login();
    bool isAdmin(const string& username, const string& password);
    bool isUser(const string& username, const string& password);
    void adminMenu();//admin
    void userMenu();
    void registerUser();//admin
    void editDataMenu();//admin
    void lihatStatusPemesanan();//admin
    void lihatDaftarUser();//admin
    void lihatPrintStokKelas();//admin
    void lihatStokKelas();
    void pesanKelas();
    void hapusPemesanan();//admin
    string getHiddenInput();
};

