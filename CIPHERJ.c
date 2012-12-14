#include <stdio.h>
#include <string.h>
#include <assert.h>


#define INF 1000000
#define max(x, y) x>y?x:y

int n,k,len,m;
char messg[1000][205]={{'\0'}} ;
int v[205],mlen[1000],kval[1000],mxk,cyclelen[201];
char res[201]={'\0'};

void preprocess()
{
  int i,j,pos;
  for(i=0;i<n;i++){
    pos=i;
    for(j=0;j<=mxk;j++){
      memo[i][j]=pos;
      pos=v[pos]-1;
    }
  }
    
}


void encode()
{
  int i,j, p,pos;
  
  for(i=0;i<m;i++){

    for(j=0;j<n;j++)
      res[memo[j][kval[i]]]=messg[i][j];

    printf("%s\n", res);
    
  }

}

int main()
{

  int i,j;

  scanf("%d", &n);

  while(n!=0){
    m=0;
    
    for(i=0;i<n;i++) scanf("%d", &v[i]);

    scanf("%d ", &k);
    mxk=k;
    
    while(k!=0){
      kval[m]=k;
      gets(messg[m]);
      len=strlen(messg[m]);
      messg[m][len]='\0';

      --len;
      if(len<n)for(i=len+1;i<n;i++)messg[m][i]=' ';

      ++m;

      scanf("%d ", &k);
      mxk=max(mxk, k);
    }
    preprocess();

    encode();
    scanf("%d", &n);
    
  }

}
