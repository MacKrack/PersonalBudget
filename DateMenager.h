#ifndef DATEMENAGER_H
#define DATEMENAGER_H

#include <iostream>
#include <ctime>

#include "AdditionalMethods.h"

using namespace std;

class DateMenager
{

public:
    static int getCurrentDate();
    static int getUserDate();
    static bool isDateIsCorrect(string date);
    static int convertStringDateToInt(string date);
    static int daysInMonth(int year, int month);
    static int getFirstDayOfMonth(int date);
    static int getFirstDayOFPreviousMonth(int date);
    static int getLastDayOFPreviousMonth(int date);





};


#endif // DATEMENAGER_H
