#include <iostream>
#include <limits>
#include "UserManager.h"
#include "AuthExceptions.h"

int main() {
    UserManager manager;
    int choice;

    do {
        std::cout << "\n=== Secure Authentication System ===\n";
        std::cout << "1. Register\n2. Login (Role Access & OTP)\n3. Forgot Password (OTP Recovery)\n4. Display All Users\n5. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        try {
            if (choice == 1) {
                std::string uname, pwd, email, role;
                std::cout << "Enter username: "; std::cin >> uname;
                std::cout << "Enter password: "; std::cin >> pwd;
                std::cout << "Enter email: "; std::cin >> email;
                std::cout << "Enter role (admin/user): "; std::cin >> role;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                
                manager.registerUser(uname, pwd, email, role);
                std::cout << "Registration successful!\n";

            } else if (choice == 2) {
                std::string uname, pwd;
                std::cout << "Enter username: "; std::cin >> uname;
                std::cout << "Enter password: "; std::cin >> pwd;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                User* loggedInUser = manager.loginUser(uname, pwd);
                if (loggedInUser) {
                    std::cout << "Credentials verified! Sending secondary OTP...\n";
                    manager.generateAndSendOTP(uname);
                    
                    std::string otp;
                    std::cout << "Enter the OTP sent to your email: ";
                    std::cin >> otp;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                    if (manager.verifyOTP(uname, otp)) {
                        std::cout << "Login fully successful! Welcome, " << loggedInUser->getUsername() << "\n";
                        loggedInUser->displayDashboard(); // Opens interactive admin/user dashboard loop
                    }
                }

            } else if (choice == 3) {
                std::string uname, otp, newPwd;
                std::cout << "Enter your username for recovery: "; std::cin >> uname;
                
                manager.generateAndSendOTP(uname);
                
                std::cout << "Enter OTP received: "; std::cin >> otp;
                std::cout << "Enter new password: "; std::cin >> newPwd;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                
                manager.recoverPassword(uname, otp, newPwd);

            } else if (choice == 4) {
                manager.displayAllUsers();
            }
        } catch (const AuthException& e) {
            std::cout << e.what() << '\n';
        } catch (const std::exception& e) {
            std::cout << "An unexpected error occurred: " << e.what() << '\n';
        }

    } while (choice != 5);

    return 0;
}