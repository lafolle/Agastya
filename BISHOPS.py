#!/usr/bin/env python
if __name__=="__main__":
    while True:
        try:
            n=int(raw_input())
        except EOFError:
            break
        if n==1:
            print 1
        else:
            print 2*n-2

# Sol in 0.06 sec
