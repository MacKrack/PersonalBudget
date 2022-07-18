#include "AccountMovement.h"

void AccountMovement::setMoveId(int newMoveId)
{
    moveId=newMoveId;
}

void AccountMovement::setUserId(int newUserId)
{
    userId=newUserId;
}

void AccountMovement::setDate(int newDate)
{
    date=newDate;
    stringDate=AdditionalMethods::conversionIntToString(date);
    stringDate.insert(6,"-");
    stringDate.insert(4,"-");
}

void AccountMovement::setMoveDetails(string newMoveDetails)
{
    moveDetails=newMoveDetails;
}

void AccountMovement::setAmount(double newAmount)
{
    amount=newAmount;
    stringAmount=AdditionalMethods::conversionDoubleToString(amount);
}

int AccountMovement::getMoveId()
{
    return moveId;
}

int AccountMovement::getUserId()
{
    return userId;
}

int AccountMovement::getDate()
{
    return date;
}

string AccountMovement::getMoveDetails()
{
    return moveDetails;
}

double AccountMovement::getAmount()
{
    return amount;
}

string AccountMovement::getStringDate()
{
    return stringDate;
}

string AccountMovement::getStringAmount()
{
    return stringAmount;
}
