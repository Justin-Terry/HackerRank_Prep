#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the arrayManipulation function below.
def arrayManipulation(n, queries):
    arr = [0] * n
    maxi = 0
    for i in range(0, len(queries)):
        for j in range(queries[i][0]-1, queries[i][1]):
            arr[j] += queries[i][2]
            if(arr[j] > maxi):
                maxi = arr[j]
    return maxi
        

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    nm = input().split()

    n = int(nm[0])

    m = int(nm[1])

    queries = []

    for _ in range(m):
        queries.append(list(map(int, input().rstrip().split())))

    result = arrayManipulation(n, queries)

    fptr.write(str(result) + '\n')

    fptr.close()
