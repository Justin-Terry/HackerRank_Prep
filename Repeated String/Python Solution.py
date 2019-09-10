#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the repeatedString function below.
def repeatedString(s, n):
    # Count the number of a's in the repeated string
    num_as_in_s = s.count("a")
    # Find out how long the partial string at the end will be, if it exists
    rem = n % len(s)

    # Get the partial string and count the a's
    partial = s[0:rem]
    partial_as = partial.count("a")

    return partial_as + int(num_as_in_s * ((n-rem)/len(s)))
    
    
    

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    n = int(input())

    result = repeatedString(s, n)

    fptr.write(str(result) + '\n')

    fptr.close()
