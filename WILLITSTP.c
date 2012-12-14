#include <stdio.h>

/* Given a number n, say if it
   is a power of 2 or not */

int main()
{
  long long int  n=1,i,k=1;
  scanf("%lld",&n);
  for(i=0;i<64&&!((n>>i)&1);i++);
  printf("%s\n",(n&(~(k<<i)))?"NIE":"TAK");
  return 0;
}


/* __builtin_popcount(n) get fucked as
   n goes beyond 2^30 */
