#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the countingValleys function below.
def countingValleys(n, s):
    elevation = 0
    numOfValleys = 0

    for c in s:
        if c == 'D':
            if elevation == 0:
                numOfValleys += 1
            elevation -= 1
        else:
            elevation += 1
    return numOfValleys
    
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    s = input()

    result = countingValleys(n, s)

    fptr.write(str(result) + '\n')

    fptr.close()
