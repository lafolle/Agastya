#!/usr/bin/env python

# Sieve of Eratosthenes using map

rng=[]

a,b=0,0

def kill(k):
    print "killing by "+str(k)
    i=1
    k*=i
    while k*i<b or k*i==b:
        rng[k*i]=-1
        i+=1
#f    print rng


if __name__=='__main__':
    t=int(raw_input())
    while t>0:
        l=[int(i) for i in raw_input().split()]
        a,b=l[0],l[1]
        rng=range(0,b+1)
        map(kill,range(2,a))
        print [rng[i] for i in range(2,b+1) if rng[i]>0]
        rng=[]
        t-=1
        
        
        
