#include "Admin.h"
#include <iostream>

using namespace std;

Admin::Admin(int id, string name, string pass)
    : User(id, name, pass) {
}

string Admin::getRole() const {
    return "Admin";
}

void Admin::showDashboard() const {
    cout << "\n===== ADMIN DASHBOARD =====\n";
    cout << "Welcome Admin, " << username << "!\n";
    cout << "Role: " << getRole() << endl;
}