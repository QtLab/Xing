#ifndef STR_UTIL_H
#define STR_UTIL_H
#include <QString>

class Str_Util
{
public:
    Str_Util();
    ~Str_Util();
    static QString getStringFromUnsignedChar( unsigned char *str, const int len );
};

#endif // STR_UTIL_H
