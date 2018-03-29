#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Mar 27 12:03:15 2018

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
spriteCluster = [
        ('colored.grey.half.buton_slim_released',   (3,1), ( 0,  0, 3, 1)),
        ('colored.grey.half.buton_slim_pressed',    (3,1), ( 3,  0, 3, 1)),
        ('colored.yellow.half.buton_slim_released', (3,1), ( 6,  0, 3, 1)),
        ('colored.yellow.half.buton_slim_pressed',  (3,1), ( 9,  0, 3, 1)),
        ('colored.green.half.buton_slim_released',  (3,1), (12,  0, 3, 1)),
        ('colored.green.half.buton_slim_pressed',   (3,1), (15,  0, 3, 1)),
        ('colored.red.half.buton_slim_released',    (3,1), (18,  0, 3, 1)),
        ('colored.red.half.buton_slim_pressed',     (3,1), (21,  0, 3, 1)),
        ('colored.blue.half.buton_slim_released',   (3,1), (24,  0, 3, 1)),
        ('colored.blue.half.buton_slim_pressed',    (3,1), (27,  0, 3, 1)),
        
        ('colored.grey.full.buton_slim_released',   (3,1), ( 0,  1, 3, 1)),
        ('colored.grey.full.buton_slim_pressed',    (3,1), ( 3,  1, 3, 1)),
        ('colored.yellow.full.buton_slim_released', (3,1), ( 6,  1, 3, 1)),
        ('colored.yellow.full.buton_slim_pressed',  (3,1), ( 9,  1, 3, 1)),
        ('colored.green.full.buton_slim_released',  (3,1), (12,  1, 3, 1)),
        ('colored.green.full.buton_slim_pressed',   (3,1), (15,  1, 3, 1)),
        ('colored.red.full.buton_slim_released',    (3,1), (18,  1, 3, 1)),
        ('colored.red.full.buton_slim_pressed',     (3,1), (21,  1, 3, 1)),
        ('colored.blue.full.buton_slim_released',   (3,1), (24,  1, 3, 1)),
        ('colored.blue.full.buton_slim_pressed',    (3,1), (27,  1, 3, 1)),
        
        ('colored.grey.buton_big_released',   (3,3), ( 0,  2, 3, 3)),
        ('colored.yellow.buton_big_released', (3,3), ( 6,  2, 3, 3)),
        ('colored.green.buton_big_released',  (3,3), (12,  2, 3, 3)),
        ('colored.red.buton_big_released',    (3,3), (18,  2, 3, 3)),
        ('colored.blue.buton_big_released',   (3,3), (24,  2, 3, 3)),     
        ('colored.grey.buton_big_pressed',    (3,1), ( 3,  4, 3, 3)),
        ('colored.yellow.buton_big_pressed',  (3,1), ( 9,  4, 3, 3)),
        ('colored.green.buton_big_pressed',   (3,1), (15,  4, 3, 3)),
        ('colored.red.buton_big_pressed',     (3,1), (21,  4, 3, 3)),
        ('colored.blue.buton_big_pressed',    (3,1), (27,  4, 3, 3)),
        
        ('colored.grey.slimborder.buton_slim_released',   (3,1), ( 3,  2, 3, 1)),
        ('colored.grey.slimborder.buton_slim_pressed',    (3,1), ( 3,  3, 3, 1)),
        ('colored.yellow.slimborder.buton_slim_released', (3,1), ( 9,  2, 3, 1)),
        ('colored.yellow.slimborder.buton_slim_pressed',  (3,1), ( 9,  3, 3, 1)),
        ('colored.green.slimborder.buton_slim_released',  (3,1), (15,  2, 3, 1)),
        ('colored.green.slimborder.buton_slim_pressed',   (3,1), (15,  3, 3, 1)),
        ('colored.red.slimborder.buton_slim_released',    (3,1), (21,  2, 3, 1)),
        ('colored.red.slimborder.buton_slim_pressed',     (3,1), (21,  3, 3, 1)),
        ('colored.blue.slimborder.buton_slim_released',   (3,1), (27,  2, 3, 1)),
        ('colored.blue.slimborder.buton_slim_pressed',    (3,1), (27,  3, 3, 1)),
        
        ('colored.grey.pannel',   (3,3), ( 0,  5, 3, 3)),
        ('colored.yellow.pannel', (3,3), ( 6,  5, 3, 3)),
        ('colored.green.pannel',  (3,3), (12,  5, 3, 3)),
        ('colored.red.pannel',    (3,3), (18,  5, 3, 3)),
        ('colored.blue.pannel',   (3,3), (24,  5, 3, 3)),  
        
        ('colored.yellow.border.buton_big_released', (3,3), ( 6,  8, 3, 3)),
        ('colored.green.border.buton_big_released',  (3,3), (12,  8, 3, 3)),
        ('colored.red.border.buton_big_released',    (3,3), (18,  8, 3, 3)),
        ('colored.blue.border.buton_big_released',   (3,3), (24,  8, 3, 3)),     
        ('colored.yellow.border.buton_big_pressed',  (3,1), ( 9, 10, 3, 3)),
        ('colored.green.border.buton_big_pressed',   (3,1), (15, 10, 3, 3)),
        ('colored.red.border.buton_big_pressed',     (3,1), (21, 10, 3, 3)),
        ('colored.blue.border.buton_big_pressed',    (3,1), (27, 10, 3, 3)),
        
        ('colored.yellow.border.buton_slim_released', (3,1), ( 9,  8, 3, 1)),
        ('colored.yellow.border.buton_slim_pressed',  (3,1), ( 9,  9, 3, 1)),
        ('colored.green.border.buton_slim_released',  (3,1), (15,  8, 3, 1)),
        ('colored.green.border.buton_slim_pressed',   (3,1), (15,  9, 3, 1)),
        ('colored.red.border.buton_slim_released',    (3,1), (21,  8, 3, 1)),
        ('colored.red.border.buton_slim_pressed',     (3,1), (21,  9, 3, 1)),
        ('colored.blue.border.buton_slim_released',   (3,1), (27,  8, 3, 1)),
        ('colored.blue.border.buton_slim_pressed',    (3,1), (27,  9, 3, 1)),
        
        ('colored.grey.slider',      (2,2), ( 4,  6, 2, 2)),
        ('colored.yellow.slider',    (2,2), ( 10,  6, 2, 2)),
        ('colored.green.slider',     (2,2), (16,  6, 2, 2)),
        ('colored.red.slide',        (2,2), (22,  6, 2, 2)),
        ('colored.blue.slider',      (2,2), (28,  6, 2, 2)),
        
        ('colored.grey.checkbox',    (3,1), ( 3,  5, 1, 3)),
        ('colored.yellow.checkbox',  (3,1), ( 9,  5, 1, 3)),
        ('colored.green.checkbox',   (3,1), (15,  5, 1, 3)),
        ('colored.red.checkbox',     (3,1), (21,  5, 1, 3)),
        ('colored.blue.checkbox',    (3,1), (27,  5, 1, 3)),
        
        ('colored.grey.selectbox',   (2,1), ( 4,  5, 2, 1)),
        ('colored.yellow.selectbox', (2,1), (10,  5, 2, 1)),
        ('colored.green.selectbox',  (2,1), (16,  5, 2, 1)),
        ('colored.red.selectbox',    (2,1), (22,  5, 2, 1)),
        ('colored.blue.selectbox',   (2,1), (28,  5, 2, 1)),
        
        ('colored.sliderbar_horizontal', (3,1), ( 3,  8, 3, 1)),
        ('colored.sliderbar_vertical',   (1,3), ( 3,  9, 1, 3)),
        ('colored.arrows',               (2,2), ( 4,  9, 2, 2)),
        ('colored.list',                 (3,3), ( 0,  9, 3, 4)),
        ('colored.textbox',              (3,1), ( 0,  8, 3, 1)),
        
        ('ancient.white.pannel', (3,3), ( 0, 13, 3, 3,)),
        ('ancient.grey.pannel',  (3,3), ( 3, 13, 3, 3,)),
        ('ancient.brown.pannel', (3,3), ( 6, 13, 3, 3,)),
        ('ancient.tan.pannel',   (3,3), ( 9, 13, 3, 3,)),
        
        ('ancient.white.buton_slim_released', (3,1), ( 0, 16, 3, 1,)),
        ('ancient.grey.buton_slim_released',  (3,1), ( 3, 16, 3, 1,)),
        ('ancient.brown.buton_slim_released', (3,1), ( 6, 16, 3, 1,)),
        ('ancient.tan.buton_slim_released',   (3,1), ( 9, 16, 3, 1,)),
        
        ('ancient.white.buton_slim_pressed', (3,1), ( 0, 17, 3, 1,)),
        ('ancient.grey.buton_slim_pressed',  (3,1), ( 3, 17, 3, 1,)),
        ('ancient.brown.buton_slim_pressed', (3,1), ( 6, 17, 3, 1,)),
        ('ancient.tan.buton_slim_pressed',   (3,1), ( 9, 17, 3, 1,)),
        
        ('ancient.white.buton_big_released', (3,3), ( 0, 18, 3, 3,)),
        ('ancient.grey.buton_big_released',  (3,3), ( 3, 18, 3, 3,)),
        ('ancient.brown.buton_big_released', (3,3), ( 6, 18, 3, 3,)),
        ('ancient.tan.buton_big_released',   (3,3), ( 9, 18, 3, 3,)),
        
        ('ancient.white.buton_big_pressed', (3,1), ( 0, 21, 3, 1,)),
        ('ancient.grey.buton_big_pressed',  (3,1), ( 3, 21, 3, 1,)),
        ('ancient.brown.buton_big_pressed', (3,1), ( 6, 21, 3, 1,)),
        ('ancient.tan.buton_big_pressed',   (3,1), ( 9, 21, 3, 1,)),
        
        ('ancient.white.slider',   (2,2), ( 1, 23, 2, 2)),
        ('ancient.grey.slider',    (2,2), ( 4, 23, 2, 2)),
        ('ancient.brown.slider',   (2,2), ( 7, 23, 2, 2)),
        ('ancient.tan.slide',      (2,2), (10, 23, 2, 2)),
        
        ('ancient.white.checkbox', (3,1), ( 0, 22, 1, 3)),
        ('ancient.grey.checkbox',  (3,1), ( 3, 22, 1, 3)),
        ('ancient.brown.checkbox', (3,1), ( 6, 22, 1, 3)),
        ('ancient.tan.checkbox',   (3,1), ( 9, 22, 1, 3)),
        
        ('ancient.white.selectbox', (2,1), ( 1, 22, 2, 1)),
        ('ancient.grey.selectbox',  (2,1), ( 4, 22, 2, 1)),
        ('ancient.brown.selectbox', (2,1), ( 7, 22, 2, 1)),
        ('ancient.tan.selectbox',   (2,1), (10, 22, 2, 1)),

        
        ]

