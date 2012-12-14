#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define INF 1000000
#define max(x, y) x>y?x:y
#define min(x,y) x<y?x:y

int h,w;
int m[101][101],s[101][101];


int compute(int col)
{
  int i,j,k=col;
  int r=1,c=col;

  for(i=0;i<h-1;i++){
    for(j=c;j<=k;j++){
      if(j-1>=0) s[i+1][j-1]=min(s[i+1][j-1],s[i][j]+m[i+1][j-1]);
      s[i+1][j]=min(s[i+1][j],s[i][j]+m[i+1][j]);
      if(j+1<w) s[i+1][j+1]=min(s[i+1][j+1],s[i][j]+m[i+1][j+1]);
    }
    c=c?c-1:0;
    k=j<w?j:w-1;
  }
}


int main()
{
  int i,j,k,t,ms;

  while(scanf("%d %d",&h,&w)!=EOF){

    assert(h<=100&&w<=100);

    for(i=0;i<h;i++)for(j=0;j<w;j++)scanf("%d", &m[i][j]);
    //    memset(s, 0, sizeof(int)*101*101);
    for(i=0;i<h;i++)for(j=0;j<w;j++)s[i][j]=INF;

    for(i=0;i<w;i++)s[0][i]=m[0][i];

    ms=INF;

    for(i=0;i<w;i++)
      compute(i);

    for(i=0;i<w;i++)
      ms=min(ms,s[h-1][i]);

    printf("%d\n",ms);
        
  }
}
