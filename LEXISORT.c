#include<stdio.h>
#include <string.h>

int cmp(const char *a, const char *b)
{
  return strcmp(a,b)>0;
}

char words[50000][10];

int main()
{
  int t,n,i;
  scanf("%d",&t);
  while(t--){
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%s",words[i]);
    qsort(words,n,sizeof(words[0]),cmp);
    for(i=0;i<n;i++)
      printf("%d %s\n",i+1,words[i]);
  }
}

/*
  Bad output is popping up :(
*/
