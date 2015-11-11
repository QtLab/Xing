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

    return result.trimmed();
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

QTime FieldUtil::getTimeFromField(char *strTime, int length)
{
    return QTime::fromString(QString::fromLocal8Bit(strTime, length), "hhmmss");
}

QString FieldUtil::getStringFromField(char *src, int length)
{
    return QString::fromLocal8Bit(src, length).trimmed();
}

long FieldUtil::getLongFromField(char *strLong, int length)
{
    QString str = QString::fromLocal8Bit(strLong, length);
    return str.toLong();
}

float FieldUtil::getFloatFromField(char *strFloat, int length)
{
    QString str = QString::fromLocal8Bit(strFloat, length);
    float value1 =  str.toFloat();
    float value2 = value1/100.0f;
    return value2;
}
