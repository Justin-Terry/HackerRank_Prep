#!/bin/python3

import math
import os
import random
import re
import sys



if __name__ == '__main__':
    arr = []
    maxTotal = int(-sys.maxsize - 1)
    hourGlassTotal = 0;

    for _ in range(6):
        arr.append(list(map(int, input().rstrip().split())))

    for i in range(0, 4):
        for j in range (0, 4):
            tl = arr[i][j]
            tm = arr[i][j+1]
            tr = arr[i][j+2]
            mid = arr[i+1][j+1]
            bl = arr[i+2][j]
            bm = arr[i+2][j+1]
            br = arr[i+2][j+2] 

            hourGlassTotal = tl + tm + tr + mid + bl + bm + br
            if(hourGlassTotal > maxTotal):
                maxTotal = hourGlassTotal
    print(maxTotal)
            
