// LoginSystem.cpp
#include "LoginSystem.h"
#include <iostream>
#include <conio.h>

using namespace std;

LoginSystem::LoginSystem() : userCount(0) {
    // Initialize any necessary values in the constructor
}

void LoginSystem::displayLoginScreen() {
    system("cls");
    cout << "=== Login System ===" << endl;
}

bool LoginSystem::authenticateUser(const string& username, const string& password) {
    for (int i = 0; i < userCount; ++i) {
        if (users[i].username == username && users[i].password == password) {
            return true; // Authentication successful
        }
    }
    return false; // Authentication failed
}

void LoginSystem::hidePasswordInput(string& password) {
    password = ""; // Clear the password
    char ch;
    while ((ch = _getch()) != 13) { // 13 is the ASCII code for Enter
        if (ch == 8) { // 8 is the ASCII code for Backspace
            if (!password.empty()) {
                password.pop_back();
                cout << "\b \b"; // Move the cursor back and overwrite the character with a space
            }
        }
        else {
            password.push_back(ch);
            cout << '*';
        }
    }
    cout << endl;
}

void LoginSystem::login() {
    displayLoginScreen();
    cout << "=== Login ===" << endl;

    string username, password;
    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    hidePasswordInput(password);

    if (authenticateUser(username, password)) {
        cout << "Login successful!" << endl;
    }
    else {
        cout << "Login failed. Invalid username or password." << endl;
    }

    cout << "Press Enter to continue...";
    cin.ignore(); // Clear the input buffer
    cin.get();    // Wait for Enter key
}

void LoginSystem::addParticipant() {
    displayLoginScreen();
    cout << "=== Add Participant ===" << endl;

    if (userCount < MAX_USERS) {
        User newUser;
        cout << "Enter username: ";
        cin >> newUser.username;

        cout << "Enter password: ";
        hidePasswordInput(newUser.password);

        users[userCount++] = newUser;
        cout << "Participant added successfully!" << endl;
    }
    else {
        cout << "Maximum number of users reached. Cannot add more participants." << endl;
    }

    cout << "Press Enter to continue...";
    cin.ignore(); // Clear the input buffer
    cin.get();    // Wait for Enter key
}

void LoginSystem::displayMenu() {
    char choice;

    while (true) {
        displayLoginScreen();
        cout << "1. Login" << endl;
        cout << "2. Add Participant" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        choice = _getch();

        switch (choice) {
        case '1':
            login();
            break;
        case '2':
            addParticipant();
            break;
        case '3':
            return;
        default:
            cout << "Invalid choice. Please try again." << endl;
            cout << "Press Enter to continue...";
            cin.ignore(); // Clear the input buffer
            cin.get();    // Wait for Enter key
            break;
        }
    }
}
