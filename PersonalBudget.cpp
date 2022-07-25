#include "PersonalBudget.h"

void PersonalBudget::userRegistration()
{
    userMenager.userRegistration();
}

void PersonalBudget::userLogin()
{
    while (userMenager.getUserIdFromLoggedUser() == 0)
    {
        userMenager.userLogin();
    }
    if (userMenager.getUserIdFromLoggedUser() != 0)
        accountMovementMenager = new AccountMovementMenager(FILE_NAME_WITH_INCOMES, FILE_NAME_WITH_EXPANSES, userMenager.getLoggedUser());
}

void PersonalBudget::changePasswordForLoggedUser()
{
    userMenager.changePasswordForLoggedUser();
}

void PersonalBudget::userLogout()
{
    userMenager.userLogout();
    delete accountMovementMenager;
    accountMovementMenager = NULL;
}

bool PersonalBudget::isUserLogged()
{
    return userMenager.isUserLogged();
}

char PersonalBudget::chooseActionsFromMainMenu()
{
    char choose;

    system("clear");
    cout << "    >>> MAIN MENU<<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Registration" << endl;
    cout << "2. Login" << endl;
    cout << "9. Exit" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choise: ";
    choose = AdditionalMethods::loadChar();

    return choose;
}

char PersonalBudget::chooseActionsFromPersonalBudgetMenu()
{
    char choose;

    system("clear");
    cout << " >>> PERSONAL BUDGET MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Add income" << endl;
    cout << "2. Add expense" << endl;
    cout << "3. Current month balance" << endl;
    cout << "4. Previous month balance" << endl;
    cout << "5. Selected period balance" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Change password" << endl;
    cout << "0. Logout" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choise: ";
    choose = AdditionalMethods::loadChar();

    return choose;
}

int PersonalBudget::getUserIdFromLoggedUser()
{
    userMenager.getUserIdFromLoggedUser();
}

void PersonalBudget::addIncome()
{
    if (userMenager.isUserLogged())
    {
        accountMovementMenager->addIncome();
    }
    else
    {
        cout << "Please login before add account movemenet." << endl;
        cin.get();
    }
}

void PersonalBudget::addExpense()
{
    if (userMenager.isUserLogged())
    {
        accountMovementMenager->addExpense();
    }
    else
    {
        cout << "Please login before add account movemenet." << endl;
        cin.get();
    }
}

void PersonalBudget::showCurrentMonthBalance()
{
    accountMovementMenager->showCurrentMonthBalance();
}

void PersonalBudget::showPreviousMonthBalance()
{
    accountMovementMenager->showPreviousMonthBalance();
}

void PersonalBudget::showSelectedPeriodBalance()
{
    accountMovementMenager->showSelectedPeriodBalance();
}

// temp
void PersonalBudget::displayAllUsers()
{
    userMenager.displayAllUsers();
}

//    accountMovementMenager.displayAllAccountMovement(accountMovementMenager.incomes);
//    accountMovementMenager.displayAllAccountMovement(accountMovementMenager.expenses);