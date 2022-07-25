#include <iostream>

#include "PersonalBudget.h"

using namespace std;

int main()
{

    PersonalBudget personalBudget("Users.xml", "Incomes.xml", "Expenses.xml");

    char choice;

    while (true)
    {
        if (personalBudget.isUserLogged())
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
            //    temp
            case '3':
                personalBudget.displayAllUsers();
                break;
                //
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
            if (!personalBudget.isUserLogged())

                choice = personalBudget.chooseActionsFromPersonalBudgetMenu();

            switch (choice)
            {
            case '1':; // ksiazkaAdresowa.dodajAdresata();
                break;
            case '2':; // ksiazkaAdresowa.wyszukajAdresatowPoImieniu();
                break;
            case '3':; // ksiazkaAdresowa.wyszukajAdresatowPoNazwisku();
                break;
            case '4':; // ksiazkaAdresowa.wyswietlWszystkichAdresatow();
                break;
            case '5':; // ksiazkaAdresowa.usunAdresata();
                break;
            case '6':; //;ksiazkaAdresowa.edytujAdresata();
                break;
            case '7':; // ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();
                break;
            case '8':
                personalBudget.userLogout();
                break;
            }
        }
    }
    return 0;
}

// #include "UserMenager.h"
// #include "DateMenager.h"
// #include "AccountMovementMenager.h"

// int main()
// {

//     UserMenager userMenager("Users.xml");

//     userMenager.displayAllUsers();

// //    userMenager.userRegistration();

//     userMenager.userLogin();

// //    userMenager.changePasswordForLoggedUser();

// //    userMenager.userRegistration();
// //    userMenager.userRegistration();
// //    userMenager.userRegistration();

// //    userMenager.displayAllUsers();

//     AccountMovementMenager accountMovementMenager("Incomes.xml", "Expenses.xml", userMenager.getLoggedUser());

//     accountMovementMenager.showCurrentMonthBalance();
//     accountMovementMenager.showPreviousMonthBalance();
//     accountMovementMenager.showSelectedPeriodBalance();

//    accountMovementMenager.displayAllAccountMovement(accountMovementMenager.incomes);
//    accountMovementMenager.displayAllAccountMovement(accountMovementMenager.expenses);

//    accountMovementMenager.addIncome();
//
//    accountMovementMenager.addExpense();
