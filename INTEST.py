#!/usr/bin/env python



if __name__=='__main__':
    inp=raw_input().split()
    n=int(inp[0])
    k=int(inp[1])
    s=0
    while n>0:
        if int(raw_input())%k==0:
            s+=1
        n-=1
    print s
