#!/usr/bin/env python



if __name__=='__main__':
    t = int(raw_input())
    while t>0:
        a,b = raw_input().split()
        print int(str(int(a[::-1])+int(b[::-1]))[::-1])
        t-=1

# AC        
