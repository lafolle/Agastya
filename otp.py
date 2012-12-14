#!/usr/bin/env python

"""
Give us life again, we just wanna be whole... - We are broken by Paramore
"""

"""
A simple One Time Padding symmetric encryption scheme.
Length of key is equal to length of message to be encrypted

Padding is of length 8.

OTP is symmetric key encryption algotithm. 2 messages were intercepted:
one was original message, other message used acronyms, which provided
hint for decryption of secret key.
"""

import sys
import random
from operator import xor

def getkey(key_len):
    key=''
    for i in range(key_len): key += '1' if random.randint(0,9)>5 else '0'
    return key

def str_to_bin(messg, pad=8):
    "Convert message to binary with padding"
    
    binstr = ''
    for i in range(len(messg)):
        x=bin(ord(messg[i]))[2:]
        binstr+='0'*(pad-len(x))+x
    return binstr

def otp_enc(messg):
    "One Time Padding"
    
    binstr = str_to_bin(messg)
    key = getkey(len(binstr))
    cipher = ''
    for (ch, kbit) in zip(binstr, key):
        cipher += str(xor(ord(ch)-48, ord(kbit)-48))
    return (cipher,key)

def otp_dec(cipher, key, pad=8):
    "Decode cipher using key"

    bitmessg,messg = '',''
    for (ch, kbit) in zip(cipher, key):
        bitmessg += str(xor(ord(ch)-48, ord(kbit)-48))
    for limiter in range(0,len(cipher),pad):
        messg += chr(int(bitmessg[limiter:limiter+pad],2))
    return messg

if __name__ == '__main__':
    if len(sys.argv) is not 2:
        print 'First argument should be a message to be encrypted'
    else:    
        messg = sys.argv[1]
        (cipher, key) = otp_enc(messg)

        print 'Encrypted message : %s\n' % cipher
        print 'Key used in encryption : %s\n' % key



