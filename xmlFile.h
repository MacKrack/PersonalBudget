#ifndef XMLFILE_H
#define XMLFILE_H

#include <iostream>
#include <vector>

#include "User.h"
#include "AccountMovement.h"
#include "Markup.h"
#include "AdditionalMethods.h"

using namespace std;

class XmlFile
{
    const string FILE_NAME;

public:
    XmlFile(string fileName) : FILE_NAME(fileName){};

    string getFileName();
};

#endif // XMLFILE_H
