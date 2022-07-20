#ifndef FILEREGISTERINGACCOUNTMOVEMENTS_H
#define FILEREGISTERINGACCOUNTMOVEMENTS_H

#include <iostream>
#include <vector>

#include "User.h"
#include "AccountMovement.h"
#include "Markup.h"
#include "AdditionalMethods.h"

using namespace std;

class FileRegisteringAccountMovements
{

public:
    void addMovementToFile(AccountMovement accountMovement, string fileName);
    vector <AccountMovement> loadMovementFromFile(string fileName, int idOfLoggedUser);


};



#endif // FILEREGISTERINGACCOUNTMOVEMENTS_H
