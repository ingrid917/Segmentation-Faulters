#include <iostream>
#include "User.h"
#include "../Customer/Customer.h"
#include "UserRepository.h"
#include "UserServices.h"
#include <assert.h>
using namespace std;



void testUserMethods() {
    // Crearea unui utilizator
    User user("test@email.com", "parola123", "customer");

    // Verificarea getter-elor
    assert(user.getEmail() == "test@email.com");
    assert(user.getRole() == "customer");
    assert(user.verifyPassword("parola123") == true);
    assert(user.verifyPassword("wrongPassword") == false);

    cout << "User methods passed!" << endl;
}

void testUserRepository() {
    // Crearea unui repository și adăugarea unui utilizator
    UserRepository repo;
    User user("test@email.com", "parola123", "customer");
    repo.addUser(user);

    // Căutarea utilizatorului după email
    User* foundUser = repo.findUserByEmail("test@email.com");
    assert(foundUser != nullptr);
    assert(foundUser->getEmail() == "test@email.com");
    assert(foundUser->getRole() == "customer");

    cout << "UserRepository methods passed!" << endl;
}

void testAuthService() {
    // Crearea unui repository și a unui utilizator
    UserRepository repo;
    User user("test@email.com", "parola123", "customer");
    repo.addUser(user);

    // Testarea login-ului corect
    assert(AuthService::login(repo, "test@email.com", "parola123") == true);

    // Testarea login-ului greșit
    assert(AuthService::login(repo, "test@email.com", "wrongPassword") == false);
    assert(AuthService::login(repo, "wrong@email.com", "parola123") == false);

    cout << "AuthService methods passed!" << endl;
}

void teste2() {
    testUserMethods();
    testUserRepository();
    testAuthService();

    cout << "All tests passed!" << endl;
}
