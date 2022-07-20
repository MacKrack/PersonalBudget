#include "FileRegisteringAccountMovements.h"

void FileRegisteringAccountMovements::addMovementToFile (AccountMovement accountMovement, string fileName)
{
    CMarkup xml;
    bool fileExists = xml.Load(fileName);
    if(!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Movements");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Movement");
    xml.IntoElem();
    {
        xml.AddElem("MoveId", accountMovement.getMoveId());
        xml.AddElem("UserId", accountMovement.getUserId());
        xml.AddElem("Date", AdditionalMethods::conversionIntDateToStringDate(accountMovement.getDate()));
        xml.AddElem("MoveDetail", accountMovement.getMoveDetails());
        xml.AddElem("Amount", accountMovement.getStringAmount());
    }
    xml.OutOfElem();
    xml.Save(fileName);
}

vector<AccountMovement> FileRegisteringAccountMovements::loadMovementFromFile(string fileName, int idOfLoggedUser)
{
    vector <AccountMovement> accountMovements;
    CMarkup xml;
    xml.Load(fileName);
    xml.FindElem("Movements");
    xml.IntoElem();
    while (xml.FindElem("Movement"))
    {
        AccountMovement accountMovement;
        xml.IntoElem();
        xml.FindElem("MoveId");
        accountMovement.setMoveId(atoi(MCD_2PCSZ(xml.GetData())));
        xml.FindElem("UserId");
        accountMovement.setUserId(atoi(MCD_2PCSZ(xml.GetData())));
        xml.FindElem("Date");
        accountMovement.setDate(AdditionalMethods::conversionStringDateTointDate(xml.GetData()));
        xml.FindElem("MoveDetail");
        accountMovement.setMoveDetails(xml.GetData());
        xml.FindElem("Amount");
        accountMovement.setAmount(AdditionalMethods::conversionStringToDouble(xml.GetData()));
        accountMovements.push_back(accountMovement);
        xml.OutOfElem();
    }
    return accountMovements;
}
