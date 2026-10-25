#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <vector>
#include <memory>
#include "User.h"

using namespace std;

class UserManager {
private:
    vector<shared_ptr<User>> users;
    int nextUserId;

    bool usernameExists(string username);
    bool isValidPassword(string password);

public:
    UserManager();

    void registerUser(string username, string password);

    bool loginUser(string username, string password);

    void displayAllUsers();
};

#endif