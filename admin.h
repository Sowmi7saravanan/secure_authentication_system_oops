#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"

class Admin : public User {
public:
    Admin(int id, string name, string pass);

    string getRole() const override;
    void showDashboard() const override;
};

#endif