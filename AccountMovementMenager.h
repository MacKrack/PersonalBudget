#ifndef ACCOUNTMOVEMENTMENAGER_H
#define ACCOUNTMOVEMENTMENAGER_H

#include <iostream>
#include <vector>
#include <ctime>

#include "AccountMovement.h"
#include "AdditionalMethods.h"
#include "User.h"
#include "DateMenager.h"
#include "FileRegisteringAccountMovements.h"

using namespace std;

class AccountMovementMenager
{

    const string FILE_NAME_WITH_INCOMES;
    const string FILE_NAME_WITH_EXPANSES;
    User copyOfLoggedUser;

    FileRegisteringAccountMovements fileRegisteringAccountMovements;

    void addMovement(vector <AccountMovement> &accountMovements, string fileName, string keyword);
    int getNewTransactionId(vector <AccountMovement> accountMovements);
    double getTransactionAmount();
    bool isTransactionAmountIsCorrectValue(string stringValue);
    double convertStringValueToDouble(string stringValue);


public:


    AccountMovementMenager(string newIncomesFileName, string newExpensesFileName, User newLoggedUser)
    : FILE_NAME_WITH_INCOMES(newIncomesFileName), FILE_NAME_WITH_EXPANSES(newExpensesFileName), copyOfLoggedUser(newLoggedUser)
    {
        incomes = fileRegisteringAccountMovements.loadMovementFromFile(FILE_NAME_WITH_INCOMES, copyOfLoggedUser.getUserId());
        expenses = fileRegisteringAccountMovements.loadMovementFromFile(FILE_NAME_WITH_EXPANSES, copyOfLoggedUser.getUserId());
    };
vector <AccountMovement> incomes;
    vector <AccountMovement> expenses;
    void addIncome();
    void addExpense();


    //temp
    void displayAllAccountMovement(vector <AccountMovement> &accountMovements);

};

#endif // ACCOUNTMOVEMENTMENAGER_H
