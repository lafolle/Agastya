#include <stdio.h>
#include <string.h>
#include <stdlib.h>

short  v[87000000];
int primes[5000001];

void precompute(int n)
{
  int i,j,k,p,q,m,cnt;
  memset(v,1,2*87000000);
  cnt=0;
  m=1;
  v[0]=0;v[1]=0;

  q=9273;
  v[2]=1;
  for(i=3;i<=q;i+=2){ // not considering any even numbers
    if(!v[i]) continue;

    k=n/i;
    for(j=2;j<=k;j++)
      v[i*j]=0;
  }

  k=0;
  primes[0]=2;
  for(i=3;i<=n;i+=2)if(v[i])primes[++k]=i;
}

int main()
{
  int t,n;
  precompute(87000000);
  scanf("%d",&t);
  while(t--){
    scanf("%d",&n);
    printf("%d\n",primes[n-1]);
  }
  return 0;
}

