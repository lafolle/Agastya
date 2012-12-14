#include <stdio.h>
#include <string.h>

#define pl printf("\n")

int main()
{
  int t,i,j,k,l=1;
  char line[1000],ch,*word,delim[]=" ",rev[100][1000];
  scanf("%d",&t);
  while(t--){
    k=read(0,line,1000);
    line[k-1]='\0';
    word=strtok(line,delim);      
    i=0;
    while(word!=NULL){
      strcpy(rev[i++],word);
      word=strtok(NULL,delim);      
    }
    printf("Case #%d: ",l++);
    for(j=i-1;j>=0;j--)
      printf("%s ",rev[j]);
    pl;
  }
}
