#include "trmetainfo.h"
#include "util/xingutil.h"
#include <QStringList>
#include <QObject>
#include <QFile>
#include <QStringBuilder>

TrMetaInfo::TrMetaInfo(const QString &trName):mTrName(trName),mInBlock(NULL),mOutBlock(NULL),mOutBlock1(NULL)
{
    readTrRes();
}

TrMetaInfo::~TrMetaInfo()
{
    delete mInBlock;
    delete mOutBlock;
    if(mOutBlock1!=NULL)
        delete mOutBlock1;
}

bool TrMetaInfo::hasOutBlock1()
{
    return mOutBlock1 != NULL;
}

TrBlockInfo *TrMetaInfo::getInBlock()
{  
    return mInBlock;
}

TrBlockInfo *TrMetaInfo::getOutBlock()
{
    return mOutBlock;
}

TrBlockInfo *TrMetaInfo::getOutBlock1()
{
    return mOutBlock1;
}

QString TrMetaInfo::toString()
{
    QString desc;
    QTextStream st(&desc);
    st<<mTrName<<"("<<mTitle<<")"<<endl;
    st<<mInBlock->toString()<<endl;
    st<<mOutBlock->toString()<<endl;
    if(hasOutBlock1()) {
        st<<mOutBlock1->toString()<<endl;
    }
    return desc;
}

void TrMetaInfo::readTrRes()
{
    QString fullPath = QString("c:/eBest/xingAPI/Res/%1.res").arg(mTrName);
    QFile file(fullPath);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    QTextStream in(&file);
    while(!in.atEnd()) {
        QString line = in.readLine();
        if(isInBlock(line)){
            processInBlock(in);
        } else if(isOutBlock(line)){
            processOutBlock(in);
        } else if(isOutBlock1(line)) {
            processOutBlock1(in);
        }
    }
}

bool TrMetaInfo::isInBlock(const QString &line)
{
    QString inBlockName = QString("%1InBlock").arg(mTrName);
    QStringList token = line.trimmed().split(",");
    if(inBlockName==token[0]) return true;
    else return false;
}

bool TrMetaInfo::isOutBlock(const QString &line)
{
    QString outBlockName = QString("%1OutBlock").arg(mTrName);
    QStringList token = line.trimmed().split(",");
    if(outBlockName==token[0]) return true;
    else return false;
}

bool TrMetaInfo::isOutBlock1(const QString &line)
{
    QString outBlockName = QString("%1OutBlock1").arg(mTrName);
    QStringList token = line.trimmed().split(",");
    if(outBlockName==token[0]) return true;
    else return false;
}

void TrMetaInfo::processInBlock(QTextStream &in)
{
    while(!in.atEnd()) {
        QString line = in.readLine();
        QString trimmedLine = line.trimmed();
        if(trimmedLine=="begin") {
            mInBlock = new TrBlockInfo(QString("%1InBlock").arg(mTrName));
        } else if(trimmedLine=="end") {
            return;
        } else {
            mInBlock->addField(TrFieldInfo::parse(trimmedLine));
        }
    }
}

void TrMetaInfo::processOutBlock(QTextStream &in)
{
    while(!in.atEnd()) {
        QString line = in.readLine();
        QString trimmedLine = line.trimmed();
        if(trimmedLine=="begin") {
            mOutBlock = new TrBlockInfo(QString("%1OutBlock").arg(mTrName));
        } else if(trimmedLine=="end") {
            return;
        } else {
            mOutBlock->addField(TrFieldInfo::parse(trimmedLine));
        }
    }
}
void TrMetaInfo::processOutBlock1(QTextStream &in)
{
    while(!in.atEnd()) {
        QString line = in.readLine();
        QString trimmedLine = line.trimmed();
        if(trimmedLine=="begin") {
            mOutBlock1 = new TrBlockInfo(QString("%1OutBlock1").arg(mTrName));
        } else if(trimmedLine=="end") {
            return;
        } else {
            mOutBlock1->addField(TrFieldInfo::parse(trimmedLine));
        }
    }
}


