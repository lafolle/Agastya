#!/usr/bin/env python


def cube(n):
    return n*n*n


def last3(n):
    if n<5:
        return -1
    k=str(n)
    l=len(k)
    return k[l-3]+k[l-2]+k[l-1]
    


if __name__=='__main__':
    e38=[]
    pi=0

    
    
    for i in range(5,249):
        t=last3(cube(i))
        if t[2]=='8' and t[1]=='8' and t[0]=='8':
            print i-pi,i
            pi=i
