
#! /usr/bin/python




def solve():
    wc=int(raw_input())
    line=raw_input()
    ab,af,eng=[],[],[]
    word_list=line.split()
    ef=False
    
    for word in word_list:
        if word[0]=='#' and ef:
            af.append(word)
        elif word[0]=='#' and not ef:
            ab.append(word)
        else:
            ef=True
            eng.append(word)

    if len(eng) is 0  or (len(ab) is 0 and len(af) is 0):
        return line
    else:
        return ' '.join(af+eng+ab)
        

if __name__=="__main__":
    T=int(raw_input())
    i=0
    while i<T:
        ans = solve()
        print ans
        i+=1
