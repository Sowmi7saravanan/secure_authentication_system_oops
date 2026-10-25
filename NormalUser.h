#ifndef NORMAL_USER_H
#define NORMAL_USER_H

#include "User.h"

class NormalUser : public User {
public:
    NormalUser(std::string uname, std::string pwd, std::string mail);
    void displayDashboard() override;
};

#endif