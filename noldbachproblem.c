#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int n,k;
int m[1001];



int main()
{
  int i,j,lim;

  scanf("%d %d", &n, &k);

  memset(m, -1, sizeof(int)*1001);

  m[2]=0;
  m[3]=0;
  lim=sqrt(n);
  for(i=3;i<lim;i++){
    if(!m[i])
      for(j=3;j<=n/i;j++)
	m[i*j]=1;
  }

  for(i=1;i<=n;i++)
    if(!m[i]) printf("%d ",i);
  printf("\n");
}
