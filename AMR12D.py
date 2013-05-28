#!/usr/bin/env python


# brain strain .... no mood


if __name__=='__main__':
    s = raw_input()
    l = len(s)
    print "YES" if s[0:l/2]==reversed(s[(l/2)+1:l+1]) else "NO"
    print s[0:l/2]
    print s[(l/2):l+1]
        
