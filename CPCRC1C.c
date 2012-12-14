#include <stdio.h>

long long int a,b,c, n,m,s;


long long int getsum(long long int k)
{
  s=0LL;

  while(k){
    s+=k%10LL;
    k/=10LL;
  }

  return s;
}

long long int bruteforce()
{
  long long int sum=0,i;

  for(i=n;i<=m;i++)sum+=getsum(i);

  return sum;
  
}

int main()
{
  int i;
  scanf("%lld %lld", &n, &m);

  while(n!=-1&&m!=-1){

    if(n==m){
      printf("%lld\n",getsum(a));
      scanf("%lld %lld\n",&n, &m);
      continue;
    }

    printf("%lld\n",bruteforce());

    scanf("%lld %lld", &n, &m);
    
  }

}
