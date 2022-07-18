#ifndef XMLFILE_H
#define XMLFILE_H

#include <iostream>

#include "User.h"
#include "Markup.h"

using namespace std;

class XmlFile
{
    const string FILE_NAME;

public:
    XmlFile(string fileName) : FILE_NAME(fileName){
    }

    string getFileName();
};

#endif // XMLFILE_H
