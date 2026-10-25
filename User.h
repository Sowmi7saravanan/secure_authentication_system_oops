#ifndef USER_H
#define USER_H

#include <string>

class User {
protected:
    std::string username;
    std::string password;
    std::string email;
    std::string role;

public:
    User(std::string uname, std::string pwd, std::string mail, std::string r);
    virtual ~User() = default;

    std::string getUsername() const;
    std::string getEmail() const;
    std::string getRole() const;
    bool checkPassword(std::string pwd) const;
    void setPassword(std::string newPwd);

    virtual void displayDashboard() = 0; // Polymorphic function
};

#endif