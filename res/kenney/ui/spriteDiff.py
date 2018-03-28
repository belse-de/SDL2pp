#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Fri Mar 23 18:07:10 2018

@author: belse
"""

import sys, os, glob, errno
import argparse
from PIL import Image, ImageChops

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
    result = not image.getbbox()
    data = image.load()
    for y in range(image.size[1]):
        for x in range(image.size[0]):
            isBlack = data[x,y] == (0,0,0,0)
            if not isBlack:
                print(x,y,data[x,y])
            result = result and isBlack
    return result

if __name__ == "__main__":
    print(str(sys.argv))
    if not len(sys.argv) >= 3:
        exit
    
    aPath = os.path.realpath(sys.argv[1])
    bPath = os.path.realpath(sys.argv[2])
    
    a = Image.open(aPath)
    b = Image.open(bPath)
    
    if len(sys.argv) == 3:
        pass
    elif len(sys.argv) == 5:
        x1 = int(sys.argv[3])
        y1 = int(sys.argv[4])
        a = a.crop((x1,y1,x1+16,y1+16))
        pass
    elif len(sys.argv) == 7:
        x1 = int(sys.argv[3])
        y1 = int(sys.argv[4])
        x2 = int(sys.argv[5])
        y2 = int(sys.argv[6])
        a = a.crop((x1,y1,x1+16,y1+16))
        b = b.crop((x2,y2,x2+16,y2+16))
        pass
    else:
        exit
        
    data = a.load()
    for y in range(16):
        for x in range(16):
            r,g,bl,al = data[x,y]
            if al == 0:
                data[x,y] = (0,0,0,0)
                        
    data = b.load()
    for y in range(16):
        for x in range(16):
            r,g,bl,al = data[x,y]
            if al == 0:
                data[x,y] = (0,0,0,0)
        
    diff1 = ImageChops.subtract(a, b)
    diff2 = ImageChops.subtract(b, a)
    
    if isBlackTrans(diff1) and isBlackTrans(diff2):
        print("images MATCH")
    else:
        print("images DIFFER")
        print(diff1.getcolors())
        print(diff2.getcolors())
        diff1.save("diff1.png")
        diff2.save("diff2.png")
        print(a.load()[0,0])
        print(b.load()[0,0])
    
    pass