TrFieldInfo *TrFieldInfo::parse(const QString &trimmedLine)
{
    QStringList fieldList = trimmedLine.split(',');
    QString korName(fieldList[FIELD_KOR_NAME_INDEX]);
    QString engName(fieldList[FIELD_ENG_NAME_INDEX]);
    QString dataType(fieldList[FIELD_DATA_TYPE_INDEX]);
    QString lengthStr(fieldList[FIELD_DATA_LENGTH_INDEX]);

    bool ok;
    lengthStr = lengthStr.remove(lengthStr.length()-1,1);
    float length = lengthStr.toFloat(&ok);
    if(ok){
        TrFieldInfo* info = new TrFieldInfo(korName,engName,getType(korName,dataType,length),length);
        return info;
    }
}

TrFieldInfo::~TrFieldInfo()
{

}

QString TrFieldInfo::getKorName()
{
    return mKorName;
}

QString TrFieldInfo::getEngName()
{
    return mEngName;
}

TrFieldInfo::DATA_TYPE TrFieldInfo::getDataType()
{
    return mType;
}

float TrFieldInfo::getLength()
{
    return mLength;
}

QString TrFieldInfo::toString()
{
    QString type;
    switch(mType) {
    case TrFieldInfo::CHAR:
        type = QObject::tr("CHAR");
        break;
    case TrFieldInfo::LONG:
        type = QObject::tr("LONG");
        break;
    case TrFieldInfo::LONGLONG:
        type = QObject::tr("LONGLONG");
        break;
    case TrFieldInfo::FLOAT:
        type = QObject::tr("FLOAT");
        break;
    case TrFieldInfo::DATE:
        type = QObject::tr("DATE");
        break;
    case TrFieldInfo::TIME:
        type = QObject::tr("TIME");
        break;

    }
    return QString("%1, %2, %3, %4\n").arg(mKorName).arg(mEngName).arg(type).arg(mLength);
}

TrFieldInfo::DATA_TYPE TrFieldInfo::getType(const QString &hname, const QString &type, int dataSize)
{
    if(hname.endsWith(qkor("일"))||(hname.endsWith(qkor("일자")))){
        return TrFieldInfo::DATE;
    } else if(hname.endsWith(qkor("시간"))){
        return TrFieldInfo::TIME;
    }
    if(type==QObject::tr("char")){
        return TrFieldInfo::CHAR;
    } else if(type==QObject::tr("long")) {
        if(dataSize>9)
            return TrFieldInfo::LONGLONG;
        else
            return TrFieldInfo::LONG;
    } else if(type==QObject::tr("float")) {
        return TrFieldInfo::FLOAT;
    } else {
        return TrFieldInfo::NONE;
    }
}

TrFieldInfo::TrFieldInfo(const QString &korName, const QString &engName, TrFieldInfo::DATA_TYPE type, float length):mKorName(korName), mEngName(engName), mType(type), mLength(length)
{

}


TrBlockInfo::TrBlockInfo(const QString &blockName):mBlockName(blockName)
{

}

TrBlockInfo::~TrBlockInfo()
{
    foreach(TrFieldInfo* info , mFieldMap.values()){
        delete info;
    }
    mFieldMap.clear();
}

TrFieldInfo *TrBlockInfo::getField(const QString &fieldName)
{
    return mFieldMap.value(fieldName);
}

QList<QString> TrBlockInfo::getFieldNameList()
{
    return mFieldMap.keys();
}

QString TrBlockInfo::getBlockName()
{
    return mBlockName;
}

void TrBlockInfo::addField(TrFieldInfo *field)
{
    mFieldMap.insert(field->getEngName(), field);
}

QString TrBlockInfo::toString()
{
    QString desc;
    QTextStream st(&desc);
    st<<mBlockName<<endl;
    st<<"Begin";
    QMap<QString, TrFieldInfo*>::iterator iter;
    for(iter = mFieldMap.begin(); iter != mFieldMap.end(); ++iter){
        st<<"\t"<<iter.value()->toString();
    }
    st<<endl<<"End";
    return desc;
}
