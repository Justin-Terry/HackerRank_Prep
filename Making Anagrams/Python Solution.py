#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the makeAnagram function below.
def makeAnagram(a, b):
    mapA = setupMap(a)
    mapB = setupMap(b)
    
    return calcDeletes(mapA, mapB)

def calcDeletes(m1, m2):
    total = 0
    for c in m1.keys():
        if(c in m2):
            total += abs(m1[c] - m2[c])
        else:
            total += m1[c]
    for c in m2.keys():
        if(c not in m1):
            total += m2[c]
    return total
def setupMap(s):
    m = {}
    for c in s:
        addOne(m, c);
    return m

def addOne(m, s):
    if(s in m.keys()):
        m[s] = m[s] + 1
    else:
        m[s] = 1

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    a = input()

    b = input()

    res = makeAnagram(a, b)

    fptr.write(str(res) + '\n')

    fptr.close()
