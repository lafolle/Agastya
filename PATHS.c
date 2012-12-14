#include <stdio.h>

typedef long long int lli;
lli f(int x ){lli s=1;while(x)s*=x--;return s;}

int t,m;
int main()
{
  scanf("%d", &t);
  while(t--){
    scanf("%d",&m);
    printf("%lld\n", ((lli)f(2*(m-1)) / f(m-1)) /(lli) f(m-1) );
  }
}

// to be completed...
