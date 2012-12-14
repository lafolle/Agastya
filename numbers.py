#!/usr/bin/python

import math

def process(n):
    k=int(math.pow(3+math.sqrt(5),n))
    l=[]
    l.append(k%10)
    k/=10
    l.append(k%10)
    k/=10
    if k==0:
        l.append(0)
    else:
        l.append(k%10)

    print str(l[2])+str(l[1])+str(l[0])

if __name__=='__main__':
    t=int(raw_input())
    k=1
    while t>0:
        n=int(raw_input())
        print 'Case #'+str(k)+':',
        process(n)
        t-=1
        k+=1
        
