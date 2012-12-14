#include<stdio.h>
int main()
{
  int t,tanda,k,l,j,x,min,mini,sum,n,a[20][3],z,rendah;
  
  scanf("%d",&t);
  while(t--)
  {min=2000;
    
    scanf("%d",&n);
    for( l=0;l<n;l++ )
    { 
      for(j=0;j<3;j++)
        scanf("%d",&a[l][j]);
        
      }
    x=0;min=2000;
    for(j=0;j<3;j++)
    {
      for(z=0;z<3;z++)
      {
      if(n==2)  {sum=a[0][j]+a[1][z]; if(min>=sum) min=sum;};
        
      if(j!=z) {sum=a[0][j]+a[1][z]; 
      
      if(min>=sum) {min=sum; tanda=z; } 
                }
      
      }
    }
    
    
    for(l=2;l<n;l++)
    {k=0;rendah=min;
  
      for(j=0;j<3;j++)
      {
        if(tanda!=j){
        {mini=rendah+a[l][j];}
        if(k==0) {min=2000; k=1;}
        if(min>=mini) {min=mini; tanda=j;}
        }
        }
      }
     
     printf("%d\n",min);
      
    }
  
  return 0;}

