#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>

#include "UserMenager.h"
#include "AccountMovementMenager.h"

using namespace std;

class PersonalBudget
{
    UserMenager userMenager;
    AccountMovementMenager *accountMovementMenager;
    const string FILE_NAME_WITH_INCOMES;
    const string FILE_NAME_WITH_EXPANSES;

public:
    PersonalBudget(string fileNameWithUsers, string fileNameWithIncomes, string fileNameWithExpanses)
    : userMenager(fileNameWithUsers), FILE_NAME_WITH_INCOMES(fileNameWithIncomes), FILE_NAME_WITH_EXPANSES(fileNameWithExpanses)
    {
        accountMovementMenager = NULL;
    };
    ~PersonalBudget()
    {
        delete accountMovementMenager;
        accountMovementMenager = NULL;
    }

    void userRegistration();
    void userLogin();
    void changePasswordForLoggedUser();
    void userLogout();
    bool isUserLogged();
    char chooseActionsFromMainMenu();
    char chooseActionsFromPersonalBudgetMenu();

// temp
    void displayAllUsers();
    
};

#endif PERSONALBUDGET_H