#ifndef TRMETAINFO_H
#define TRMETAINFO_H
#include <QString>
#include <QMap>
#include <QTextStream>
#define FIELD_KOR_NAME_INDEX 0
#define FIELD_ENG_NAME_INDEX 1
#define FIELD_DATA_TYPE_INDEX 3
#define FIELD_DATA_LENGTH_INDEX 4

#define TR_RES_PATH "c:/eBEST/xingAPI/Res"
class TrFieldInfo
{
public:
    static TrFieldInfo *parse(const QString& trimmedLine);
    ~TrFieldInfo();

    typedef enum {CHAR, LONG, FLOAT, TIME, DATE, NONE } DATA_TYPE;

    QString getKorName();
    QString getEngName();
    DATA_TYPE getDataType();
    float getLength();
    QString toString();
private:
    static DATA_TYPE getType(const QString& hname, const QString& type);
    TrFieldInfo(const QString& korName, const QString& engName, DATA_TYPE type, float length);
    QString mKorName;
    QString mEngName;
    DATA_TYPE mType;
    float mLength;
};
class TrBlockInfo
{
public:
    TrBlockInfo(const QString& blockName);
    ~TrBlockInfo();
    const TrFieldInfo *getField(const QString& fieldName);
    void addField(TrFieldInfo* field);
private:
    QMap<QString, TrFieldInfo*> mFieldMap;
    QString mBlockName;
};

class TrMetaInfo
{
public:
    TrMetaInfo(const QString& trName);
    ~TrMetaInfo();
    bool hasOutBlock1();
    const TrBlockInfo *getInBlock();
    const TrBlockInfo *getOutBlock();
    const TrBlockInfo *getOutBlock1();
private:
    void readTrRes();
    bool isInBlock(const QString &line);
    bool isOutBlock(const QString &line);
    bool isOutBlock1(const QString &line);
    void processInBlock(const QTextStream &in);
    void processOutBlock(const QTextStream &in);
    void processOutBlock1(const QTextStream &in);
private:
    QString mTrName;
    QString mTitle;
    TrBlockInfo* mInBlock;
    TrBlockInfo* mOutBlock;
    TrBlockInfo* mOutBlock1;
};

#endif // TRMETAINFO_H
