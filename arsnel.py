#!/usr/bin/env python


import math


def pathscount(n):
    return math.factorial(2*(n-1))/(math.factorial(n-1)*math.factorial(n-1))



if __name__=='__main__':
    pass
    
