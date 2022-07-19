#include "UserMenager.h"

void UserMenager::userRegistration()
{
    User user = giveNewUserDetails();

    users.push_back(user);
    fileWithUsers.addUserToFile(user);

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

int UserMenager::userLogin()
{
    string login = "", password = "";

    cout << "Enter login: ";
    login=AdditionalMethods::loadLine();

    for (int i=0; i<users.size(); i++)
    {
        if (users[i].getLogin() == login)
        {
            for (int attempsNumber = 3; attempsNumber > 0; attempsNumber--)
            {
                cout << "Enter password. Attempts left: " << attempsNumber << ": ";
                password=AdditionalMethods::loadLine();

                if (users[i].getPassword() == password)
                {
                    cout << endl << "Successfully logged." << endl << endl;
                    system("pause");
                    loggedUser = users[i];
                    return idLoggedUser = users[i].getUserId();
                }
            }
            cout << "Entered wrong password - 3 times." << endl;
            system("pause");
            return idLoggedUser = 0;
        }
    }
    cout << "User with that login does not exist" << endl << endl;
    system("pause");
    return idLoggedUser = 0;
}

void UserMenager::changePasswordForLoggedUser()
{
    string newPassword = "";
    cout << "Enter new password: ";
    newPassword=AdditionalMethods::loadLine();

    for (int i=0; i<users.size(); i++)
    {
        if (users[i].getUserId() == idLoggedUser)
        {
            users[i].setPassword(newPassword);
            loggedUser.setPassword(newPassword);
            cout << "Password changed." << endl << endl;
            system("pause");
        }
    }
    fileWithUsers.changePasswordForLoggedUserInFile(loggedUser);
}

int UserMenager::getUserIdFromLoggedUser()
{
    return idLoggedUser;
}

int UserMenager::userLogout()
{
    return idLoggedUser=0;
}

bool UserMenager::isUserLogged()
{
    if (loggedUser.getUserId()>0)
        return true;
    else
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

User UserMenager::getLoggedUser()
{
    return loggedUser;
}
