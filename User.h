#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;

class User
{
    int userId;
    string login;
    string password;

public:
    void setUserId(int newUserId);
    void setLogin(string newLogin);
    void setPassword(string newPassword);

    int getUserId();
    string getLogin();
    string getPassword();

};

#endif // USER_H
