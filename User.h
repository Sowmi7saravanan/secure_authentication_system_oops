#ifndef USER_H
#define USER_H

#include <string>

using namespace std;

class User {
protected:
    int userId;
    string username;
    string password;

private:
    int failedAttempts;
    bool isLocked;

public:
    User(int id, string name, string pass);

    int getUserId() const;
    string getUsername() const;

    bool checkPassword(string enteredPassword);
    void changePassword(string newPassword);

    bool getIsLocked() const;
    void recordFailedAttempt();
    void resetFailedAttempts();
    void unlockAccount();

    void displayUser() const;

    // Polymorphism
    virtual string getRole() const = 0;
    virtual void showDashboard() const = 0;

    // Virtual destructor
    virtual ~User() = default;
};

#endif