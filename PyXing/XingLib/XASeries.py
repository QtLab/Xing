# -*- coding: utf-8 -*-
"""
Created on Thu Sep 12 22:29:11 2013

@author: 용석
"""

from pandas import Series

class XASeries:
    def __init__(self,data,indexTable):
        self.base = Series(data)
        self.indexTable = indexTable
    def __getattr__(self, *args, **kwargs):
        return getattr(self.base, *args, **kwargs)
    def getNameByEn(self,en):
        return self.indexTable[en]
        