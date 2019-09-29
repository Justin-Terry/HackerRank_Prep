#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the isBalanced function below.
def isBalanced(s):
    if len(s)%2 != 0:
        return "NO"
    
    stack = []
    for i in range(0, len(s)):
        if s[i] == '(' or s[i] == '{' or s[i] == '[':
            stack.append(s[i])
        elif len(stack) > 0:
            if(checkClosure(stack.pop(), s[i]) == False):
                return "NO"
        else:
            return "NO"
    if(len(stack) > 0):
        return "NO"
    else:
        return "YES"
    
def checkClosure(a, b):
    if(a is '{' and b is '}'):
        return True
    if(a is '[' and b is ']'):
        return True
    if(a is '(' and b is ')'):
        return True
    else:
        return False

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input())

    for t_itr in range(t):
        s = input()

        result = isBalanced(s)

        fptr.write(result + '\n')

    fptr.close()
