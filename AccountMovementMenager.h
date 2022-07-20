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
    vector <AccountMovement> incomes;
    vector <AccountMovement> expenses;
    const string FILE_NAME_WITH_INCOMES;
    const string FILE_NAME_WITH_EXPANSES;
    User copyOfLoggedUser;

    FileRegisteringAccountMovements fileRegisteringAccountMovements;

    struct Comparison
    {
        bool operator()(AccountMovement first, AccountMovement second)
        {
            if(first.getDate() < second.getDate())
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    } dateComparison;

    void addMovement(vector <AccountMovement> &accountMovements, string fileName, string keyword);
    int getNewTransactionId(vector <AccountMovement> accountMovements);
    double getTransactionAmount();
    bool isTransactionAmountIsCorrectValue(string stringValue);
    double convertStringValueToDouble(string stringValue);
    void showBalanceFromCurrentMonth(vector <AccountMovement> accountMovements, string keyword, vector <AccountMovement> accountMovementsSecond, string keywordSecond);
    double sortAndDisplayTransactions(vector <AccountMovement> accountMovements, string keyword, int startDate, int endDate);



public:
    AccountMovementMenager(string newIncomesFileName, string newExpensesFileName, User newLoggedUser)
    : FILE_NAME_WITH_INCOMES(newIncomesFileName), FILE_NAME_WITH_EXPANSES(newExpensesFileName), copyOfLoggedUser(newLoggedUser)
    {
        incomes = fileRegisteringAccountMovements.loadMovementFromFile(FILE_NAME_WITH_INCOMES, copyOfLoggedUser.getUserId());
        expenses = fileRegisteringAccountMovements.loadMovementFromFile(FILE_NAME_WITH_EXPANSES, copyOfLoggedUser.getUserId());
    };

    void addIncome();
    void addExpense();
    void showCurrentMonthBalance();



    //temp
    void displayAllAccountMovement(vector <AccountMovement> &accountMovements);

};

#endif // ACCOUNTMOVEMENTMENAGER_H
