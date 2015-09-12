# -*- coding: utf-8 -*-
"""
Created on Wed Sep 11 16:18:40 2013

@author: yongseok.lee
"""

import win32com
import win32com.client
import pythoncom


class XASession:
    class XASessionEvents:
        def OnLogin(self,szCode, szMsg):
            self.xasession.onLogin(szCode, szMsg)
        def OnLogout(self,*args):
            self.xasession.onLogout(args)
        def OnDisconnect(self, *args):
            self.xasession.onDisconnect(args)
    
    def __init__(self):
        class EventHandler(XASession.XASessionEvents):
            xasession = self
        self.__flag = False

        self.__XASession = win32com.client.DispatchWithEvents("XA_Session.XASession",EventHandler)
    
    def login(self,user="seuki77", password='folken77', certpw='',isRealServer=False):
        self.__user = user
        self.__password = password
        self.__certpw = certpw
        if isRealServer:
            self.__server = "hts.etrade.co.kr"
        else:
            self.__server = "demo.etrade.co.kr"
            self.__certpw = ''
        ret = self.__XASession.ConnectServer(self.__server, 20001)
        
        if ret is False:
            print("XASession fail to connect server")
            return False
        ret = self.__XASession.Login(self.__user, self.__password, self.__certpw,0,1)
        if ret is False:
            print("XASession fail to login")
        self.__flag = True
        while self.__flag:
            pythoncom.PumpWaitingMessages()
        print("XASession login Success")
        return True
    def logout(self):
        self.__XASession.Logout()
    def disconnect(self):
        self.__XASession.DisconnectServer()
    def isConnect(self):
        return self.__XASession.DisconnectServer()
    def getAccountListCount(self):
        return self.__XASession.GetAccountListCount()
    def getAccountList(self, nIndex):
        return self.__XASession.GetAccountList(nIndex)
    
    def onLogin(self,szCode, szMsg):
        print("onLogin szCode={0}, szMsg={1}".format(szCode, szMsg))
        self.__flag = False
    def onLogout(self, *args):
        print("onLogin")
    def onDisconnect(self, *args):
        print("onDisconnect")
    def __del__(self):
        self.logout()
        self.disconnect()

if __name__ == '__main__':
    xasession = XASession()
    xasession.login()
    xasession.logout()
    xasession.disconnect
    del xasession
    
        