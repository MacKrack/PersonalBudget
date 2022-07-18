#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include <iostream>

#include "XmlFile.h"

class FileWithUsers : public XmlFile
{

public:
    FileWithUsers(string fileName) : XmlFile (fileName) {};

    void addUserToFile(User user);
};

#endif // FILEWITHUSERS_H
