#!/usr/bin/env python


t = int(raw_input())

while t>0:
    sen = raw_input().strip().split()
    if not sen: continue
    d = {}
    x = 1
    d[len(sen[0])] = 1
    for i in xrange(1, len(sen)):
        if len(sen[i])==len(sen[i-1]):
            x+=1
        else:
            if len(sen[i-1]) in d.keys():
                d[len(sen[i-1])] = max(d[len(sen[i-1])], x)
            else:
                d[len(sen[i-1])] = x
            x=1
    if len(sen[i-1]) not in d.keys():
        d[len(sen[i-1])] = x
    else:
        d[len(sen[i-1])] = max(d[len(sen[i-1])], x)
    print max(d.values())
    t-=1

# AC    
