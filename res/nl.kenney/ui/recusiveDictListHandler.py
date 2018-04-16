#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Apr 10 19:25:00 2018

@author: belse
"""
z = {
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
        'space':{
                'grey':[{'red':[1,2,3]},'green','blue','yellow'],
                'blue':['red','green','blue','yellow']
                }
        }
a = {'a': {1: {1: 2, 3: 4}, 2: {5: 6}}}
b = {'a':{'b':{'c':1, 'd':2}, 'e':{'f':3, 'g':4}}, 'h':{'i':5, 'j':6}}
c = {u'xml': {u'config': {u'portstatus': {u'status': u'good'}, u'target': u'1'}, u'port': u'11'}}
d = {"a": 1, "b": 2, "c": {"d": 3, "e": {"f": 4}}}
e = {}
e["key1"] = {}
e["key1"]["key1.1"] = "value1"
e["key2"]  = {}
e["key2"]["key2.1"] = "value2"
e["key2"]["key2.2"] = e["key1"]
e["key2"]["key2.3"] = e
'''
e ==
              root<-------back edge
            /      \           |
         _key1   __key2__      |
        /       /   \    \     |
   |->key1.1 key2.1 key2.2 key2.3
   |   /       |      |
   | value1  value2   |
   |                  | 
  cross edge----------|
'''
#TODO handle loops
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


def iterDictTraversal(d, handle=None, keys=[], ):
    stack = [([],d)]
    visited = []
    res = []
    while stack:
        sk,sv = stack.pop()
        visited.append(sv)
        print(sk,sv)
        if isinstance(sv, dict):
            for k, v in sv.items():
                skk = list(sk)
                skk.append(k)
                stack.append((skk, v))
                pass
        elif isinstance(sv, list):
            for i, v in enumerate(sv):
                ski = list(sk)
                ski.append(i)
                stack.append((ski, v))
        else:
            res.append((sk, handle(sk, sv)))

    else:
        pass
            
# test recDictTraversal
        '''
print(recDictTraversal(a, print))
print(recDictTraversal(b, print))
print(recDictTraversal(c, print))
print(recDictTraversal(d, print))
print(recDictTraversal(e, print))
print(recDictTraversal([], print))
print(recDictTraversal({}, print))
print(recDictTraversal(1, print))
print(recDictTraversal('a', print))
print(recDictTraversal({}))
print(recDictTraversal(z, print))
'''
print('\n'*3)

print(iterDictTraversal(a, print))
print(iterDictTraversal(b, print))
print(iterDictTraversal(c, print))
print(iterDictTraversal(d, print))
#print(iterDictTraversal(e, print))
print(iterDictTraversal([], print))
print(iterDictTraversal({}, print))
print(iterDictTraversal(1, print))
print(iterDictTraversal('a', print))
print(iterDictTraversal({}))
print(iterDictTraversal(z, print))

