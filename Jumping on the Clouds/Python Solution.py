#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the jumpingOnClouds function below.
def jumpingOnClouds(c):
    currentCloud = 0
    numOfJumps = 0

    # While not at then end
    while currentCloud < len(c)-1:
        # If a jump over a spot is possible, check what is there
        if(currentCloud < len(c)-2):
            currentCloud += 2
            # If you can't land there, one jump one spot
            if(c[currentCloud] == 1):
                currentCloud -= 1
        # You're at n - 1 spot, only possible to jump once more.
        else:
            currentCloud += 1
            
        numOfJumps += 1
        print(currentCloud)
    return numOfJumps

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    c = list(map(int, input().rstrip().split()))

    result = jumpingOnClouds(c)

    fptr.write(str(result) + '\n')

    fptr.close()
