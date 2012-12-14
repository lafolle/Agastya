#include<stdio.h>
int main()
{
  long long int d,j,c,t,i,min,a[1000],b[1000];
    scanf("%lld",&t);
    while(t)
    {
        t--;
        scanf("%lld",&c);
        for(i=0;i<c;i++)
	  scanf("%lld",&a[i]);
	
	scanf("%lld",&d);
        for(i=0;i<d;i++)
	  scanf("%lld",&b[i]);
	
        min=a[0];
        for(i=0;i<c;i++)
        {
            for(j=0;j<c;j++)
            {
                if((min>a[i]-b[j])&&(a[i]-b[j]>=0))
                min=a[i]-b[j];
                else if((min>b[j]-a[i])&&(b[j]-a[i]>=0))
                min=b[j]-a[i];
            }
        }
        printf("%lld\n",min);
    }
    return 0;
}
