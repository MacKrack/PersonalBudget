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

int AdditionalMethods::conversionTmToInt(tm* &tmDate)
{
    int intDate;
    intDate = (tmDate->tm_year + 1900) * pow(10,4) + (tmDate->tm_mon + 1) * pow (10,2) + tmDate->tm_mday;
    return intDate;
}

string AdditionalMethods::conversionDoubleToString(double number)
{
    stringstream ss;
    string str;
    ss << number;
    ss >> str;
    return  str;
}

