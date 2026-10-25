#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"

class Admin : public User {
public:
    Admin(std::string uname, std::string pwd, std::string mail);
    void displayDashboard() override;
};

#endif