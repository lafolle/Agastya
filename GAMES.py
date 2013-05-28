#!/usr/bin/env python

import math

t = int(raw_input())
while t>0:
    n = float(raw_input())
    k=1;
    while True:
        (f, i) = math.modf(n*k)
        if f<0.00001:
            print k
            break
        k+=1
    t-=1
