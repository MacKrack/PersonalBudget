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

char AdditionalMethods::loadChar()
{
    string input = "";
    char sign  = {0};
    while (true)
    {
        cin.sync();
        getline(cin, input);

        if (input.length() == 1)
        {
            sign = input[0];
            break;
        }
        cout << "It is not single char. Enter again correctly." << endl;
    }
    return sign;
}

string AdditionalMethods::conversionIntDateToStringDate (int intDate)
{
    string stringDate, stringDay, stringMonth,stringYear;

    int day, month, year, temp;

    day = intDate % 100;

    if(day < 10)
    {
        stringDay = "0" + conversionIntToString(day);
    }
    else
    {
        stringDay = conversionIntToString(day);
    }

    temp = intDate / 100;

    month = temp % 100;

    if(month < 10)
    {
        stringMonth = "0" + conversionIntToString(month);
    }
    else
    {
        stringMonth = conversionIntToString(month);
    }

    year = temp / 100;

    stringYear = conversionIntToString(year);

    stringDate = stringYear + "-" + stringMonth + "-" + stringDay;

    return stringDate;
}
