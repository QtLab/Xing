__author__ = 'YONGSUK'


class TrQueryMaker:
    def __init__(self, trName, inblockInfo, outblockInfo):
        self.trName = trName
        self.inblockInfo = inblockInfo
        self.outblockInfo = outblockInfo
        self.lines = []

    def make(self):
        pass

    def addHeader(self):
        pass

    def addline(self, line):
        self.lines.append(line)

    def className(self):
        return self.trName.title()+'Query'

    def itemName(self):
        return self.trName.title()+'Item'

    def baseClassName(self):
        return ''

class TrQueryHeaderMaker(TrQueryMaker):
    dataTypeMap = {'char': 'QString', 'long': 'long', 'float': 'float', 'double': 'double'}
    def __init__(self, trName, inblockInfo, outblockInfo):
        TrQueryMaker.__init__(self, trName, inblockInfo, outblockInfo)

    def make(self):
        self.__openPreprocessor()
        self.__addHeader()
        self.__openClassDef()
        self.onDeclareProperty()
        self.addline('public:')
        self.__addDestructor()
        self.onDeclareAccessMethodForProperty()
        self.addline('protected:')
        self.__addConstructor()
        self.__addCreateItemMethod()
        self.addline('private:')
        self.onDeclarePrivateFieldForProperty()
        self.__closeClassDef()
        self.__closePreprocessor()

    def __openPreprocessor(self):
        self.addline('#ifndef ' + self.trName.upper() + 'QUERY')
        self.addline('#define ' + self.trName.upper() + 'QUERY')
        self.addline('')
        pass
    def __addHeader(self):
        self.addline('#include <QObject>')
        self.addline('#include "tr/'+self.baseClassName().lower()+'.h"')
        self.addline('#include "tr/'+self.trName+'/'+self.itemName().lower()+'.h"')
    def __closePreprocessor(self):
        self.addline('#endif')
    def __openClassDef(self):
        self.addline('class ' + self.className() + ' : public '+self.baseClassName())
        self.addline('{')
        self.addline('\tQ_OBJECT')
    def __closeClassDef(self):
        self.addline('};')
    def onDeclareProperty(self):
        pass
    def onDeclareAccessMethodForProperty(self):
        pass
    def onDeclarePrivateFieldForProperty(self):
        pass

    def addTrFieldToProperty(self, fieldList):
        for trField in fieldList:
            self.addline('\tQ_PROPERTY(' + self.__getDataType(
                trField) + ' ' + trField.fieldname + ' MEMBER' + ' _' + trField.fieldname + ' READ ' + trField.fieldname + ' WRITE set' + trField.fieldname.title() + ')\t\t//' + trField.hname)
    def __getDataType(self, field):
        if field.hname.endswith('시간'):
            return 'QTime'
        elif field.hname.endswith('일') or field.hname.endswith('일자'):
            return 'QDate'
        else:
            return self.dataTypeMap[field.datatype]
    def __addConstructor(self):
        self.addline('\texplicit ' + self.className() + '(QObject *parent=0);')

    def __addDestructor(self):
        self.addline('\t~' + self.className() + '();')

    def __addCreateItemMethod(self):
        self.addline('\tvirtual '+self.itemName()+ ' *createItem() override;')

    def addPropertyMethod(self, fieldList):
        for trField in fieldList:
            self.addline('\t' + self.__getDataType(
                trField) + ' ' + trField.fieldname + '() { return _' + trField.fieldname + '; }')
            self.addline('\tvoid set' + trField.fieldname.title() + '(' + self.__getDataType(
                trField) + ' ' + trField.fieldname + ') { _' + trField.fieldname + ' = ' + trField.fieldname + '; }')

    def addPropertyField(self, fieldList):
        for trField in fieldList:
            self.addline('\t' + self.__getDataType(trField) + ' _' + trField.fieldname + ';\t\t//' + trField.hname)



