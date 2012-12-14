#include  <stdio.h>

int main()
{
  int t;
  unsigned int n;
  scanf("%d",&t);
  while(t--){
    scanf("%u",&n);
    printf("%.11f\n",n==1?2.0/3.0:(3.0/4.0)-(1.0/(2.0*(n+1)))+(1.0/(2.0*(n+2))));
  }
}
