#include "UserRepository.h"

void UserRepository::addUser(const User& user) {
    users.push_back(user);
}

User* UserRepository::findUserByEmail(const std::string& email) {
    for (auto& user : users) {
        if (user.getEmail() == email) {
            return &user;
        }
    }
    return nullptr;
}