class SimpleTrQueryHeaderMaker(TrQueryHeaderMaker):
    def __init__(self, trName, inblockInfo, outblockInfo):
        TrQueryHeaderMaker.__init__(self, trName, inblockInfo, outblockInfo)
        pass
    def onDeclareProperty(self):
        self.addTrFieldToProperty(self.inblockInfo.fieldList)
    def onDeclareAccessMethodForProperty(self):
        self.addPropertyMethod(self.inblockInfo.fieldList)
    def onDeclarePrivateFieldForProperty(self):
        self.addPropertyField(self.inblockInfo.fieldList)
    def baseClassName(self):
        return 'SimpleTrQuery'

class BlockTrQueryHeaderMaker(TrQueryHeaderMaker):
    def __init__(self, trName, inblockInfo, outblockInfo):
        TrQueryHeaderMaker.__init__(self, trName, inblockInfo, outblockInfo)
        pass
    def onDeclareProperty(self):
        self.addTrFieldToProperty(self.inblockInfo.fieldList)
    def onDeclareAccessMethodForProperty(self):
        self.addPropertyMethod(self.inblockInfo.fieldList)
    def onDeclarePrivateFieldForProperty(self):
        self.addPropertyField(self.inblockInfo.fieldList)
    def baseClassName(self):
        return 'BlockTrQuery'

class CtsTrQueryHeaderMaker(TrQueryHeaderMaker):
    def __init__(self, trName, inblockInfo, outblockInfo, outblockInfo1):
        TrQueryHeaderMaker.__init__(self, trName, inblockInfo, outblockInfo)
        self.outblockInfo1 = outblockInfo1
        pass
    def onDeclareProperty(self):
        fieldList = set(self.inblockInfo.fieldList).union(self.outblockInfo.fieldList)
        self.addTrFieldToProperty(fieldList)
    def onDeclareAccessMethodForProperty(self):
        fieldList = set(self.inblockInfo.fieldList).union(self.outblockInfo.fieldList)
        self.addPropertyMethod(fieldList)
    def onDeclarePrivateFieldForProperty(self):
        fieldList = set(self.inblockInfo.fieldList).union(self.outblockInfo.fieldList)
        self.addPropertyField(fieldList)
    def baseClassName(self):
        return 'CtsTrQuery'

class TrQueryCppMaker(TrQueryMaker):
    def __init__(self, trName, inblockInfo, outblockInfo):
        TrQueryMaker.__init__(self, trName, inblockInfo, outblockInfo)

    def make(self):
        self.__addHeader()
        self.addline('')
        self.__addConstructor()
        self.__addDestructor()
        self.__addCreateItemMethod()

    def __addCreateItemMethod(self):
        self.addline(self.itemName()+' *'+self.className()+'::createItem()')
        self.addline('{')
        self.addline('\treturn new '+self.itemName()+'();')
        self.addline('}')
        
    def __addHeader(self):
        self.addline('#include "'+self.className().lower()+'.h"')

    def __addConstructor(self):
        self.addline(self.className()+'::'+self.className()+'(QObject *parent) : '+self.baseClassName()+'(tr("'+self.trName+'"), parent)')
        self.addline('{')
        self.addline('')
        self.addline('}')

    def __addDestructor(self):
        self.addline(self.className()+'::~'+self.className()+'()')
        self.addline('{')
        self.addline('')
        self.addline('}')


class SimpleTrQueryCppMaker(TrQueryCppMaker):
    def __init__(self, trName, inblockInfo, outblockInfo):
        TrQueryCppMaker.__init__(self, trName, inblockInfo, outblockInfo)

    def baseClassName(self):
        return 'SimpleTrQuery'


class BlockTrQueryCppMaker(TrQueryCppMaker):
    def __init__(self, trName, inblockInfo, outblockInfo):
        TrQueryCppMaker.__init__(self, trName, inblockInfo, outblockInfo)

    def baseClassName(self):
        return 'BlockTrQuery'


class CtsTrQueryCppMaker(TrQueryCppMaker):
    def __init__(self, trName, inblockInfo, outblockInfo, outblockInfo1):
        TrQueryCppMaker.__init__(self, trName, inblockInfo, outblockInfo)
        self.outblockInfo1 = outblockInfo1
    def baseClassName(self):
        return 'CtsTrQuery'