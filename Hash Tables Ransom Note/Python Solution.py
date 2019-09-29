#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the checkMagazine function below.
def checkMagazine(magazine, note):
    mag = {}

    for s in magazine:
        addOne(mag, s)

    for s in note:
        if(s not in mag.keys() or mag[s] < 1):
            print("No")
            return
        mag[s] = mag[s] - 1
    
    print("Yes")

def addOne(m, s):
    if(s in m.keys()):
        m[s] = m[s] + 1
    else:
        m[s] = 1

if __name__ == '__main__':
    mn = input().split()

    m = int(mn[0])

    n = int(mn[1])

    magazine = input().rstrip().split()

    note = input().rstrip().split()

    checkMagazine(magazine, note)