def countFromSize(imageSize, spriteSize, spriteMargin):
    x = (imageSize[0] + spriteMargin[0]) / (spriteSize[0] + spriteMargin[0])
    y = (imageSize[1] + spriteMargin[1]) / (spriteSize[1] + spriteMargin[1])
    return (int(x), int(y))

def posFromI(pos, spriteSize, spriteMargin = (0,0)):
    x = pos[0] * (spriteSize[0] + spriteMargin[0])
    y = pos[1] * (spriteSize[1] + spriteMargin[1])
    dx = x + spriteSize[0]
    dy = y + spriteSize[1]
    return (x, y, dx, dy)

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
        
        for cluster in spriteCluster:
            clusterIds = []
            for yi in range(cluster[2][3]):
                yj = cluster[2][1] + yi
                for xi in range(cluster[2][2]):
                    xj = cluster[2][0] + xi
                    clusterIds.append((xj, yj))
            
            clusterPixelSize = (cluster[1][0] * spriteSize[0], cluster[1][1] * spriteSize[1])
            pngCluster = Image.new('RGBA', clusterPixelSize)
            pos = 0
            for xyi in clusterIds:
                posXYI = posFromI(xyi, spriteSize, spriteMargin)
                sprite = sheet.crop(posXYI)
                
                x = pos % cluster[1][0]
                y = pos // cluster[1][0]
                xyj = (x,y)
                xy = posFromI(xyj, spriteSize)
                
                pngCluster.paste(sprite, xy)
                pos += 1
            
            
            pngClusterName = cluster[0] + ".png"
            fullPath = os.path.join(spriteSheetDir, '..', 'cluster', pngClusterName)
            pngCluster.save(fullPath)
            