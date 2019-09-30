#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the twoStrings function below.
def twoStrings(s1, s2):
    mMap = {}
    for c in s1:
        addOne(mMap, c)
    
    for c in s2:
        if c in mMap.keys():
            return "YES"
    return "NO"

def addOne(m, s):
    if(s in m.keys()):
        m[s] = m[s] + 1
    else:
        m[s] = 1

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    q = int(input())

    for q_itr in range(q):
        s1 = input()

        s2 = input()

        result = twoStrings(s1, s2)

        fptr.write(result + '\n')

    fptr.close()
