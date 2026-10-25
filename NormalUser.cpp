#include "NormalUser.h"
#include <iostream>
#include <limits>

NormalUser::NormalUser(std::string uname, std::string pwd, std::string mail)
    : User(uname, pwd, mail, "User") {}

void NormalUser::displayDashboard() {
    int userChoice;
    do {
        std::cout << "\n=== [User Dashboard] ===\n";
        std::cout << "1. View Profile Information\n";
        std::cout << "2. Update Personal Details\n";
        std::cout << "3. Logout\n";
        std::cout << "Enter user option: ";
        std::cin >> userChoice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (userChoice == 1) {
            std::cout << "\n[Profile Info] Username: " << username << " | Email: " << email << " | Role: " << role << "\n";
        } else if (userChoice == 2) {
            std::cout << "\n[Update Details]: Feature coming soon!\n";
        } else if (userChoice == 3) {
            std::cout << "Logging out of User Dashboard...\n";
        } else {
            std::cout << "Invalid option! Try again.\n";
        }
    } while (userChoice != 3);
}