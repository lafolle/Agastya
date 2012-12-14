#include<iostream>
#include<cstdio>
//#include<conio.h>
#include<stdlib.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
              int n,m,i,j,k=0,sum=0,sum1=0,flag=0;
              scanf("%d %d",&n,&m);
              int a[m];
              for(i=0;i<m;i++)
              scanf("%d",&a[i]);
              
              for(i=1;i<m;i++)
              {
                              if(a[i]>a[i-1])
                              sum+=(a[i]-a[i-1]);
                              else
                              if(a[i]<a[i-1])
                              {
                                             sum-=(a[i-1]-a[i]);
                                             if(sum<0)
                                             {
                                                      sum1=sum1+abs(sum);
                                                      sum=sum+abs(sum);
                                                      if(sum1>=n)
                                                      {
                                                                flag=1;
                                                                break;
                                                      }
                                             }
                              }
                              else if(a[i]==a[i-1])
                              {
                                   
                               sum1+=1;
                               if(sum1>=n)
                               {
                                          flag=1;
                                          break;
                               }
                               
                               
                              }
              }
              
              sum1+=1;
              if(flag==1)
              printf("-1\n");
              else
              printf("%d\n",sum1);
    }
return 0;
//    getch();
}
              
                                             
                                             
