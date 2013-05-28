#include <string.h>
#include <stdio.h>

char *m = "machula";

int main()
{
  int i,j,k,t,n;
  scanf("%d",&t);

  while(t--){
    char a[20],b[20],c[20],d[20],e[20];
    scanf("%s + %s = %s", a, b, c);

    if(strstr(a, m)){
      j=atoi(b);
      k=atoi(c);
      sprintf(e,"%d",k-j);      
      printf("%s + %s = %s\n", e, b, c);      
    }
    else if(strstr(b,m)){
      j=atoi(a);
      k=atoi(c);
      sprintf(e,"%d",k-j);      
      printf("%s + %s = %s\n", a, e, c);            
    }
    else{
      j=atoi(a);
      k=atoi(b);
      n=k+j;
      sprintf(e,"%d",k+j);      
      printf("%s + %s = %s\n", a, b, e);                  
    }
  }
  
  return 0;
}

// AC
