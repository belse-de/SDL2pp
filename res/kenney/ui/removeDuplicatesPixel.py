#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Mar 22 18:09:15 2018

@author: belse
"""

import os
import errno
import glob
from PIL import Image, ImageChops

slicePathes = [
    './pixel/9-Slice/space_inlay.png',
    './pixel/9-Slice/space.png',
    './pixel/9-Slice/Colored/blue.png',
    './pixel/9-Slice/Colored/green_pressed.png',
    './pixel/9-Slice/Colored/green.png',
    './pixel/9-Slice/Colored/red_pressed.png',
    './pixel/9-Slice/Colored/grey.png',
    './pixel/9-Slice/Colored/blue_pressed.png',
    './pixel/9-Slice/Colored/yellow_pressed.png',
    './pixel/9-Slice/Colored/grey_pressed.png',
    './pixel/9-Slice/Colored/yellow.png',
    './pixel/9-Slice/Colored/red.png',
    './pixel/9-Slice/Outline/blue.png',
    './pixel/9-Slice/Outline/green_pressed.png',
    './pixel/9-Slice/Outline/green.png',
    './pixel/9-Slice/Outline/red_pressed.png',
    './pixel/9-Slice/Outline/blue_pressed.png',
    './pixel/9-Slice/Outline/yellow_pressed.png',
    './pixel/9-Slice/Outline/yellow.png',
    './pixel/9-Slice/Outline/red.png',
    './pixel/9-Slice/list.png',
    './pixel/9-Slice/Ancient/grey_inlay.png',
    './pixel/9-Slice/Ancient/tan.png',
    './pixel/9-Slice/Ancient/brown_inlay.png',
    './pixel/9-Slice/Ancient/tan_inlay.png',
    './pixel/9-Slice/Ancient/grey.png',
    './pixel/9-Slice/Ancient/tan_pressed.png',
    './pixel/9-Slice/Ancient/white.png',
    './pixel/9-Slice/Ancient/brown_pressed.png',
    './pixel/9-Slice/Ancient/white_pressed.png',
    './pixel/9-Slice/Ancient/grey_pressed.png',
    './pixel/9-Slice/Ancient/brown.png',
    './pixel/9-Slice/Ancient/white_inlay.png',
]
slicePathes.sort()

pngDirGlob = './pixel/PNG/*.png'
spriteSize = (16, 16)

def countFromSize(imageSize, spriteSize):
    x = (imageSize[0]) / (spriteSize[0])
    y = (imageSize[1]) / (spriteSize[1])
    return (int(x), int(y))

def posFromI(i, spriteSize):
    x = i[0] * spriteSize[0]
    y = i[1] * spriteSize[1]
    dx = x + spriteSize[0]
    dy = y + spriteSize[0]
    return (x, y, dx, dy)
    
def isBlackTrans(image):
    result = True
    data = image.load()
    for y in range(image.size[1]):
        for x in range(image.size[0]):
            isBlack = data[x,y] == (0,0,0,0)
            result = result and isBlack
    return result

def rmPrefix(string, prefix):
    if string.startswith(prefix):
        return string[len(prefix):]
    return string


def silentRmFile(filename):
    try:
        os.remove(filename)
    except OSError as e: # this would be "except OSError, e:" before Python 2.6
        if e.errno != errno.ENOENT: # errno.ENOENT = no such file or directory
            raise # re-raise exception if a different error occurred

if __name__ == "__main__":
    # execute only if run as a script
    print("Hello from __main__, my dear user!")  
    cwd = os.getcwd()
    fileDir = os.path.dirname(os.path.realpath(__file__))
    fileName = os.path.basename(os.path.realpath(__file__))
    
    if(cwd != fileDir):
        print("Working dir and file dir are NOT equal, I can NOT proceed.")
        exit
    
    pngs = glob.glob(os.path.realpath(pngDirGlob))
    pngs.sort()
    
    for path in slicePathes:
        path = os.path.realpath(path)
        sheet = Image.open(path)
        count = countFromSize(sheet.size, spriteSize)
        
        pngs = glob.glob(os.path.realpath(pngDirGlob))
        pngs.sort()
        
        ids = []
        for yi in range(count[1]):
            for xi in range(count[0]):
                ids.append((xi, yi))
        
        for xy in ids:
            template = sheet.crop(posFromI(xy, spriteSize))
            
            for png in pngs:
                sprite = Image.open(png)
                
                diff1 = ImageChops.subtract(template, sprite)
                diff2 = ImageChops.subtract(sprite, template)
                if isBlackTrans(diff1) and isBlackTrans(diff2):
                    print(rmPrefix(path, fileDir), xy, rmPrefix(png, fileDir))
                    silentRmFile(png)
                    break
