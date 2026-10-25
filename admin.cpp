#include "admin.h"
#include <iostream>
#include <limits>

Admin::Admin(std::string uname, std::string pwd, std::string mail)
    : User(uname, pwd, mail, "Admin") {}

void Admin::displayDashboard() {
    int adminChoice;
    do {
        std::cout << "\n=== [Admin Dashboard] ===\n";
        std::cout << "1. Manage System Configurations\n";
        std::cout << "2. View All Security Logs\n";
        std::cout << "3. Logout\n";
        std::cout << "Enter admin option: ";
        std::cin >> adminChoice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (adminChoice == 1) {
            std::cout << "\n[System Config]: All security policies and user encryption settings are optimal.\n";
        } else if (adminChoice == 2) {
            std::cout << "\n[Security Logs]: No unauthorized login attempts detected.\n";
        } else if (adminChoice == 3) {
            std::cout << "Logging out of Admin Dashboard...\n";
        } else {
            std::cout << "Invalid option! Try again.\n";
        }
    } while (adminChoice != 3);
}