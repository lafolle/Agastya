#include<stdio.h>
int main()
{
char q[35],e[35];
int t,i,j,k,l,d[34],ct,m,r,a[34],b[34],c[1000],flag;
scanf("%d",&t);
while(t--)
{
scanf("%s %s",q,e);
ct=0;
for(i=0;q[i]!='\0';i++)
a[i]=q[i]-48;
k=i;
for(i=0;e[i]!='\0';i++)
b[i]=e[i]-48;
l=i;
for(i=0;i<1000;i++)
c[i]=0;
if(a[k-1]%2==0)
{       
i=0;
while(i<k)
{
if(i==k-1)
d[i]=a[i]/2;
else
{
d[i]=a[i]/2;
a[i+1]=a[i+1]+(a[i]%2)*10;
}
i++;
}
}
else
{       
i=0;
while(i<k)
{
if(i==k-1)
d[i]=a[i]/2+1;
else
{
d[i]=a[i]/2;
a[i+1]=a[i+1]+(a[i]%2)*10;
}
i++;
}
}
//for(j=0;j<i;j++)
//printf("d[%d]= %d ",j,d[j]);
k=i;
for(i=k-1;i>=0;i--)
{
m=k-1-i;
for(j=l-1;j>=0;j--,m++)
{
if(d[i]*b[j]>9)
{
ct++;
c[m]+=(d[i]*b[j])%10;
if(c[m]>9)
{
c[m+1]+=c[m]/10;
c[m]=c[m]%10;
}
r=(d[i]*b[j])/10;
c[m+1]+=r;
//printf("c[%d]=%d,,,c[%d]=%d",m,c[m],m+1,c[m+1]);
}
else
{
c[m]+=d[i]*b[j];
if(c[m]>9)
{
c[m+1]+=c[m]/10;
c[m]=c[m]%10;
}
//printf("c[%d]=%d,,,c[%d]=%d",m,c[m],m+1,c[m+1]);
ct++;
}
}
}
flag=0;
//printf("\n");
for(i=ct;i>=0;i--)
{
if(c[i]>0||flag)
{
flag=1;
printf("%d",c[i]);
}}
printf("\n");
}
return 0;
}

// WA
