#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the countSwaps function below.
def countSwaps(a):
    swaps = 0
    currentRound = 1
    while(currentRound != 0):
        currentRound = 0
        for i in range(0, len(a)-1):
            if a[i] > a[i+1]:
                swap(a, i, i+1)
                currentRound += 1
                swaps+=1
    print("Array is sorted in", swaps, "swaps.")
    print("First Element:", a[0])
    print("Last Element:", a[len(a)-1])

def swap(arr, a, b):
    temp = arr[a]
    arr[a] = arr[b]
    arr[b] = temp

if __name__ == '__main__':
    n = int(input())

    a = list(map(int, input().rstrip().split()))

    countSwaps(a)
