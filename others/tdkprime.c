#include<stdio.h>

#define NEW_MAX  86028121 /*5000000th prime*/

char flags[43014063];  /*1/2 of new_max bcoz not storing flags for evens, goblal so initialised to 0,true*/      
unsigned int primes[5000002]; 

void sieve(void)
{
        
        unsigned long p,i;  
        
       /*9276 is approx sqrt of 86028121*/
                
        for(p=3;p<=9277;p+=2)  /*p+=2 bcoz we need not check even*/
        {
                if(flags[(p+1)/2]==0)
                {
                                
                        for(i=p*p; i<=NEW_MAX ;i+=p+p)
                       
                        {
                               
                                flags[(i+1)/2]=1;     
                                         /*p*p,  p*p+p,  p*p + 2p   are not primes*/
                                
                        }
                }
        }
}

void store_sieve()  /*store primes till k=500000*/
{
      int j=2;
      unsigned int i;
        primes[1]=2;
        for(i=3;j<=5000000;i+=2)
        {
         if(flags[(i+1)/2]==0)
            primes[j++]=i;
      }
}



int main()
{
        
        int t,k;
        /*setting of flags for prime nos. by sieve of erasthromas upto NEW_MAX*/
        sieve();
        store_sieve();
        /*end of initial sieving*/
        scanf("%d",&t);
        while(t--)
        {
                scanf("%d",&k);
                  printf("%u\n",primes[k]);
        }
    
        return 0;
}
