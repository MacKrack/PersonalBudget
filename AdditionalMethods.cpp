#include "AdditionalMethods.h"

string AdditionalMethods::conversionIntToString(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

int AdditionalMethods::conversionStringToInt(string number)
{
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;

    return numberInt;
}

string AdditionalMethods::loadLine()
{
    string entry = "";
    getline(cin >> ws, entry);
    return entry;
}
