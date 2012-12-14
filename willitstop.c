#include <stdio.h>

int main()
{
  long long int  n=1,j,i,k=1;

  scanf("%lld",&n);

  for(i=0;i<64&&!((n>>i)&1);i++);
  j=n&(~(k<<i));
  if(!j) printf("TAK\n");
  else printf("NIE\n");
  
  return 0;
}


/* __builtin_popcount(n) get fucked as
   n goes beyond w^30 */
