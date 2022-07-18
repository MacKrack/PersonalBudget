#ifndef ACCOUNTMOVEMENT_H
#define ACCOUNTMOVEMENT_H

#include <iostream>
#include "AdditionalMethods.h"

using namespace std;

class AccountMovement
{
    int moveId;
    int userId;
    int date;
    string moveDetails;
    double amount;
    string stringDate;
    string stringAmount;

public:
    void setMoveId(int newMoveId);
    void setUserId(int newUserId);
    void setDate(int newDate);
    void setMoveDetails(string newMoveDetails);
    void setAmount(double newAmount);

    int getMoveId();
    int getUserId();
    int getDate();
    string getMoveDetails();
    double getAmount();
    string getStringDate();
    string getStringAmount();

};

#endif // ACCOUNTMOVEMENT_H
