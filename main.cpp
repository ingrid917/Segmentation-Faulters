#include <iostream>
#include "User/UserRepository.h"
#include "User/UserServices.h"
void teste();

int main() {
    int opt;
    std::cout << "1. Ruleaza aplicatia\n2. Ruleaza teste\nAlege: ";
    std::cin >> opt;

    if (opt == 2) {
        teste();
        return 0;
    }

    UserRepository repo;
    repo.addUser(User("admin@store.com", "parola123", "employee"));

    std::string email, password;
    std::cout << "Email: ";
    std::cin >> email;
    std::cout << "Password: ";
    std::cin >> password;

    if (AuthService::login(repo, email, password)) {
        std::cout << "Login successful!\n";
    } else {
        std::cout << "Invalid credentials.\n";
    }

    return 0;
}
