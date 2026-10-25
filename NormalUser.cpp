#include "NormalUser.h"
#include <iostream>

using namespace std;

NormalUser::NormalUser(int id, string name, string pass)
    : User(id, name, pass) {
}

string NormalUser::getRole() const {
    return "Normal User";
}

void NormalUser::showDashboard() const {
    cout << "\n===== USER DASHBOARD =====\n";
    cout << "Welcome, " << username << "!\n";
    cout << "Role: " << getRole() << endl;
}