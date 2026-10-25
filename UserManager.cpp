#include "UserManager.h"
#include "NormalUser.h"
#include "Admin.h"
#include <iostream>

using namespace std;

UserManager::UserManager() {

    nextUserId = 1;

    shared_ptr<User> admin =
        make_shared<Admin>(
            nextUserId,
            "admin",
            "admin123"
        );

    users.push_back(admin);

    nextUserId++;
}

bool UserManager::usernameExists(string username) {

    for (const shared_ptr<User>& user : users) {

        if (user->getUsername() == username) {
            return true;
        }
    }

    return false;
}

bool UserManager::isValidPassword(string password) {

    if (password.length() < 6) {
        return false;
    }

    return true;
}

void UserManager::registerUser(string username, string password) {

    if (username.length() < 3) {
        cout << "Username must contain at least 3 characters!" << endl;
        return;
    }

    if (usernameExists(username)) {
        cout << "Username already exists!" << endl;
        return;
    }

    if (!isValidPassword(password)) {
        cout << "Password must contain at least 6 characters!" << endl;
        return;
    }

    shared_ptr<User> newUser =
        make_shared<NormalUser>(
            nextUserId,
            username,
            password
        );

    users.push_back(newUser);

    cout << "Registration successful!" << endl;
    cout << "Your User ID is: " << nextUserId << endl;

    nextUserId++;
}

bool UserManager::loginUser(string username, string password) {

    for (shared_ptr<User>& user : users) {

        if (user->getUsername() == username) {

            if (user->getIsLocked()) {
                cout << "Account is locked! Contact administrator." << endl;
                return false;
            }

            if (user->checkPassword(password)) {

                user->resetFailedAttempts();

                cout << "Login successful!" << endl;

                user->showDashboard();

                return true;
            }
            else {

                user->recordFailedAttempt();

                cout << "Incorrect password!" << endl;

                if (user->getIsLocked()) {
                    cout << "Too many failed attempts. Account locked!" << endl;
                }

                return false;
            }
        }
    }

    cout << "User not found!" << endl;

    return false;
}

void UserManager::displayAllUsers() {

    if (users.empty()) {
        cout << "No users registered yet." << endl;
        return;
    }

    cout << "\n----- Registered Users -----\n";

    for (const shared_ptr<User>& user : users) {

        user->displayUser();

        cout << "Role: " << user->getRole() << endl;

        cout << "----------------------------\n";
    }
}