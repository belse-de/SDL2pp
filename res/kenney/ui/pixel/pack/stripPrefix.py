#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Mar 29 10:50:37 2018

@author: belse
"""

# execute only if run as a script
if __name__ == "__main__":
    import os, glob
    pngsGlobStr = './**/16x16_???_??x??y.png'
    pngsGlob = glob.glob(pngsGlobStr)
    
    for png in pngsGlob:
        pngDir  = os.path.dirname(png)
        pngName = os.path.basename(png)
        pngNewName = pngName[10:]
        #print(pngName, '->', pngNewName )
        newPng = os.path.join(pngDir, pngNewName)
        print(png, '->', newPng )
        os.rename(png, newPng)