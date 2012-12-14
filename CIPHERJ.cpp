#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>

using namespace std;

#define INF 1000000
#define max(x, y) x>y?x:y

typedef vector<int> vi;

int n,k,len,m;
char messg[1000][205]={{'\0'}} ;
int v[205],mlen[1000],kval[1000],mxk;
char res[201]={'\0'};

vi cy[201];
bool visited[201];

void preprocess(int root, int k)
{
  if(i==root || visited[i]) return;

  
}


void encode()
{
  int i,j, p,pos;
  
}

int main()
{

  int i,j;

  scanf("%d", &n);

  while(n!=0){
    m=0;
    
    for(i=0;i<n;i++) scanf("%d", &v[i]);

    scanf("%d ", &k);
    
    while(k!=0){
      kval[m]=k;
      gets(messg[m]);
      len=strlen(messg[m]);
      messg[m][len]='\0';

      --len;
      if(len<n)for(i=len+1;i<n;i++)messg[m][i]=' ';

      ++m;

      scanf("%d ", &k);
    }

    fill(visited+1,visited+1+n,false);

    for(i=1;i<=n;i++)
      if(!visited[i]){
	preprocess(v[i],v[i]);
	visited[i]=true;
      }

    encode();
    scanf("%d", &n);
    
  }

}

// Look for cycles
