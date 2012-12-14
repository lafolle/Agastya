#include <stdio.h>
#include <string.h>

char line[20000];

int main()
{
  int i,j,k,n,len,t;
  int ll,ul;

  scanf("%d", &t);
  
  while(t--){

    gets(line);
    len = strlen(line);

    for(i=0,ll=0;i<n&&!isalpha(line[i]);i++,ll++);
    for(i=n-1,ul=0;i>=0&&!isalpha(line[i]);i--,ul--);

    for(i=ll;i<=ul;i++)printf("%c", line[i]);


  }

  return 0;
}

    
