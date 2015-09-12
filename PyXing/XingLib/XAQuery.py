__author__ = 'YONGSUK'
import win32com
import win32com.client
import pythoncom

class XAQuery:
    def __init__(self, trNumber):
        class QueryEvents:
            __xaquery = self
            def OnReceiveData(self, *args):
                self.__xaquery.onReceiveData(args)
            def OnReceiveMessage(self, bIsSystemError, szMessageCode, szMessage):
                self.__xaquery.onReceiveMessage(bIsSystemError, szMessageCode, szMessage)
        self.trNumber = trNumber
        self.xaquery = win32com.client.DispatchWithEvents("XA_DataSet.XAQuery", QueryEvents)
        self.xaquery.LoadFromResFile("Res\\%s.res"%(trNumber))
        self.__evt_wait_flag = False

    def onReceiveData(self, *args):
        print("receive data {0}".format(args))

    def onReceiveMessage(self, bIsSystemError, szMessageCode,szMessage):
        print("{0} receive msg bIsSystemError = {1}, msgCode = {2}, msg={3}".format(self.trNumber, bIsSystemError, szMessageCode, szMessage))
        self.__evt_wait_flag = False

    def waitForResponse(self):
        self.__evt_wait_flag = True
        while self.__evt_wait_flag:
            pythoncom.PumpWaitingMessages()
        return
