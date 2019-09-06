#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the sockMerchant function below.
def sockMerchant(n, ar):
    numOfPairs = 0
    socks = {}

    for sock in ar:
        if(sock in socks):
            socks[sock] = (socks[sock])+1
        else:
            socks[sock] = 1

    for sock in socks:
        numOfPairs += math.floor(socks[sock]/2.0)
        
    return numOfPairs

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    ar = list(map(int, input().rstrip().split()))

    result = sockMerchant(n, ar)

    fptr.write(str(result) + '\n')

    fptr.close()
