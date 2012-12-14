#!/usr/bin/env python





# fucked up at n=168
def compute_native(n):
    df={1:1}
    s=0
    for i in range(1,n+1):
        df[i+1]=df[i]*(i+1)
        s+=pow(-1,i-1)*(1.0/df[i+1])

    if s is not 0:
        return 1.0/s
    else:
        print 'wtf!'

def brothers_algorithm(n):
    e=2
    f={0:1,1:1}
    for i in range(1,n+1):
        k=2*i+1
        f[k]=k*(k-1)*f[2*i-1]
        e+=2.0*(i+1)/f[k]

    return e
        

if __name__=='__main__':
    for i in range(10,100,2):
        print "For "+str(i)+ ", e is : "+ str(brothers_algorithm(i)) #str(compute(i))
    
#    print 2.71828182846
    
