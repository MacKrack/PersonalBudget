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
