#include "UserMenager.h"

void UserMenager::userRegistration()
{
    User user = giveNewUserDetails();

    users.push_back(user);
//    fileWithUsers.addUserToFile(user);

    cout << endl << "Account created successfully!" << endl << endl;
    system("pause");
}

User UserMenager::giveNewUserDetails()
{
    User user;

    user.setUserId(getUserIdForNewUser());

    string login;
    do
    {
        cout << "Enter login: ";
        cin >> login;
        user.setLogin(login);
    }
    while (isLoginExist(user.getLogin())==true);

    string password;
    cout << "Enter password: ";
    cin >> password;
    user.setPassword(password);

    return user;
}

int UserMenager::getUserIdForNewUser()
{
    if(users.empty()==true)
        return 1;
    else
        return users.back().getUserId()+1;
}

bool UserMenager::isLoginExist(string login)
{
      for (int i=0; i < users.size(); i++)
    {
        if (users[i].getLogin() == login)
        {
            cout << endl << "User with that login is already exist." << endl;
            return true;
        }
    }
    return false;
}



void UserMenager::displayAllUsers()
{
    if (users.empty() == true)
    {
        cout << "No Users exist yet." << endl;
        system("pause");
    }
    else
    {
        for (int i=0; i < users.size(); i++)
        {
            cout << endl << users[i].getUserId() << endl;
            cout << users[i].getLogin() << endl;
            cout << users[i].getPassword() << endl;
        }
        system("pause");
    }
}
