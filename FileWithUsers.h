#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include <iostream>
#include <vector>

#include "XmlFile.h"

class FileWithUsers : public XmlFile
{

public:
    FileWithUsers(string fileName) : XmlFile (fileName) {};

    void addUserToFile(User user);
    vector<User> loadUsersFromFile();
};

#endif // FILEWITHUSERS_H
