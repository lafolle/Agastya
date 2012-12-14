#!/usr/bin/env python

def beal(max_base, max_power):
    bases, powers, table, pow = initial_data(max_base, max_power)
    for x in bases: 
        powx = pow[x]
        if x % 1000 == 0: print 'x =', x
        for y in bases:
            if y > x or gcd(x,y) > 1: continue
            powy = pow[y]
            for m in powers:
                xm = powx[m]
                for n in powers:
                    sum = xm + powy[n]
                    r = table.get(sum)
                    if r: report(x, m, y, n, nth_root(sum, r), r)
                
def initial_data(max_base, max_power):
    bases = range(1, max_base+1)
    powers = range(3, max_power+1)
    table = {}
    pow = [None] * (max_base+1)
    for z in bases:
        pow[z] = [None] * (max_power+1)
        for r in powers:
            zr = long(z) ** r
            pow[z][r] = zr
            table[zr] = r
    print 'initialized %d table elements' % len(table)
    return bases, powers, table, pow  

def report(x, m, y, n, z, r):
    x, y, z = map(long, (x, y, z))
    assert min(x, y, z) > 0 and min(m, n, r) > 2 
    assert x ** m + y ** n == z ** r
    print '%d ^ %d + %d ^ %d = %d ^ %d = %s' % \
        ( x,   m,   y,   n,   z,   r,  z**r)
    if gcd(x,y) == gcd(x,z) == gcd(y, z) == 1: 
        raise 'a ruckus: SOLUTION!!'

def gcd(x, y):
    while x:
        x, y = y % x, x
    return y

def nth_root(base, n): 
    return long(round(base ** (1.0/n)))

import time

def timer(b, p):
    start = time.clock()
    beal(b, p)
    secs = time.clock() - start
    return {'secs': secs, 'mins': secs/60, 'hrs': secs/60/60}

# where the fuck is the output
