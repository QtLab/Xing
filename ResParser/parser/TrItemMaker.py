__author__ = 'YONGSUK'

class TrItemHeaderMaker:
    dataTypeMap = {'char': 'QString', 'long': 'long', 'float': 'float', 'double': 'double'}

    def __init__(self, headerInfo):
        self.headerInfo = headerInfo
        self.lines = []

    def make(self):
        self.__addPreprocessor()
        self.__addHeader()
        self.__addClassDef()
        self.__addProperty()
        self.__line('public:')
        self.__addConstructor()
        self.__addDestructor()
        self.__addPublicMethod()
        self.__line('private:')
        self.__addPrivateField()
        self.__line('};')
        self.__line('\n#endif //' + self.headerInfo.trName.upper() + 'ITEM')

    def __line(self, line):
        self.lines.append(line)

    def __addPreprocessor(self):
        self.__line('#ifndef ' + self.headerInfo.trName.upper() + 'ITEM')
        self.__line('#define ' + self.headerInfo.trName.upper() + 'ITEM')
        self.__line('')
        pass

    def __addHeader(self):
        self.__line('#include <QObject>')
        self.__line('#include <QString>')
        self.__line('#include <QDate>')
        self.__line('#include "tr/tritem.h"')
        # self.__line('#include "tr/'+self.headerInfo.trName+'/'+self.headerInfo.trName+'.h')

    def __addClassDef(self):
        self.__line('class ' + self.headerInfo.trName.title() + 'Item : public TrItem')
        self.__line('{')
        self.__line('\tQ_OBJECT')

    def __addProperty(self):
        for trField in self.headerInfo.fieldList:
            self.__line('\tQ_PROPERTY(' + self.__getDataType(
                trField) + ' ' + trField.fieldname + ' MEMBER' + ' _' + trField.fieldname + ' READ ' + trField.fieldname + ' WRITE set' + trField.fieldname.title() + ')\t\t//' + trField.hname)

    def __getDataType(self, field):
        if field.hname.endswith('시간'):
            return 'QTime'
        elif field.hname.endswith('일') or field.hname.endswith('일자') or field.hname.endswith('날짜'):
            return 'QDate'
        else:
            return self.dataTypeMap[field.datatype]

    def __addConstructor(self):
        self.__line('\texplicit ' + self.headerInfo.trName.title() + 'Item(QObject *parent=0);')

    def __addDestructor(self):
        self.__line('\t~' + self.headerInfo.trName.title() + 'Item();')

    def __addPublicMethod(self):
        for trField in self.headerInfo.fieldList:
            self.__line('\t' + self.__getDataType(
                trField) + ' ' + trField.fieldname + '() { return _' + trField.fieldname + '; }')
            self.__line('\tvoid set' + trField.fieldname.title() + '(' + self.__getDataType(
                trField) + ' ' + trField.fieldname + ') { _' + trField.fieldname + ' = ' + trField.fieldname + '; }')

    def __addPrivateField(self):
        for trField in self.headerInfo.fieldList:
            self.__line('\t' + self.__getDataType(trField) + ' _' + trField.fieldname + ';\t\t//' + trField.hname)


class TrItemCppMaker:
    def __init__(self, headerInfo):
        self.headerInfo = headerInfo
        self.lines = []

    def make(self):
        self.__addPreprocessor()
        self.__line('')
        self.__addConstructor()
        self.__definePropertyName()
        self.__line('}')
        self.__addDestructor()

    def __line(self, line):
        self.lines.append(line)

    def __addPreprocessor(self):
        self.__line('#include "tr/' + self.headerInfo.trName + '/' + self.headerInfo.trName + 'item.h"')
        self.__line('#include <QDebug>')

    def __addConstructor(self):
        self.__line(
            self.headerInfo.trName.title() + 'Item::' + self.headerInfo.trName.title() + 'Item(QObject *parent):TrItem(parent)')
        self.__line('{')

    def __definePropertyName(self):
        for trField in self.headerInfo.fieldList:
            hname = trField.hname.split('(')[0]
            self.__line('\tDEFINE_PROPERTY_NAME("' + hname + '","' + trField.fieldname + '");')

    def __addDestructor(self):
        self.__line(self.headerInfo.trName.title() + 'Item::~' + self.headerInfo.trName.title() + 'Item()')
        self.__line('{')
        self.__line('')
        self.__line('}')
