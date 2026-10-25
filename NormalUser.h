#ifndef NORMALUSER_H
#define NORMALUSER_H

#include "User.h"

class NormalUser : public User {
public:
    NormalUser(int id, string name, string pass);

    string getRole() const override;
    void showDashboard() const override;
};

#endif