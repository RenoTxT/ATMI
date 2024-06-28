#include <iostream>
#include <Windows.h>
#include "adminPage.h"
#include "titlePage.h"
#include "systemPage.h"

titlePage tAP;
systemPage sAP;

using namespace std;

string choose;

void adminPage::adminPageCP() {
    tAP.titleAdminCP();
    sAP.systemMenuAdmin1CP();

    cin >> choose;

    // Compare choose with character literals
    if (choose == "1") {
        system("cls");
        cout << "menu pendaftaran" << endl;
    }
    else if (choose == "2") {
        system("cls");
        cout << "login admin" << endl;
    }
    else if (choose == "3") {
        system("cls");
    }
    else {
        cout << "Invalid choice." << endl;
    }
}
