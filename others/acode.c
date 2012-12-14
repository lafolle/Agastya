#include<stdio.h>
int main(void)
{
    char str[5001];
    unsigned long long int a,b,cnt=0,i=1,n;
    scanf("%s",str);
    while(str[0]!='0')
    {
         a=1;
         b=1;
         cnt=0;
         i=1;
         while(str[i]!='\0')
         {
             if(((str[i-1]=='2' && str[i]<'7') || (str[i-1]=='1')) && str[i]!='0')
	       cnt=a+b;
             else if(str[i]=='0')
                     {
                       if(str[i-1]=='2' || str[i-1]=='1')
                        cnt=a;
		       else 
			 {
			   cnt=0;
			   break;
			 }
		     }
             else      
	       cnt=b;
             
             a=b;
             b=cnt;
             i++;
         }
         printf("%llu\n",cnt);
         scanf("%s",str);
    }
    return 0;
}
