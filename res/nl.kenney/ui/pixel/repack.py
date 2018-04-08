#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Mar 29 10:50:37 2018

@author: belse
"""

commenPrefixes = [
        'ancient',
        'color',
        #'space'
        ]

prefixes = {
        'ancient': [
            'ancient.white',
            'ancient.brown',
            'ancient.grey',
            'ancient.tan',
            ],
        'color':[
            'color.grey',
            'color.red',
            'color.green',
            'color.blue',
            'color.yellow',
            ]
        #'space':[
        #        ]
        }

# execute only if run as a script
if __name__ == "__main__":
    import os, glob, shutil
    pngsGlobStr = './pack/**/'
    
    for com in commenPrefixes:
        comGlobStr = pngsGlobStr + com + '.*.png'
        comPngsGlob = glob.glob(comGlobStr, recursive=True)
        comPngsGlob.sort()
    
        for pre in prefixes[com]:
            globStr = pngsGlobStr + pre + '.*.png'
            #print(globStr)
            pngsGlob = glob.glob(globStr, recursive=True)
            pngsGlob.sort()
            
            oldDir = ''
            newDir = ''
            for png in pngsGlob:
                comPngsGlob.remove(png)
                continue
            
                pngDir  = os.path.dirname(png)
                pngName = os.path.basename(png)         
                newName = pngName[len(pre)+1:]
                
                if oldDir != pngDir:
                    newDir = pngDir.replace('pack', 'packed/' + pre, 1)
                    #print(pngDir, '->', newDir)
                    oldDir = pngDir
                    if not os.path.exists(newDir):
                        os.makedirs(newDir)
                    
                #print('  ', pngName, '->', newName)
                #print('     ', os.path.join(newDir,newName))
                shutil.copy(png, os.path.join(newDir,newName))
                #shutil.move(png, os.path.join(newDir,newName))
             
            oldDir = ''
            newDir = ''
            for png in comPngsGlob:
                pngDir  = os.path.dirname(png)
                pngName = os.path.basename(png) 
                newName = pngName[len(com)+1:]
                
                for pre in prefixes[com]:        
                    if oldDir != pngDir:
                        newDir = pngDir.replace('pack', 'packed/' + pre, 1)
                        #print(pngDir, '->', newDir)
                        oldDir = pngDir
                        if not os.path.exists(newDir):
                            os.makedirs(newDir)
                    
                print('   ', os.path.join(newDir,newName))
                #shutil.copy(png, os.path.join(newDir,newName))
            #pngNewName = pngName[10:]
            #print(pngName, '->', pngNewName )
            #newPng = os.path.join(pngDir, pngNewName)
            #print(png, '->', newPng )
            #os.rename(png, newPng)
