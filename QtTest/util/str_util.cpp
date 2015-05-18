#include "str_util.h"

Str_Util::Str_Util()
{

}

Str_Util::~Str_Util()
{

}
QString Str_Util::getStringFromUnsignedChar( unsigned char *str, const int len ){
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
