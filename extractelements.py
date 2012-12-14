#!/usr/bin/env python

class Time(object):
    """attributes are hour,minute && second"""

def print_time(t):
    print 'Hour - ',t.hour
    print 'Minute - ',t.minute
    print 'Second - ',t.second

def is_after(t1,t2):
    return t1.hour>t2.hour

if __name__=="__main__":
    t1=Time()
    t1.hour=23
    t1.minute=23
    t1.second=23
    t2=Time()
    t2.hour=23
    t2.second=
    print_time(t)

