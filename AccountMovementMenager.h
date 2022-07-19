#ifndef ACCOUNTMOVEMENTMENAGER_H
#define ACCOUNTMOVEMENTMENAGER_H

#include <iostream>
#include <vector>
#include <ctime>

#include "AccountMovement.h"
#include "AdditionalMethods.h"
#include "User.h"
#include "DateMenager.h"

using namespace std;

class AccountMovementMenager
{

    const string FILE_NAME_WITH_INCOMES;
    const string FILE_NAME_WITH_EXPANSES;
    User copyOfLoggedUser;


    int getNewTransactionId(vector <AccountMovement> accountMovements);
    double getTransactionAmount();
    bool isTransactionAmountIsCorrectValue(string stringValue);
    double convertStringValueToDouble(string stringValue);


public:
    AccountMovementMenager(string newIncomesFileName, string newExpensesFileName, User newLoggedUser) : FILE_NAME_WITH_INCOMES(newIncomesFileName), FILE_NAME_WITH_EXPANSES(newExpensesFileName), copyOfLoggedUser(newLoggedUser){};

    vector <AccountMovement> incomes;
    vector <AccountMovement> expenses;
    void addMovement(vector <AccountMovement> &accountMovements, string fileName, string keyword);

    void addIncome();
    void addExpense();


    //temp
    void displayAllAccountMovement(vector <AccountMovement> &accountMovements);

};

#endif // ACCOUNTMOVEMENTMENAGER_H
