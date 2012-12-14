#!/usr/bin/env python

import math
import sys,getopt
import threading,zipfile

class complex:
    """Defining a complex class"""
    r=0
    i=0
    def __init__(self):
        print("Initialising complex number")
        self.r=23
        self.i=23

    def __init__(self,r,i):
        self.r=r
        self.i=i

    """compute amplitude of complex number"""
    def amplitude(self):
        return math.sqrt(pow(self.r,2),pow(self.i,2))

    def display(self):
        s="("+str(self.r)+"i"+str(self.i)+")"
        print(s)

if __name__=="__name__":
    if len(sys.argv):
        print(sys.argv)
    else:
        print "no arguments are provided."
    n=complex()
    m=complex(23,32)
    print(m.amplitude())
