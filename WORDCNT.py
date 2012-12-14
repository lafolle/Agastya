#!/usr/bin/python


def bigger(a,b):
    if a>b:
        return a
    else:
        return b
    

def process(s):
    l=len(s)

    if l==0:
        return 0
    
    c=0
    plen=0
    mlen=-23
    for word in s:
        wlen=len(word)
        if wlen==0:
            continue
        if plen==0:
            plen=wlen
            c+=1
            continue
        
        if plen==wlen:
            c+=1
        else:
            plen=wlen
            mlen=bigger(mlen,c)
            c=1

    return mlen

if __name__=='__main__':
    c=0
    t=int(raw_input())
    while t>=0:
        try:
            s=raw_input()
            c=process(s.strip().split())
            if c is not -23:
                print c
        except EOFError:
            k=len(s)
            str=''
            for i in range(0,k):
                str+=s[i]
            print 'EOF'
        t-=1
        
