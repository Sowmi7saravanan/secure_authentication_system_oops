#include "UserManager.h"
#include "Admin.h"
#include "NormalUser.h"
#include "AuthExceptions.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

UserManager::~UserManager() {
    for (auto& pair : users) {
        delete pair.second;
    }
    users.clear();
}

void UserManager::registerUser(std::string username, std::string password, std::string email, std::string role) {
    if (users.find(username) != users.end()) {
        throw UserAlreadyExistsException();
    }

    if (role == "admin" || role == "Admin") {
        users[username] = new Admin(username, password, email);
    } 
    else if (role == "user" || role == "User") {
        users[username] = new NormalUser(username, password, email);
    } 
    else {
        throw AuthException("Error: Invalid role! Please enter 'admin' or 'user'.");
    }
}

User* UserManager::loginUser(std::string username, std::string password) {
    auto it = users.find(username);
    if (it == users.end() || !it->second->checkPassword(password)) {
        throw InvalidCredentialsException();
    }
    return it->second;
}

void UserManager::generateAndSendOTP(std::string username) {
    if (users.find(username) == users.end()) {
        throw AuthException("Error: Username not found!");
    }
    
    srand(static_cast<unsigned int>(time(0)));
    int otpNum = 1000 + rand() % 9000;
    std::string otpStr = std::to_string(otpNum);
    
    otpStore[username] = otpStr;
    
    std::cout << "\n[SIMULATED SMS/EMAIL SERVICE] OTP sent to " << users[username]->getEmail() 
              << " -> CODE: [ " << otpStr << " ]\n";
}

bool UserManager::verifyOTP(std::string username, std::string otpInput) {
    auto it = otpStore.find(username);
    if (it != otpStore.end() && it->second == otpInput) {
        otpStore.erase(username);
        return true;
    }
    throw InvalidOTPException();
}

void UserManager::recoverPassword(std::string username, std::string otpInput, std::string newPassword) {
    if (verifyOTP(username, otpInput)) {
        auto it = users.find(username);
        if (it != users.end()) {
            it->second->setPassword(newPassword);
            std::cout << "Password successfully recovered and updated!\n";
        }
    }
}

void UserManager::displayAllUsers() {
    std::cout << "\n--- Registered Users List ---\n";
    for (const auto& pair : users) {
        std::cout << "Username: " << pair.first << " | Role: " << pair.second->getRole() << " | Email: " << pair.second->getEmail() << "\n";
    }
}