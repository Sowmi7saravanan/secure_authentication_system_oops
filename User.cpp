#include "User.h"

User::User(std::string uname, std::string pwd, std::string mail, std::string r)
    : username(uname), password(pwd), email(mail), role(r) {}

std::string User::getUsername() const { return username; }
std::string User::getEmail() const { return email; }
std::string User::getRole() const { return role; }

bool User::checkPassword(std::string pwd) const {
    return password == pwd;
}

void User::setPassword(std::string newPwd) {
    password = newPwd;
}