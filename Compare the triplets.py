#!/bin/python3
import math
import os
import random
import re
import sys
def compareTriplets(a, b):
    A=0
    B=0
    l=[]
    for i in range(len(a)):
        if a[i]<b[i]:
            B+=1
        elif a[i]>b[i]:
            A+=1
    l.append(A)
    l.append(B) 
    return l 
            
    

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    a = list(map(int, input().rstrip().split()))

    b = list(map(int, input().rstrip().split()))

    result = compareTriplets(a, b)

    fptr.write(' '.join(map(str, result)))
    fptr.write('\n')

    fptr.close()
