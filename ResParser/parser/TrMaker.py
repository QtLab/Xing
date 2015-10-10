__author__ = 'YONGSUK'
import sys
from TrParser import TrParser
from TrItemMaker import TrItemCppMaker
from TrItemMaker import TrItemHeaderMaker
from TrQueryMaker import SimpleTrQueryHeaderMaker
from TrQueryMaker import BlockTrQueryHeaderMaker
from TrQueryMaker import CtsTrQueryHeaderMaker
from TrQueryMaker import SimpleTrQueryCppMaker
from TrQueryMaker import BlockTrQueryCppMaker
from TrQueryMaker import CtsTrQueryCppMaker

def makeTrItem(parser):
    outblock = parser.getOutBlock1()
    if outblock is None:  # res file has only OutBlock.
        outblock = parser.getOutBlock()
        maker = TrItemHeaderMaker(outblock)
        maker.make()
        with open(trName + 'item.h', 'w',encoding='utf-8') as fp:
            for line in maker.lines:
                fp.write(line)
                fp.write('\n')
    else:  # Res file has OutBlock and OutBlock1
        maker = TrItemHeaderMaker(outblock)
        maker.make()
        with open(trName + 'item.h', 'w',encoding='utf-8') as fp:
            for line in maker.lines:
                fp.write(line)
                fp.write('\n')
    cppMaker = TrItemCppMaker(outblock)
    cppMaker.make()
    with open(trName + 'item.cpp', 'w',encoding='utf-8') as fp:
        for line in cppMaker.lines:
            fp.write(line)
            fp.write('\n')

def saveToFile(lines, fileName):
    with open(fileName, 'w',encoding='utf-8') as fp :
        for line in lines:
            fp.write(line)
            fp.write('\n')

def makeSimpleTrQuery(trName, inblock, outblock):
    header_maker = SimpleTrQueryHeaderMaker(trName, inblock, outblock)
    header_maker.make()
    saveToFile(header_maker.lines, trName+'query.h')
    cpp_maker = SimpleTrQueryCppMaker(trName, inblock, outblock)
    cpp_maker.make()
    saveToFile(cpp_maker.lines, trName+'query.cpp')

def makeBlockTrQuery(trName, inblock, outblock):
    header_maker = BlockTrQueryHeaderMaker(trName, inblock, outblock)
    header_maker.make()
    saveToFile(header_maker.lines, trName+'query.h')
    cpp_maker = BlockTrQueryCppMaker(trName, inblock, outblock)
    cpp_maker.make()
    saveToFile(cpp_maker.lines, trName+'query.cpp')
    pass

def makeCtsTrQuery(trName, inblock, outblock, outblock1):
    header_maker = CtsTrQueryHeaderMaker(trName, inblock, outblock, outblock1)
    header_maker.make()
    saveToFile(header_maker.lines, trName+'query.h')
    cpp_maker = CtsTrQueryCppMaker(trName, inblock, outblock, outblock1)
    cpp_maker.make()
    saveToFile(cpp_maker.lines, trName+'query.cpp')
    pass

def makeTrQuery(parser):
    inblock = parser.getInBlock()
    outblock = parser.getOutBlock()
    outblock1 = parser.getOutBlock1()
    if outblock1 is None and parser.hasOccurs is False:
        makeSimpleTrQuery(parser.trName, inblock, outblock)
    elif outblock1 is None and parser.hasOccurs is True:
        makeBlockTrQuery(parser.trName, inblock, outblock)
    elif outblock1 is not None and parser.hasOccurs is True:
        makeCtsTrQuery(parser.trName, inblock, outblock, outblock1)
    else :
        print('makeTrQuery - Unexpected Tr Type')

if __name__ == '__main__':
    trName = sys.argv[1]
    print(trName)
    parser = TrParser(trName)
    parser.parse()
    makeTrItem(parser)
    makeTrQuery(parser)