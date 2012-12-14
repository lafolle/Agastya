#include<cstdio>
#include<algorithm>
using namespace std;

int K,M;
int MAXVAL[51][1000];
int W[51];
int V[51];


void calc_maxval()
{ 
  for(int i=0;i<=M;i++)
    MAXVAL[i][0] = 0;
  for(int i=0;i<=K;i++)
    MAXVAL[0][i] = 0;

  for(int i=1;i<=M;i++)
    {
      for(int j=1;j<=W[i];j++)  MAXVAL[i][j] = max(MAXVAL[i-1][j],MAXVAL[i][j-1]);
      for(int j=W[i];j<=K;j++)  MAXVAL[i][j] = max(MAXVAL[i-1][j-W[i]]+V[i], max(MAXVAL[i][j-1],MAXVAL[i-1][j]) );
    }

}

int main()
{
  int t;
  scanf("%d",&t);
  while(t--)
    {

      scanf("%d %d",&K,&M);
      for(int i=1;i<=M;i++)
	scanf("%d %d",&W[i],&V[i]);      
  
      calc_maxval();
      printf("Hey stupid robber, you can get %d.\n",MAXVAL[M][K]);
    }
  return 0;
}

// frodo
