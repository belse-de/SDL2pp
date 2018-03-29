#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Mar 21 16:16:02 2018

@author: belse
"""

import os 
import xml.etree.ElementTree as ET  

xmlFiles = [
    './space/Spritesheet/uipackSpace_sheet.xml',
    './fixed/Spritesheet/redSheet.xml',
    './fixed/Spritesheet/greySheet.xml',
    './fixed/Spritesheet/blueSheet.xml',
    './fixed/Spritesheet/greenSheet.xml',
    './fixed/Spritesheet/yellowSheet.xml',
    './rpg/Spritesheet/uipack_rpg_sheet.xml',
]

pngRealPath = os.path.join('..', 'PNG')

def printElementsRecur(element, layer):
    if 'name' in element.attrib.keys():
        print('  '*layer + element.tag, element.attrib['name'])
    else:
        print('  '*layer + element.tag, element.attrib)
    for child in element:
        printElementsRecur(child, layer+1)

if __name__ == "__main__":
    # execute only if run as a script
    print("Hello from __main__, my dear user!")  
    cwd = os.getcwd()
    print("I'm called from:", cwd)
    fileDir = os.path.dirname(os.path.realpath(__file__))
    fileName = os.path.basename(os.path.realpath(__file__))
    print("Current file", fileName, "is located in:", fileDir)
    print()
    if(cwd == fileDir):
        print("Since working dir and file dir are equal, I can proceed.")
        print()
        
        for xml in xmlFiles:
            print("opening XML file:", xml)
            xmlPathAbs = os.path.realpath(xml)
            tree = ET.parse(xmlPathAbs)
            textureAtlas = tree.getroot()
            #printElementsRecur(root,0)
            if textureAtlas.tag != 'TextureAtlas':
                print(xml, 'is not a texture atlas! skipping it.')
                continue
            
            pngAbsPath = os.path.join(os.path.dirname(xmlPathAbs), pngRealPath)
            
            for subTexture in textureAtlas:
                if subTexture.tag == 'SubTexture' and 'name' in subTexture.attrib.keys():
                    textureName = subTexture.attrib['name']
                    if not os.path.isfile(os.path.join(pngAbsPath, textureName)):
                        print(textureName, 'is missing!')
                        
            print() # empty line at end
        
    else:
        print("Working dir and file dir are NOT equal, I can NOT proceed.")
    
    