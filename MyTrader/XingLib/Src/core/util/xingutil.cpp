#include "core/util/xingutil.h"

QString qkor(const char *strKor)
{
    static QTextCodec *codec = QTextCodec::codecForName("eucKR");
    return codec->toUnicode(strKor);
}
