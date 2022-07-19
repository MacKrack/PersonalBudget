#include "AccountMovementMenager.h"

void AccountMovementMenager::addIncome()
{
    addMovement(incomes, FILE_NAME_WITH_INCOMES, "Income");
}

void AccountMovementMenager::addMovement(vector <AccountMovement> &accountMovements, string fileName, string keyword)
{
    AccountMovement accountMovement;

    string item;
    accountMovement.setMoveId(getNewTransactionId(accountMovements));
    accountMovement.setUserId(copyOfLoggedUser.getUserId());
    char choice = NULL;
    do {
        system("cls");
        cout << "Do you want to add new " << keyword << " with today date? (y/n)" << endl;
        cin.sync();
        choice = AdditionalMethods::loadChar();
        switch (choice) {
        case 'y':
            accountMovement.setDate(DateMenager::getCurrentDate());
            break;
        case 'n':
            cout << "Enter the date (yyyy-mm-dd): ";
            accountMovement.setDate(DateMenager::getUserDate());
            break;
        default:
            cout << "Incorrect choice." << endl;
            break;
        }
    } while (choice!='n' && choice!='y');
    cout << "Enter details of " << keyword << " : ";
    item = AdditionalMethods::loadLine();
    accountMovement.setMoveDetails(item);
    cout << "Enter amount of " << keyword << " : ";
    accountMovement.setAmount(getTransactionAmount());
    accountMovements.push_back(accountMovement);
//    fileWithTransactions.addTransactionToFile(accountMovement, fileName);
    transform(keyword.begin(), keyword.end(), keyword.begin(), ::tolower);
    cout << "Added movement - " << keyword << "." << endl << endl;
    system("pause");
}

int AccountMovementMenager::getNewTransactionId(vector <AccountMovement> accountMovements)
{
    if (accountMovements.empty() == true)
        return 1;
    else
        return accountMovements.back().getMoveId() + 1;
}

double AccountMovementMenager::getTransactionAmount()
{
    double transactionAmount = 0;
    string stringAmount = "";
    do {
        stringAmount = AdditionalMethods::loadLine();
        if (isTransactionAmountIsCorrectValue(stringAmount)) {
            transactionAmount = convertStringValueToDouble(stringAmount);
            break;
        }
        cout << "Enter correct value: " << endl;
    } while (true);
    return transactionAmount;
}

bool AccountMovementMenager::isTransactionAmountIsCorrectValue(string stringAmount)
{
    int dotCounter = 0;
    for (int i = 0; i < stringAmount.size(); i++)
        {
        int sign = stringAmount[i];
        if (sign == 44 || sign == 46)
        {
            dotCounter++;
            if (stringAmount.size() > i+3)
            {
                cout << "Wrong amount format. Accuracy to 0.01." << endl;
                return false;
            }
        }
        if (((sign < 48) || (sign > 57)) && (sign != 46)&& (sign != 44))
        {
            cout << "Invalid sign in amount." << endl;
            return false;
        }
    }
    if (dotCounter > 1)
    {
        cout << "Wrong amount format: too many commas." << endl;
        return false;
    }
    if (stringAmount.empty())
    {
        cout << "The amount has not been entered." << endl;
        return false;
    }
    return true;
}

double AccountMovementMenager::convertStringValueToDouble(string stringAmount)
{
     double doubleAmount = 0;
    for (int i = 0, j = stringAmount.size()-1; i < stringAmount.size(); i++, j--)
    {
        int sign = stringAmount[i];
        if (sign == 44 || sign == 46)
        {
            doubleAmount = doubleAmount / pow(10,j+1);
            j = 0;
        }
        else
        {
            doubleAmount = doubleAmount + ((sign - 48) * pow(10,j));
        }
    }
    return doubleAmount;
}


void AccountMovementMenager::displayAllIncomes()
{
    if (incomes.empty() == true)
    {
        cout << "No Incomes exist yet." << endl;
        system("pause");
    }
    else
    {
        for (int i=0; i < incomes.size(); i++)
        {
            cout << endl << incomes[i].getUserId() << endl;
            cout << incomes[i].getMoveId() << endl;
            cout << incomes[i].getDate() << endl;
            cout << incomes[i].getMoveDetails() << endl;
            cout << incomes[i].getAmount() << endl;

        }
        system("pause");
    }
}
