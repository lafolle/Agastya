#include <stdio.h>
#include <assert.h>

int TS[3][20];
int memo[20][3];
int n;

int min(int a,int b){ if(a<b) return a; return b; }


// a recursive solution with memoization
int getmin(int p, int ind)
{

  if(ind==n-1) return memo[ind][p];

  if(memo[ind][p]!=-1) return memo[ind][p];
  
  int k,a,b,c;

  if(p==0)
    k=min(getmin(1,ind+1),
	  getmin(2,ind+1));
  else if(p==1)
    k=min(getmin(0,ind+1),
	  getmin(2,ind+1));
  else if(p==2)
    k=min(getmin(0,ind+1),
	  getmin(1,ind+1));
  
  memo[ind][p]=k+TS[p][ind];
  
  return memo[ind][p];
}


int main()
{
  int i,t,j,k,m,s=0;
  scanf("%d",&t);

  while(t--){

    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d %d %d", &TS[0][i],&TS[1][i],&TS[2][i]);

    for(i=0;i<20;i++)for(j=0;j<3;j++)memo[i][j]=-1;
    
    if(n==2){
      s=0;
      for(i=0;i<2;i++){
	m=200000;
	for(j=0;j<3;j++)
	  m=min(m, TS[j][i]);
	s+=m;
      }
      printf("%d\n",s);
      continue;
    }

    memo[n-1][0]=TS[0][n-1];
    memo[n-1][1]=TS[1][n-1];
    memo[n-1][2]=TS[2][n-1];

    printf("%d\n",min(getmin(0,0), min(getmin(1,0), getmin(2,0))));
    
  }
  return 0;
}

// AC



