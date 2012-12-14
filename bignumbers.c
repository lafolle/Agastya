#include <stdio.h>
#include <string.h>

#define INF 1000001

int min(int i, int j)
{
  if(i<j) return i;
  return j;
}

int max(int i, int j)
{
  if(i>j) return i;
  return j;
}

char cs[100001];


int add(const char *a, int l1, const char *b, int l2)
{
  int i,j,k,l,carry=0,dig;

  const char *n=(l1<l2)?a:b;
  const char *m=(l1>l2)?a:b;

  k=1000;
  for(i=min(l1,l2)-1,j=max(l1,l2)-1;j>=0;--i,--j,--k){
    dig=(i>=0)?n[i]-'0'+m[j]-'0'+carry:m[j]-'0'+carry;
    cs[k]=dig%10+'0';
    carry=dig/10;
  }
  if(carry) cs[k]=carry+'0';
  return k;
}


int main()
{
  int t;
  
  int l1, l2;
  char as[100001],bs[100001];  
  
  scanf("%d",&t);

  while(t--){
    
    scanf("%s %s",as, bs);
    l1=strlen(as);
    l2=strlen(bs);

    int k=add(as,l1,bs,l2);
    for(;k<=1000;k++)printf("%c",cs[k]);
    printf("\n");
    
  }

  return 0;
}
