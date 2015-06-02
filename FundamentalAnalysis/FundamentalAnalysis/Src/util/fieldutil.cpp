#include "fieldutil.h"

FieldUtil::FieldUtil()
{

}

FieldUtil::~FieldUtil()
{

}
QString FieldUtil::getStringFromField( unsigned char *str, const int len ){
    QString result = "";
    int lengthOfString = len;

    // print string in reverse order
    QString s;
    for( int i = 0; i < lengthOfString; i++ ){
        s = QString( "%1" ).arg( str[i], 0, 16 );

        // account for single-digit hex values (always must serialize as two digits)
        if( s.length() == 1 )
            result.append( "0" );

        result.append( s );
    }

    return result;
}

void FieldUtil::setField(char *dst, const QString &src, int length)
{
    memcpy(dst, src.toLocal8Bit(), length);
}

void FieldUtil::setField(char *dst, const QDate &date, int length)
{
    memcpy(dst, date.toString("yyyyMMdd").toLocal8Bit(), length);
}

void FieldUtil::setField(char *dst, int src, int length)
{
    QString str = QString::number(src);
    memcpy(dst, str.toLocal8Bit(), length);
}

QDate FieldUtil::getDateFromField(char *strDate, int length)
{
    return QDate::fromString(QString::fromLocal8Bit(strDate, length), "yyyyMMdd");
}

QString FieldUtil::getStringFromField(char *src, int length)
{
    return QString::fromLocal8Bit(src, length);
}

long FieldUtil::getLongFromField(char *strLong, int length)
{
    int multiply = 1;
    long result = 0;

    for (int i=length-1; i>=0; i--) {
        result += ((unsigned int)(strLong[i] - '0') * multiply);
        multiply *= 10;
    }

    return result;
}

float FieldUtil::getFloatFromField(char *strFloat, int length)
{
    int i, j, multiply;
    float result = 0;

    for (i=0; i<length; i++) {
        multiply = 1;
        for (j=0; j<i; j++)
            multiply *= 10;

        result += (float)((int)(strFloat[length-1-i] - '0') * 0.01 * multiply);
    }

    return result;
}
