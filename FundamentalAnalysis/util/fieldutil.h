#ifndef FIELDUTIL_H
#define FIELDUTIL_H
#include <QString>
#include <QDate>
#include <QTime>



#define SET_FIELD(dst, src) FieldUtil::setField(dst, src, sizeof(dst))
#define GET_DATE_FROM_FIELD(src) FieldUtil::getDateFromField(src, sizeof(src))
#define GET_STRING_FROM_FIELD(src) FieldUtil::getStringFromField(src, sizeof(src))
#define GET_STRING_FROM_FIELD_WITH_LENGTH(src, length) FieldUtil::getStringFromField(src, length)
#define GET_LONG_FROM_FIELD(src) FieldUtil::getLongFromField(src, sizeof(src))
#define GET_FLOAT_FROM_FIELD(src) FieldUtil::getFloatFromField(src, sizeof(src))
#define GET_TIME_FROM_FIELD(src) FieldUtil::getTimeFromField(src, sizeof(src))
#define INIT_BLOCK(src,len) memset(src, ' ', len)

class FieldUtil
{
public:
    FieldUtil();
    ~FieldUtil();
    static QString getStringFromField( unsigned char *str, const int len );
    static void setField(char* dst, const QString& src, int length);
    static void setField(char* dst, const QDate& date, int length);
    static void setField(char* dst, int src, int length);
    static QDate getDateFromField(char* strDate, int length);
    static QTime getTimeFromField(char* strTime, int length);
    static QString getStringFromField(char* src, int length);
    static long getLongFromField(char * strLong, int length);
    static float getFloatFromField(char* strFloat, int length);

};

#endif // STR_UTIL_H
