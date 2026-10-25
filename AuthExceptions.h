#ifndef AUTH_EXCEPTIONS_H
#define AUTH_EXCEPTIONS_H

#include <exception>
#include <string>

class AuthException : public std::exception {
protected:
    std::string message;
public:
    AuthException(std::string msg) : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};

class InvalidCredentialsException : public AuthException {
public:
    InvalidCredentialsException() : AuthException("Error: Invalid username or password!") {}
};

class UserAlreadyExistsException : public AuthException {
public:
    UserAlreadyExistsException() : AuthException("Error: User already exists!") {}
};

class InvalidOTPException : public AuthException {
public:
    InvalidOTPException() : AuthException("Error: Invalid or expired OTP!") {}
};

#endif