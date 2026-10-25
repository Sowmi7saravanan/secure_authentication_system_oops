#include "User.h"
#include <iostream>

using namespace std;

// Constructor
User::User(int id, string name, string pass) {
    userId = id;
    username = name;
    password = pass;

    failedAttempts = 0;
    isLocked = false;
}

// Getter for User ID
int User::getUserId() const {
    return userId;
}

// Getter for Username
string User::getUsername() const {
    return username;
}

// Check password
bool User::checkPassword(string enteredPassword) {
    return password == enteredPassword;
}

// Change password
void User::changePassword(string newPassword) {
    password = newPassword;
}

// Check if account is locked
bool User::getIsLocked() const {
    return isLocked;
}

// Record failed login attempt
void User::recordFailedAttempt() {

    failedAttempts++;

    if (failedAttempts >= 3) {
        isLocked = true;
    }
}

// Reset failed attempts after successful login
void User::resetFailedAttempts() {
    failedAttempts = 0;
}

// Unlock account
void User::unlockAccount() {
    isLocked = false;
    failedAttempts = 0;
}

// Display user information
void User::displayUser() const {
    cout << "User ID: " << userId << endl;
    cout << "Username: " << username << endl;
}