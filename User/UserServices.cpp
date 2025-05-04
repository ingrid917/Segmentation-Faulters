#include "UserServices.h"

bool AuthService::login(UserRepository& userRepo, const std::string& email, const std::string& password) {
    User* user = userRepo.findUserByEmail(email);
    return user && user->verifyPassword(password);
}