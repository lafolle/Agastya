#include <stdio.h>
#include <stdlib.h>


int v[1000],memo[100][1000];
int n,m;


int sss(int i, int s)
{
  if(s==0)return 1;
  if(i>=n || s<0) return 0;

  int q=sss(i+1,s-v[i]);
  int p=sss(i+1,s);

  if(p==1 || q==1) return 1;

  return 0;

}



int main()
{
  int i,j,k;

  while(scanf("%d %d", &n, &m)!=EOF){

    for(i=0;i<n;i++)scanf("%d",&v[i]);
    for(i=0;i<n;i++)for(j=0;j<=m;j++)memo[i][j]=-1;


    printf("%s\n",sss(0,m)?"Yes":"No");
    
  }
}
