# -*- coding: utf-8 -*-
"""
Spyder Editor

This is a temporary script file.
"""
while True:
    try:    
        li=input().split()
    except EOFError:
        break
    li2=[]
    for num in li:
    	li2.append(int(num))
    print(sum(li2))