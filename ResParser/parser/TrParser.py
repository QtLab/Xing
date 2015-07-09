#-*- coding: utf-8 -*-
__author__ = 'YONGSUK'
import sys
class TrField:
    def __init__(self, hname, fieldname, datatype, size):
        self.hname = hname
        self.fieldname = fieldname
        self.datatype = datatype
        self.size = size
    def __str__(self) :
        return 'hname={0}, fieldname={1}, datatype={2}, size={3}'.format(self.hname, self.fieldname, self.datatype, self.size)

class TrOutBlock :
    def __init__(self, trName, outblockname) :
        self.trName = trName
        self.outblockname = outblockname
        self.fieldList = []
    def addField(self, field):
        self.fieldList.append(field)
    def __str__(self) :
        description = self.outblockname+'\n'
        for trField in self.fieldList :
            description = description + trField.__str__()+'\n'
        return description

class TrInBlock :
    def __init__(self, trName,inblockname) :
        self.trName = trName
        self.inblockname = inblockname
        self.fieldList = []
    def addField(self, field):
        self.fieldList.append(field)
    def __str__(self) :
        description = self.inblockname+'\n'
        for trField in self.fieldList :
            description = description + trField.__str__()+'\n'
        return description

class TrParser:
    FILE_PATH='c:/eBEST/xingAPI/Res/'
    def __init__(self, trName):
        self.trName = trName
        self.dataMap = dict()
    def parse(self):
        with open(self.FILE_PATH+self.trName+'.res') as f :
            trLine = f.readline().strip()
            while trLine :
                if trLine.startswith(self.trName) :
                    field = trLine.split(',');
                    if field[0].endswith('OutBlock') or field[0].endswith('OutBlock1') :
                        outblock = self.readOutBlock(f, field[0])
                        self.dataMap[outblock.outblockname] = outblock
                    elif field[0].endswith('InBlock') :
                        inblock = self.readInBlock(f, field[0])
                        self.dataMap[inblock.inblockname] = inblock
                trLine = f.readline().strip()

    def getInBlock(self):
        return self.dataMap[self.trName+'InBlock']

    def getOutBlock(self):
        if self.trName+'OutBlock' in self.dataMap.keys() :
            return self.dataMap[self.trName+'OutBlock']
        else :
            return None
    def getOutBlock1(self):
        if self.trName+'OutBlock1' in self.dataMap.keys() :
            return self.dataMap[self.trName+'OutBlock1']
        else :
            return None


    def readOutBlock(self, fp, outblockname):
        outblock = TrOutBlock(self.trName, outblockname)
        line = fp.readline().strip()

        if line != 'begin' :
            return
        line = fp.readline().strip()

        while line != 'end' :
            field = line.split(',')
            trField = TrField(field[0], field[1], field[3], field[4])
            outblock.addField(trField)
            line = fp.readline().strip()
        return outblock

    def readInBlock(self, fp, inblockname):
        inblock = TrInBlock(self.trName, inblockname)
        line = fp.readline().strip()

        if line != 'begin' :
            return
        line = fp.readline().strip()

        while line != 'end' :
            field = line.split(',')
            trField = TrField(field[0], field[1], field[3], field[4])
            inblock.addField(trField)
            line = fp.readline().strip()
        return inblock

