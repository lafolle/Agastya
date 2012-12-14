#!/usr/bin/env python


def bcoff(n,r):
    print "Computing..."
    s=1
    if n-r<r:
        for i in range(1,n-r+1):
            s*=(1+(r/i))
    else:
        for i in range(1,r+1):
            s*=(1+(n-r)/i)
    return s


if __name__=="__main__":
    print bcoff(1000000,500000)



# approx 27sec for 1000000,200000
# approx 1.4min for 1000000,500000
