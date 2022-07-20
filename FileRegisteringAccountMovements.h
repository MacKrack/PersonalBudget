#ifndef FILEREGISTERINGACCOUNTMOVEMENTS_H
#define FILEREGISTERINGACCOUNTMOVEMENTS_H

#include <iostream>
#include <vector>

#include "User.h"
#include "AccountMovement.h"
#include "Markup.h"
#include "AdditionalMethods.h"

class FileRegisteringAccountMovements
{

public:
    void addMovementToFile(AccountMovement accountMovement, string fileName);

};



#endif // FILEREGISTERINGACCOUNTMOVEMENTS_H
