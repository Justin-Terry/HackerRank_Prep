#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the minimumBribes function below.
def minimumBribes(q):
    numBribes = 0
    thisRound = 1
    tooMany = False
    mMap = {}
    while(thisRound > 0):
        thisRound = 0
        # Bubble sort algorithm with a twist
        for i in range(0, len(q)-1):
            a = q[i]
            b = q[i+1]
            if a > b:
                # If you need to swap, that's a bribe, count how many "bribes" each
                # element has had.
                try:
                    mMap[a] += 1
                except KeyError:
                    mMap[a] = 1
                if(mMap[a] > 2):
                    tooMany = True
                    break
                swap(q, i, i+1)
                numBribes += 1
                thisRound += 1
    
    if(tooMany):
        print("Too chaotic")
    else:
        print(numBribes)



def swap(q, i, j):
    temp = q[i]
    q[i] = q[j]
    q[j] =  temp

if __name__ == '__main__':
    t = int(input())

    for t_itr in range(t):
        n = int(input())

        q = list(map(int, input().rstrip().split()))

        minimumBribes(q)
