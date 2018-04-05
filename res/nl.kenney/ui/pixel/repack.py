#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Mar 29 10:50:37 2018

@author: belse
"""

prefixes = [
        'ancient.white',
        'ancient.brown',
        'ancient.grey',
        'ancient.tan',
        'color.grey',
        'color.red',
        'color.green',
        'color.blue',
        'color.yellow',
        ]
prefixes = [
        'ancient.white',
        ]
# execute only if run as a script
if __name__ == "__main__":
    import os, glob
    pngsGlobStr = './pack/**/'
    for pre in prefixes:
        globStr = pngsGlobStr + pre + '.*.png'
        print(globStr)
        pngsGlob = glob.glob(globStr, recursive=True)
        pngsGlob.sort()
        oldDir = ''
        for png in pngsGlob:
            pngDir  = os.path.dirname(png)
            pngName = os.path.basename(png)
            
            if oldDir != pngDir:
                print(pngDir)
                oldDir = pngDir
                
            print('  ', pngName)
            
            
            #pngNewName = pngName[10:]
            #print(pngName, '->', pngNewName )
            #newPng = os.path.join(pngDir, pngNewName)
            #print(png, '->', newPng )
            #os.rename(png, newPng)
