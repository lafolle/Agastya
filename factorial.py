#!/usr/bin/eny python

def iter_factorial(n):
    k=1
    while n is not 0:
        k*=n
        n-=1
    return k


def factorial(n):
    if n==1:
        return 1
    return n*factorial(n-1)

if __name__=="__main__":
    t=int(raw_input())
    while t>0:
        n=int(raw_input())
        print iter_factorial(n)
        t=t-1
