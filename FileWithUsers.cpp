#include "FileWithUsers.h"

void FileWithUsers::addUserToFile(User user)
{
    CMarkup xml;

    bool fileExists = xml.Load("Users.xml");

    if(!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserId", user.getUserId());
    xml.AddElem("Login", user.getLogin());
    xml.AddElem("Password", user.getPassword());
    xml.Save("Users.xml");
}

vector<User> FileWithUsers::loadUsersFromFile()
{
    vector <User> users;
    CMarkup xml;
    xml.Load("Users.xml");
    xml.FindElem("Users");
    xml.IntoElem();
    while (xml.FindElem("User"))
    {
        User user;
        xml.IntoElem();
        xml.FindElem("UserId");
        user.setUserId(atoi(MCD_2PCSZ(xml.GetData())));
        xml.FindElem("Login");
        user.setLogin(xml.GetData());
        xml.FindElem("Password");
        user.setPassword(xml.GetData());
        xml.OutOfElem();
        users.push_back(user);
    }
    return users;
}

void FileWithUsers::changePasswordForLoggedUserInFile(User loggedUser)
{
    CMarkup xml;
    xml.Load("Users.xml");
    xml.FindElem("Users");
    xml.IntoElem();
    while(xml.FindElem("User"))
    {
        xml.FindChildElem("UserId");
        if(atoi( MCD_2PCSZ(xml.GetChildData())) == loggedUser.getUserId())
        {
            xml.FindChildElem("Password");
            xml.SetChildData(loggedUser.getPassword());
            break;
        }
    }
    xml.Save("Users.xml");
}
