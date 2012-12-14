def factorial(n):
    if n==1:
        return 1
    return n*factorial(n-1)

def iter_factorial(n):
    k=1
    while n is not 0:
        k*=n
        n-=1
    return k

def nCr(n,r):
    if r==0:
        return 1
    if n-r>r:
        p=r
        denom=r
    else:
        p=n-r
        denom=n-r
    numerator=1
    while p is not 0:
       numerator=numerator*n
       n=n-1
       p=p-1

    return numerator/iter_factorial(denom)

""" Change input functioning
Take raw_input and extract numbers from it """


if __name__=="__main__":
    T=int(raw_input())
    while T is not 0:
        T-=1
        s=raw_input().split(' ')
        n=int(s[0])
        k=int(s[1])
        if n==k:
            print 1
            continue
        s=0
        for i in range(1,k+1):
            s+=nCr(k,i)*nCr(n-k-1,i-1)
        print s

