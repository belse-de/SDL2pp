#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Mar 22 11:39:25 2018

@author: belse
"""

import os
from PIL import Image

spriteSheetPath = './pixel/Spritesheet/UIpackSheet_transparent.png'
spriteSheetDir = os.path.dirname(os.path.realpath(spriteSheetPath))
spriteSize = (16,16)
spriteMargin = (2,2)
'''
    l = n * 16 + (n - 1) * 2
'''


def countFromSize(imageSize, spriteSize, spriteMargin):
    x = (imageSize[0] + spriteMargin[0]) / (spriteSize[0] + spriteMargin[0])
    y = (imageSize[1] + spriteMargin[1]) / (spriteSize[1] + spriteMargin[1])
    return (int(x), int(y))

def posFromI(pos, spriteSize, spriteMargin):
    x = pos[0] * (spriteSize[0] + spriteMargin[0])
    y = pos[1] * (spriteSize[1] + spriteMargin[1])
    xw = x + spriteSize[0]
    yh = y + spriteSize[1]
    return (x, y, xw, yh)
            

if __name__ == "__main__":
    # execute only if run as a script
    print("Hello from __main__, my dear user!")  
    cwd = os.getcwd()
    fileDir = os.path.dirname(os.path.realpath(__file__))
    fileName = os.path.basename(os.path.realpath(__file__))
    
    if(cwd == fileDir):
        sheet = Image.open(os.path.realpath(spriteSheetPath))
        spriteCount = countFromSize(sheet.size, spriteSize, spriteMargin)
        print('fitting', spriteCount,'=', spriteCount[0] * spriteCount[1], 'sprites.')
        
        ids = []
        for yi in range(spriteCount[1]):
            for xi in range(spriteCount[0]):
                ids.append((xi, yi))
        
        group = -1
        for xyi in ids:
            #ids.remove(xyi)
            group += 1
            posXYI = posFromI(xyi, spriteSize, spriteMargin)
            
            sprite = sheet.crop(posXYI)
            if not sprite.getchannel('A').getbbox():
                continue # skip complete transparent sprites
            
            name = "{:d}x{:d}_{:03d}_{:02d}x{:02d}y.png".format(spriteSize[0], spriteSize[1], group, xyi[0], xyi[1])
            fullPath = os.path.join(spriteSheetDir, '..', 'PNG', name)
            sprite.save(fullPath)
            
            '''
            spriteColors = sprite.getcolors()
            for xyj in ids:
                posXYJ = posFromI(xyj, spriteSize, spriteMargin)
            
                compSprite = sheet.crop(posXYJ)
                if not compSprite.getchannel('A').getbbox():
                    ids.remove(xyj)
                    continue # skip and remove complete transparent sprites
                    
                compColors = compSprite.getcolors()
                if len(spriteColors) != len(compColors):
                    continue
                
                compCopy = compSprite.copy()
                compCopyData = compCopy.load()
                for y in range(compCopy.size[1]):
                    for x in range(compCopy.size[0]):
                        for statIdx, colorStat in enumerate(compColors):
                            if compCopyData[x, y] in colorStat:
                                compCopyData[x, y] = spriteColors[statIdx][1]

                diff = ImageChops.subtract(sprite, compCopy)          
                if not diff.getbbox():
                    ids.remove(xyj)
                    compName = "{:d}x{:d}_{:04d}_{:02d}x{:02d}y.png".format(spriteSize[0], spriteSize[1], group, xyj[0], xyj[1])
                    compFullPath = os.path.join(spriteSheetDir, '..', 'PNG', compName)
                    compSprite.save(compFullPath)
            '''
    else:
        print("Working dir and file dir are NOT equal, I can NOT proceed.")
    
    
'''
   

'''

'''
    for each sprite
        check if is still not grouped
            check print(sprite.getcolors()) is same length
                replace all pixel
                subtract sprites from eachother
                if result is empty
                    we got a match, put in group         
'''