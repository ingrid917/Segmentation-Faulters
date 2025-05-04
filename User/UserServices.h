#pragma once
#include "UserRepository.h"

class AuthService {
public:
    static bool login(UserRepository& userRepo, const std::string& email, const std::string& password);
};