#ifndef USERMENAGER_H
#define USERMENAGER_H

#include <iostream>
#include <vector>

#include "User.h"
#include "AdditionalMethods.h"
#include "FileWithUsers.h"

using namespace std;

class UserMenager
{
    int idLoggedUser;
    vector<User> users;

    FileWithUsers fileWithUsers;

    User giveNewUserDetails();
    int getUserIdForNewUser();
    bool isLoginExist(string login);

public:
    UserMenager(string fileNameWithUsers) : fileWithUsers (fileNameWithUsers)
    {
        idLoggedUser = 0;
        users=fileWithUsers.loadUsersFromFile();
    }
    void userRegistration();
    int userLogin();
    int getUserIdFromLoggedUser();
    void changePasswordForLoggedUser();
    int userLogout();
    bool isUserLogged();

    //temp methods
    void displayAllUsers();

};

#endif // USERMENAGER_H
