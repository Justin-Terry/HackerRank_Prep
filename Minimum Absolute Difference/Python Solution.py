#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the minimumAbsoluteDifference function below.
def minimumAbsoluteDifference(arr):
    arr.sort();
    minDif = abs(arr[0] - arr[1]);
    for i in range(1, len(arr) - 1):
        print("minDif =", minDif, "values =", arr[i], arr[i+1])
        if(abs(arr[i] - arr[i+1]) < minDif):
            minDif = abs(arr[i] - arr[i+1])
    return minDif 

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    arr = list(map(int, input().rstrip().split()))

    result = minimumAbsoluteDifference(arr)

    fptr.write(str(result) + '\n')

    fptr.close()
