#include "DateMenager.h"

int DateMenager::getCurrentDate()
{
    int currentDate;
    time_t t = time(0);
    tm* now = localtime(&t);
    currentDate = AdditionalMethods::conversionTmToInt(now);
    return currentDate;
}

int DateMenager::getUserDate()
{
    int integerUserDate = NULL;
    string stringUserDate = "";
    do
    {
        stringUserDate = AdditionalMethods::loadLine();
        if (isDateIsCorrect(stringUserDate))
        {
            integerUserDate = convertStringDateToInt(stringUserDate);
            if (integerUserDate != 0)
                break;
        }
        cout << "Enter correct date: " << endl;
    }
    while (true);
    return integerUserDate;
}

bool DateMenager::isDateIsCorrect(string date)
{
    int dashCounter = 0;
    if (date[0] == '-')
    {
        cout << "Wrong dates form." << endl;
        return false;
    }
    for (int i = 0; i < date.size(); i++)
    {
        int sign = date[i];
        if (((sign < 48) || (sign > 57)) && (sign != 45))
        {
            cout << "Unacceptable character in date." << endl;
            return false;
        }
        else if (sign == 45 && int(date[i+1]) == 45)
        {
            cout << "Wrong dates form." << endl;
            return false;
        }
        if (sign == 45)
        {
            dashCounter++;
        }
    }
    if ((dashCounter != 2) || (date[date.size() - 1] == 45))
    {
        cout << "Wrong dates form." << endl;
        return false;
    }
    return true;
}

int DateMenager::convertStringDateToInt(string date)
{
    int i = 0, year = 0, month = 0, day = 0, intDate = 0;
    time_t t = time(0);
    tm* now = localtime(&t);
    for(; (int(date[i]) >= 48) && (int(date[i]) <= 57); i++)
    {
        year=year*10+int(date[i])-48;
    }
    i++;
    for(; (int(date[i]) >= 48) && (int(date[i]) <= 57); i++)
    {
        month=month*10+int(date[i])-48;
    }
    i++;
    for(; i < date.size(); i++)
    {
        day=day*10+int(date[i])-48;
    }
    if ((year < 2000) || (year > (now->tm_year + 1900)))
    {
        cout << "Incorrect year." << endl;
        return 0;
    }
    if ( ((month < 1) || (month > 12)) || (year == (now->tm_year + 1900) && month > (now->tm_mon + 1)) )
    {
        cout << "Incorrect month." << endl;
        return 0;
    }
    if ((day == 0) || (day > daysInMonth(year,month)))
    {
        cout << "Incorrect day." << endl;
        return 0;
    }
    intDate = (year * pow (10,4)) + (month * pow (10,2)) + day;
    return intDate;
}

int DateMenager::daysInMonth(int year, int month)
{
    if(month < 0 || month > 12)
    {
        cout << "This month do not exist." << endl;
        return 0;
    }

    else if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month ==10 || month == 12)
    {
        return 31;
    }
    else if(month == 4 || month == 6 || month == 9 || month == 11)
    {
        return 30;
    }
    else
    {
        if ((year%4==0 && year%100!=0) || year%400==0)
        {
            return 29;
        }
        else
            return 28;
    }
}
