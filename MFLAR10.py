
#!/usr/bin/env python



if __name__=='__main__':
    sen=raw_input().lower()
    while sen is not '*':
        l=sen.split(' ')
        char=l[0][0]
        good=True
        
        for word in l:
            if len(word)==0 or char==word[0]:
                continue
            good=False
            break

        if good:
            print 'Y'
        else:
            print 'N'

        sen=raw_input().lower()
            
                
