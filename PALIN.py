#!/usr/bin/env python


def palin(n):
    n=str(n)
    if n==n[::-1]:
        return True
    return False


if __name__=='__main__':
    pi=0
    ph=0
    c=0
    k=0
    tph=0
    for i in range(10,1<<11):
        c+=1 
        if palin(i):
#            print i-pi, i
            pi=i
            ph+=1

        if c%100==0:
            print k,c,ph
            tph+=ph
            ph=0
            c=0
            k+=1
    print 'Average per 100 : ',tph/k
