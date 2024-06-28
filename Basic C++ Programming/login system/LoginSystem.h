// LoginSystem.h
#pragma once

#include <string>

using namespace std;

class LoginSystem {
public:
    LoginSystem();

    void displayMenu();
    void login();
    void addParticipant();

private:
    static const int MAX_USERS = 10;

    struct User {
        string username;
        string password;
    };

    User users[MAX_USERS];
    int userCount;       

    void displayLoginScreen();
    bool authenticateUser(const string& username, const string& password);
    void hidePasswordInput(string& password);
};
