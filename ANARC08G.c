#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

int n,net_debt;
int cost[1001][1001],degree[1001];


int compute()
{
  int i,j,k;

  int in=0,out=0;

  for(i=0;i<n;i++){
    in=0;
    out=0;
    for(j=0;j<n;j++){
      in+=cost[i][j];
      out-=cost[j][i];
    }
    degree[i]=in+out;
  }

  int ans=0;
  for(i=0;i<n;i++)
    if(degree[i]>0) ans+=degree[i];

  return ans;
}

int main()
{
  int i,j,k=0;

  scanf("%d",&n);

  while(n){

    net_debt=0;
    
    for(i=0;i<n;i++)
      for(j=0;j<n;j++){
	scanf("%d",&cost[i][j]);
	net_debt+=cost[i][j];
      }

    printf("%d. %d %d\n",++k,net_debt,compute());

    scanf("%d",&n);
    
  }
}

// AC
