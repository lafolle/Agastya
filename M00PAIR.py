#!/usr/bin/env python






if __name__ == '__main__':


    ans_map = []
    p = 0

    ans_map.append(0)

    for i in range(2,1000):

        ans = p<<1
        
        if (i-1)%2 == 1:
            ans += 1
        else:
            ans -= 1

        ans_map.append(ans)
            
        p = ans

    n = raw_input()

    while len(n) is not 0:

        print ans_map[int(n)-1]

        try:
            n = raw_input()
        except EOFError:
            break

        






