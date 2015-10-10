# -*- coding: utf-8 -*-
__author__ = 'YONGSUK'


class TrField:
    def __init__(self, hname, fieldname, datatype, size):
        self.hname = hname
        self.fieldname = fieldname
        self.datatype = datatype
        self.size = size

    def __str__(self):
        return 'hname={0}, fieldname={1}, datatype={2}, size={3}'.format(self.hname, self.fieldname, self.datatype,
                                                                         self.size)
    def __eq__(self, other):
        if hasattr(other, 'hname') and hasattr(other, 'fieldname') and hasattr(other, 'datatype') and hasattr(other, 'size') :
            return (self.hname == other.hname) and (self.fieldname == other.fieldname) and (self.datatype ==other.datatype) and (self.size == other.size)
        else :
            return False

    def __hash__(self):
        return hash(self.hname)+hash(self.fieldname)+hash(self.datatype)+hash(self.size)


class TrOutBlock:
    def __init__(self, trName, outblockname):
        self.trName = trName
        self.outblockname = outblockname
        self.fieldList = []

    def addField(self, field):
        self.fieldList.append(field)

    def __str__(self):
        description = self.outblockname + '\n'
        for trField in self.fieldList:
            description = description + trField.__str__() + '\n'
        return description


class TrInBlock:
    def __init__(self, trName, inblockname):
        self.trName = trName
        self.inblockname = inblockname
        self.fieldList = []

    def addField(self, field):
        self.fieldList.append(field)

    def __str__(self):
        description = self.inblockname + '\n'
        for trField in self.fieldList:
            description = description + trField.__str__() + '\n'
        return description


class TrParser:
    FILE_PATH = 'c:/eBEST/xingAPI/Res/'

    def __init__(self, trName):
        self.trName = trName
        self.dataMap = dict()

    def parse(self):
        with open(self.FILE_PATH + self.trName + '.res') as f:
            trLine = f.readline().strip()
            while trLine:
                if trLine.startswith(self.trName):
                    trLine = trLine.replace(';', '')
                    field = trLine.split(',')
                    if field[0].endswith('OutBlock'):
                        if self.hasOccursBlock(field) :
                            self.OccursBlockName = 'OutBlock'
                        outblock = self.readOutBlock(f, field[0])
                        self.dataMap[outblock.outblockname] = outblock
                    elif field[0].endswith('OutBlock1'):
                        if self.hasOccursBlock(field) :
                            self.OccursBlockName = 'OutBlock1'
                        outblock = self.readOutBlock(f, field[0])
                        self.dataMap[outblock.outblockname] = outblock
                    elif field[0].endswith('InBlock'):
                        inblock = self.readInBlock(f, field[0])
                        self.dataMap[inblock.inblockname] = inblock
                trLine = f.readline().strip()

    def hasOccursBlock(self, fieldList):
        if fieldList[-1] == 'occurs':
            self.hasOccurs = True
        else:
            self.hasOccurs = False
        return self.hasOccurs

    def getInBlock(self):
        return self.dataMap[self.trName + 'InBlock']

    def getOutBlock(self):
        if self.trName + 'OutBlock' in self.dataMap.keys():
            return self.dataMap[self.trName + 'OutBlock']
        else:
            return None

    def getOutBlock1(self):
        if self.trName + 'OutBlock1' in self.dataMap.keys():
            return self.dataMap[self.trName + 'OutBlock1']
        else:
            return None

    def readOutBlock(self, fp, outblockname):
        outblock = TrOutBlock(self.trName, outblockname)
        line = fp.readline().strip()

        if line != 'begin':
            return
        line = fp.readline().strip()

        while line != 'end':
            field = line.split(',')
            trField = TrField(field[0], field[2], field[3], field[4])
            outblock.addField(trField)
            line = fp.readline().strip()
        return outblock

    def readInBlock(self, fp, inblockname):
        inblock = TrInBlock(self.trName, inblockname)
        line = fp.readline().strip()

        if line != 'begin':
            return
        line = fp.readline().strip()

        while line != 'end':
            field = line.split(',')
            trField = TrField(field[0], field[2], field[3], field[4])
            inblock.addField(trField)
            line = fp.readline().strip()
        return inblock





