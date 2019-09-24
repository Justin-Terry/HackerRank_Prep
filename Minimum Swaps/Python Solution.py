#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the minimumSwaps function below.
def minimumSwaps(arr):
    '''
        For this problem I opted to use a map to store the indexes of each of the values
        in the array. By doing this I was able to perform the swaps quickly because I 
        did not have to search for the index of the value I was swapping. This decreased 
        complexity from O(n^2) to O(n)
    '''
    values = {}
    for i in range(0, len(arr)):
        values[arr[i]] = i


    numswaps = 0
    for i in range(0, len(arr)):
        if(arr[i] != i+1): # The value in the index is not right
            # Get the index of the value that should be in this index
            swapIntoIndex = values.get(i+1)
            # Update the map to show the swap
            values[arr[i]] = swapIntoIndex
            values[arr[swapIntoIndex]] = i
            # Perform the swap
            temp = arr[swapIntoIndex]
            arr[swapIntoIndex] = arr[i]
            arr[i] = temp
            # Increment counter
            numswaps += 1

    return(numswaps)
    




if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    arr = list(map(int, input().rstrip().split()))

    res = minimumSwaps(arr)

    fptr.write(str(res) + '\n')

    fptr.close()