class TrHeaderMaker :
    dataTypeMap = {'char':'QString', 'long':'long', 'float':'float'}
    def __init__(self,headerInfo):
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
        self.__line('\n#endif //'+self.headerInfo.trName.upper()+'ITEM')
    def __line(self, line):
        self.lines.append(line)
    def __addPreprocessor(self):
        self.__line('#ifndef '+self.headerInfo.trName.upper()+'ITEM')
        self.__line('#define '+self.headerInfo.trName.upper()+'ITEM')
        self.__line('')
        pass
    def __addHeader(self):
        self.__line('#include <QObject>')
        self.__line('#include <QString>')
        self.__line('#include <QDate>')
        self.__line('#include "tr/tritem.h"')
        self.__line('#include "tr/'+self.headerInfo.trName+'/'+self.headerInfo.trName+'.h')
    def __addClassDef(self):
        self.__line('class '+self.headerInfo.trName.title()+'Item : public TrItem')
        self.__line('{')
        self.__line('\tQ_OBJECT')
    def __addProperty(self):
        for trField in self.headerInfo.fieldList:
            self.__line('\tQ_PROPERTY('+self.__getDataType(trField)+' '+trField.fieldname+' MEMBER'+' _'+trField.fieldname+' READ '+trField.fieldname+' WRITE set'+trField.fieldname.title()+')\t\t//'+trField.hname)
    def __getDataType(self, field):
        if field.hname.endswith('시간') :
            return 'QTime'
        elif field.hname.endswith('일') or field.hname.endswith('일자') :
            return 'QDate'
        else :
            return self.dataTypeMap[field.datatype]
    def __addConstructor(self):
        self.__line('\texplicit '+self.headerInfo.trName.title()+'Item('+'LP'+self.headerInfo.outblockname+' outblock, QObject *parent=0);')
    def __addDestructor(self):
        self.__line('\t~'+self.headerInfo.trName.title()+'Item();')
    def __addPublicMethod(self):
        for trField in self.headerInfo.fieldList:
            self.__line('\t'+self.__getDataType(trField)+' '+trField.fieldname+'() { return _'+trField.fieldname+'; }')
            self.__line('\tvoid set'+trField.fieldname.title()+'('+self.__getDataType(trField)+' '+trField.fieldname+') { _'+trField.fieldname+' = '+trField.fieldname+'; }')
    def __addPrivateField(self):
        for trField in self.headerInfo.fieldList:
            self.__line('\t'+self.__getDataType(trField)+' _'+trField.fieldname+';\t\t//'+trField.hname)

class TrCppMaker :
    dataTypeMap = {'char':'GET_STRING_FROM_FIELD', 'long':'GET_LONG_FROM_FIELD', 'float':'GET_FLOAT_FROM_FIELD'}
    def __init__(self, headerInfo):
        self.headerInfo = headerInfo
        self.lines = []
    def make(self):
        self.__addPreprocessor()
        self.__line('')
        self.__addConstructor()
        self.__initField()
        self.__line('')
        self.__definePropertyName()
        self.__line('}')
        self.__addDestructor()
    def __line(self, line):
        self.lines.append(line)
    def __addPreprocessor(self):
        self.__line('#include "tr/'+self.headerInfo.trName+'/'+self.headerInfo.trName+'item.h"')
        self.__line('#include "util/fieldutil.h"')
        self.__line('#include <QDebug>')
    def __addConstructor(self):
        self.__line(self.headerInfo.trName.title()+'Item::'+self.headerInfo.trName.title()+'Item(LP'+self.headerInfo.outblockname+' outblock, QObject *parent):TrItem(parent)')
        self.__line('{')
    def __initField(self):
        for trField in self.headerInfo.fieldList:
            self.__line('\t_'+trField.fieldname+' = '+self.__getMacroType(trField)+'(outblock->'+trField.fieldname+');')
    def __definePropertyName(self):
        for trField in self.headerInfo.fieldList:
            hname = trField.hname.split('(')[0]
            self.__line('\tDEFINE_PROPERTY_NAME("'+hname+'","'+trField.fieldname+'");')
    def __addDestructor(self):
        self.__line(self.headerInfo.trName.title()+'Item::~'+self.headerInfo.trName.title()+'Item()')
        self.__line('{')
        self.__line('\tqDebug()<<"'+self.headerInfo.trName.title()+'Item destroyed";')
        self.__line('}')

    def __getMacroType(self, field):
        if field.hname.endswith('시간') :
            return 'GET_TIME_FROM_FIELD'
        elif field.hname.endswith('일') or field.hname.endswith('일자') :
            return 'GET_DATE_FROM_FIELD'
        else :
            return self.dataTypeMap[field.datatype]
if __name__ == '__main__' :
    trName = sys.argv[1]
    print(trName)
    parser = TrParser(trName)
    parser.parse()

    outblock = parser.getOutBlock()
    maker = TrHeaderMaker(outblock)
    maker.make()
    with open(trName+'item.h','w') as fp:
        for line in maker.lines:
            fp.write(line)
            fp.write('\n')
    cppMaker = TrCppMaker(outblock)
    cppMaker.make()
    with open(trName+'item.cpp','w') as fp:
        for line in cppMaker.lines:
            fp.write(line)
            fp.write('\n')

