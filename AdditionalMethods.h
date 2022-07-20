#ifndef ADDITIONALMETHODS_H
#define ADDITIONALMETHODS_H

#include <iostream>
#include <sstream>
#include <algorithm>
#include <math.h>
#include <ctime>
#include <cstdlib>

using namespace std;

class AdditionalMethods
{
public:
    static string conversionIntToString(int number);
    static int conversionStringToInt(string number);
    static string loadLine();
    static int conversionTmToInt(tm* &tmDate);
    static string conversionDoubleToString(double number);
    static char loadChar();
    static string conversionIntDateToStringDate(int intDate);
    static int conversionStringDateTointDate(string stringDate);
    static double conversionStringToDouble(string number);


};

#endif // ADDITIONALMETHODS_H
