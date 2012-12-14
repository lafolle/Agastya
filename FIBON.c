#include <stdio.h>
typedef long long int lli;int main(){int t,n,i;lli j,k,c,v[73];j=0;k=1;v[0]=j;v[1]=k;for(i=2;i<73;i++){c=j+k;v[i]=c;j=k;k=c;}scanf("%d",&t);while(t--){scanf("%d",&n);printf("%lld\n",v[n]);}return 0;}

// AC
