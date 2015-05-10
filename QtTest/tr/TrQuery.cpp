#include "TrQuery.h"

TrQuery::TrQuery(const QWidget& widget, QObject *parent):m_hwnd((HWND)widget.winId()),QObject(parent)
{

}

TrQuery::~TrQuery()
{

}

long TrQuery::changeStringToLong(char *strLong, int length)
{
    int multiply = 1;
    long result = 0;

    for (int i=length-1; i>=0; i--) {
        result += ((unsigned int)(strLong[i] - '0') * multiply);
        multiply *= 10;
    }

    return result;
}

