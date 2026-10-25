#ifndef USER_MANAGER_H
#define USER_MANAGER_H

#include "User.h"
#include <map>
#include <string>

class UserManager {
private:
    std::map<std::string, User*> users;
    std::map<std::string, std::string> otpStore;

public:
    ~UserManager();
    void registerUser(std::string username, std::string password, std::string email, std::string role);
    User* loginUser(std::string username, std::string password);
    
    void generateAndSendOTP(std::string username);
    bool verifyOTP(std::string username, std::string otpInput);
    void recoverPassword(std::string username, std::string otpInput, std::string newPassword);
    
    void displayAllUsers();
};

#endif