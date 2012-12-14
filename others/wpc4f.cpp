#include <cstdio>
#include <iostream>

#define INF 99999

using namespace std;

int main()
{
  int t;
  scanf("%d",&t);
  while(t--)
    {
      int h,res;
      int dp[105][105]={{0}};
      res=INF;
      scanf("%d",&h);
      for(int i=1;i<=h;i++)
	for(int j=1;j<=3;j++)
	  scanf("%d",&dp[i][j]);
      for(int i=1;i<=h;i++)
	for(int j=1;j<=3;j++)
	  {
	    if(j==1)
	      dp[i][j]=min(dp[i-1][j+1],dp[i-1][j+2])+dp[i][j];
	    else if(j==2)
	      dp[i][j]=min(dp[i-1][j-1],dp[i-1][j+1])+dp[i][j];
	    else
	      dp[i][j]=min(dp[i-1][j-1],dp[i-1][j-2])+dp[i][j];
	  }

      printf("%d\n",min(dp[h][3],min(dp[h][1],dp[h][2])));
    }
  return 0;
}
