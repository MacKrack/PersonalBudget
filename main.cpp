#include <iostream>

#include "PersonalBudget.h"

using namespace std;

int main()
{

    PersonalBudget personalBudget("Users.xml", "Incomes.xml", "Expenses.xml");

    char choice;

    while (true)
    {
        if (personalBudget.getUserIdFromLoggedUser() == 0)
        {
            choice = personalBudget.chooseActionsFromMainMenu();

            switch (choice)
            {
            case '1':
                personalBudget.userRegistration();
                break;
            case '2':
                personalBudget.userLogin();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl
                     << "Choosen option do not exist." << endl
                     << endl;
                cin.get();
                break;
            }
        }
        else
        {
            if (personalBudget.isUserLogged())

                choice = personalBudget.chooseActionsFromPersonalBudgetMenu();

            switch (choice)
            {
            case '1':
                personalBudget.addIncome();
                break;
            case '2':
                personalBudget.addExpense();
                break;
            case '3':
                personalBudget.showCurrentMonthBalance();
                break;
            case '4':
                personalBudget.showPreviousMonthBalance();
                break;
            case '5':
                personalBudget.showSelectedPeriodBalance();
                break;
            case '6':
                personalBudget.changePasswordForLoggedUser();
                break;
            case '0':
                personalBudget.userLogout();
                break;
            }
        }
    }
    return 0;
}
