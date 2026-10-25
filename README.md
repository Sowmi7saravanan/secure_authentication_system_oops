# Secure Authentication System (OOPs in C++)

A robust, console-based **Secure Authentication System** built in C++ using Object-Oriented Programming (OOP) principles. This project implements Role-Based Access Control (RBAC), Multi-Factor Authentication via simulated OTP (One-Time Password) verification, password recovery workflows, and custom exception handling.

---

## 🚀 Key Features

* **Object-Oriented Architecture:** Designed with clean class inheritance and polymorphism (`User` base class with derived `Admin` and `NormalUser` classes).
* **Role-Based Access Control (RBAC):** Distinct dashboards and permissions for `Admin` and `NormalUser` roles.
* **Secondary OTP Verification:** Simulated email/SMS service generating secure OTPs required upon login.
* **Password Recovery:** Secure forgot-password workflow utilizing OTP authentication before resetting credentials.
* **Custom Exception Handling:** Dedicated exception classes (`AuthException`, `UserAlreadyExistsException`, etc.) to gracefully catch and manage errors.
* **Robust Input Validation & Buffering:** Managed input streams to prevent console skipping or buffer pollution during interactive menu navigation.
* **In-Memory Storage:** Fast data management utilizing STL containers (`std::map`).

---

## 🛠️ Project Structure

```text
SecureAuthenticationSystem/
│
├── main.cpp                # Entry point and interactive console loop
├── User.h / User.cpp       # Base user class (managing credentials & base attributes)
├── admin.h / admin.cpp     # Admin derived class & interactive dashboard
├── NormalUser.h / .cpp     # Normal User derived class & interactive dashboard
├── UserManager.h / .cpp    # Core logic (Registration, login, OTP generation/verification)
└── AuthExceptions.h        # Custom exception hierarchy


⚙️ Prerequisites
To compile and run this project, you need:

A modern C++ compiler supporting C++11 or higher (e.g., g++ via MinGW or MSYS2).

Git (for version control).

📥 Getting Started & Compilation
1. Clone the Repository
Bash
git clone [https://github.com/Sowmi7saravanan/secure_authentication_system_oops.git](https://github.com/Sowmi7saravanan/secure_authentication_system_oops.git)
cd secure_authentication_system_oops
2. Compile the Code
Using PowerShell or your terminal, run the g++ command to compile all source files together:

PowerShell
g++ main.cpp User.cpp UserManager.cpp admin.cpp NormalUser.cpp -o auth.exe
3. Run the Application
PowerShell
.\auth.exe
🖥️ Usage Guide
When you run the application, you will be presented with the main menu:

Register: Create a new account by providing a username, password, email, and selecting a role (admin or user).

Login (Role Access & OTP): Enter your credentials. If valid, a simulated OTP will be generated and printed to the terminal. Enter the OTP to access your role-specific dashboard.

Forgot Password (OTP Recovery): Enter your username, verify the generated OTP, and securely update your password.

Display All Users: View a directory of registered users in the system.

Exit: Terminate the program.

👨‍💻 Author
Sowmiya Saravanan

GitHub: @Sowmi7saravanan
