#!/usr/bin/env python

#------------------
# User Instructions
#
# Hopper, Kay, Liskov, Perlis, and Ritchie live on 
# different floors of a five-floor apartment building. 
#
# Hopper does not live on the top floor. 
# Kay does not live on the bottom floor. 
# Liskov does not live on either the top or the bottom floor. 
# Perlis lives on a higher floor than does Kay. 
# Ritchie does not live on a floor adjacent to Liskov's. 
# Liskov does not live on a floor adjacent to Kay's. 
# 
# Where does everyone live?  
# 
# Write a function floor_puzzle() that returns a list of
# five floor numbers denoting the floor of Hopper, Kay, 
# Liskov, Perlis, and Ritchie.

import itertools

def adjacent(a, b):
    return abs(a-b)==1

def floor_puzzle():

    for hopper, kay, liskov, perlis, ritchie in itertools.permutations([1,2,3,4,5]):
        if (hopper is not 5 and
            kay is not 1 and
            1 < liskov < 5 and
            perlis > kay and
            not adjacent(ritchie, liskov) and
            not adjacent(liskov, kay)):
            return [hopper, kay, liskov, perlis, ritchie]


if __name__ == '__main__':
    floors = floor_puzzle()
    names = ['Hopper', 'Kay', 'Liskov', 'Perlis', 'Ritchie']
    for name, floor in zip(names, floors):
        print '%s : %d' % (name, floor)
