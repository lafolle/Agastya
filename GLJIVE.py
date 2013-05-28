#!/usr/bin/env python

v = []
for i in xrange(0,10): v.append(int(raw_input()))

sum = 0
bestsum = 0
for i in xrange(0,10):
    sum += v[i]
    if sum==100:
        bestsum=sum
        break
    if sum<100:
        bestsum = sum
    if sum>100:
        if sum-100 == 100-bestsum or sum-100 < 100-bestsum:
            bestsum=sum
        break
print bestsum

# AC
            
