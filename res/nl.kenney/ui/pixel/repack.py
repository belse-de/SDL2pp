#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Mar 29 10:50:37 2018

@author: belse
"""

dryRun = False
verbose = False
fileMove = False

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
            ],
        'space':{}
        }


def globRecSorted(globStr):
    files = glob.glob(globStr, recursive=True)
    files.sort()
    return files

def fileCpMv(src, dst, mode='dry_verbose'):
    if mode == 'dry':
        pass
    elif mode == 'dry_verbose':
        print(src, '->', dst)
    else:
        dstDir = os.path.dirname(dst)
        if not os.path.exists(dstDir):
            os.makedirs(dstDir)
                        
        if mode == 'cp' or mode == 'copy':
             shutil.copy(src, dst)
        elif mode == 'mv' or mode == 'move':
            shutil.move(src, dst)
        else:
            assert False, 'Not valide mode.'

def recDictTraversal(d, handle=None, keys=[], visited=[]):
    def travers(key, value, keyList):
        newKeys = list(keyList) # make copy
        newKeys.append(key) # extend copy
        if value not in visited:
            visited.append(value)
            if isinstance(value, dict) or isinstance(value, list):
                return recDictTraversal(v, handle, newKeys, visited)
            else:
                return handle(newKeys, v)
            
    if isinstance(d, dict):
        res = []
        for k, v in d.items():
            res.append(travers(k, v, keys))
        return keys, res

    elif isinstance(d, list):
        res = []
        for i, v in enumerate(d):
            res.append(travers(i, v, keys))
        return keys, res
    else:
        return keys, d
        
# execute only if run as a script
if __name__ == "__main__":
    import os, glob, shutil
    pngsGlobStr = './pack/**/'
    fileMode = 'dry'
    if dryRun:
        if verbose:
            fileMode = 'dry_verbose'
        else:
            fileMode = 'dry'
    elif fileMove:
        fileMode = 'mv'
    else:
        fileMode = 'cp'
    
    
    for com in commenPrefixes:
        comPngsGlob = globRecSorted(pngsGlobStr + com + '.*.png')
        print(com, len(comPngsGlob))
        
        packedPngs = []
        for pre in prefixes[com]:
            pngsGlob = globRecSorted(pngsGlobStr + pre + '.*.png')
            print(pre, len(pngsGlob))  

            for png in pngsGlob:
                comPngsGlob.remove(png)
    
                pngDir  = os.path.dirname(png)
                newDir = pngDir.replace('pack', 'packed/' + pre, 1)  
                pngName = os.path.basename(png)         
                newName = pngName[len(pre)+1:]
                newPng = os.path.join(newDir,newName)
                    
                fileCpMv(src=png, dst=newPng, mode=fileMode)            
                
            print('   ', com, len(comPngsGlob), pre, len(pngsGlob))  
            
        for png in comPngsGlob:
            pngDir  = os.path.dirname(png)
            pngName = os.path.basename(png) 
            newName = pngName[len(com)+1:]
            newFile = ''
            
            if len(prefixes[com]) > 0:
                for pre in prefixes[com]:        
                    newDir = pngDir.replace('pack', 'packed/' + pre, 1)
                    newPng = os.path.join(newDir,newName)
                    packedPngs.append(newPng)
                    fileCpMv(src=png, dst=newPng, mode=fileMode)  
            else:
                newDir = pngDir.replace('pack', 'packed/' + com, 1)
                newPng = os.path.join(newDir,newName)
                packedPngs.append(newPng)