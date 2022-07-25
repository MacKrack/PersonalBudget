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
    if (!userMenager.isUserLogged())
        return false;
    else
        return true;
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
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj adresata" << endl;
    cout << "2. Wyszukaj po imieniu" << endl;
    cout << "3. Wyszukaj po nazwisku" << endl;
    cout << "4. Wyswietl adresatow" << endl;
    cout << "5. Usun adresata" << endl;
    cout << "6. Edytuj adresata" << endl;
    cout << "---------------------------" << endl;
    cout << "7. Zmien haslo" << endl;
    cout << "8. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choose = AdditionalMethods::loadChar();

    return choose;
}

// temp
void PersonalBudget::displayAllUsers()
{
    userMenager.displayAllUsers();
}