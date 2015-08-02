#include "movementinfo.h"

MovementInfo::MovementInfo():
    PEF_COLUMN_NAME("amt0000"),
    INVESTMENT_C_COLUMN_NAME("amt0001"),
    INSURANCE_COLUMN_NAME("amt0002"),
    INVESTMENT_T_COLUMN_NAME("amt0003"),
    BANK_COLUMN_NAME("amt0004")

{

}

QString MovementInfo::getFieldNameFromType(MovementInfo::TYPE type)
{
    switch(type) {
    case PEF :
        return tr("amt0000");
    case INVESTMENT_C :
        return tr("amt0001");
    case INSURANCE :
        return tr("amt0002");
    case INVESTMENT_T:
        return tr("amt0003");
    case BANK :
        return tr("amt0004");
    case ALLFINANZ :
        return tr("amt0005");
    case NPF :
        return tr("amt0006");
    case CORP:
        return tr("amt0007");
    case INDIVISUAL:
        return tr("amt0008");
    }
}

MovementInfo MovementInfo::createMovementInfo(const QString &shcode, MovementInfo::TYPE type, const QDate &fromDate, const QDate &toDate)
{

}

MovementInfo::~MovementInfo()
{

}

