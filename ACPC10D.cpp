#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;
#define MAX 1000001

int m[100000][3];
int dp[100000][3];
int n;

int main()
{
  int i,j,k=0;
  scanf("%d",&n);

  while(n){
    for(i=0;i<n;i++)for(j=0;j<3;j++){
	scanf("%d",&m[i][j]);
	dp[i][j] = MAX;
      }
    dp[0][1]=m[0][1]; dp[0][2]=m[0][2]+dp[0][1];
    
    dp[1][0] = dp[0][1]+m[1][0];
    dp[1][1] = min(min(dp[0][1]+m[1][1], dp[0][2]+m[1][1]), dp[1][0]+m[1][1]);
    dp[1][2] = min(min(dp[0][1]+m[1][2], dp[0][2]+m[1][2]), dp[1][1]+m[1][2]);
    for(i=1;i<n-1;i++){
      for(j=0;j<3;j++){
	if(j==0){
	  dp[i+1][j] = min(dp[i][j]+m[i+1][j], dp[i+1][j]);
	  dp[i+1][j+1] = min(dp[i][j]+m[i+1][j+1], dp[i+1][j+1]);
	  dp[i][j+1] = min(dp[i][j]+m[i][j+1], dp[i][j+1]);
	}
	else if(j==2){
	  dp[i+1][j] = min(dp[i][j]+m[i+1][j], dp[i+1][j]);
	  dp[i+1][j-1] = min(dp[i][j]+m[i+1][j-1], dp[i+1][j-1]);
	}
	else{
	  dp[i+1][j] = min(dp[i][j]+m[i+1][j], dp[i+1][j]);
	  dp[i+1][j+1] = min(dp[i][j]+m[i+1][j+1], dp[i+1][j+1]);
	  dp[i+1][j-1] = min(dp[i][j]+m[i+1][j-1], dp[i+1][j-1]);
	  dp[i][j+1] = min(dp[i][j]+m[i][j+1], dp[i][j+1]);	  
	}
	
      }
    }
    printf("%d. %d\n",++k, min(dp[n-1][0]+m[n-1][1],dp[n-1][1]));
    scanf("%d", &n);
  }

  return 0;
}

// AC
