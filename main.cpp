#include <iostream>
#include "UserManager.h"

using namespace std;

int main() {

    UserManager userManager;

    int choice;

    while (true) {

        cout << "\n===== SECURE AUTHENTICATION SYSTEM =====\n";
        cout << "1. Register User\n";
        cout << "2. Login\n";
        cout << "3. Display All Users\n";
        cout << "4. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {

    string username;
    string password;

    // Keep asking until username is valid
    while (true) {
        cout << "Enter username: ";
        cin >> username;

        if (username.length() < 3) {
            cout << "Username must contain at least 3 characters!" << endl;
        }
        else {
            break;
        }
    }

    // Keep asking until password is valid
    while (true) {
        cout << "Enter password: ";
        cin >> password;

        if (password.length() < 6) {
            cout << "Password must contain at least 6 characters!" << endl;
        }
        else {
            break;
        }
    }

    userManager.registerUser(username, password);
}

        else if (choice == 2) {

            string username;
            string password;

            cout << "Enter username: ";
            cin >> username;

            cout << "Enter password: ";
            cin >> password;

            userManager.loginUser(username, password);
        }

        else if (choice == 3) {

            userManager.displayAllUsers();
        }

        else if (choice == 4) {

            cout << "Exiting program..." << endl;
            break;
        }

        else {

            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}