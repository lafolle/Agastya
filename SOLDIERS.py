#!/usr/bin/env python

from math import ceil, floor

def max(a,b):
    if a>b:
        return a
    return b

def min(a,b):
    if a<b:
        return a
    return b

if __name__=='__main__':
    t=int(raw_input())
    while t>0:
        l=raw_input().split()
        m=int(l[0])
        n=int(l[1])

        x = int(n*ceil(m/2.0))
        y = int(m*ceil(n/2.0))

        if x>y:
            print x
        else:
            print y
            
        t-=1


