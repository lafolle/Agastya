#include<iostream>
#include <cstdio>

#define MAX 1000001
using namespace std;
int main()
{
  int n,gram[502],h,min[10001],amt[502],i,j,sum=0,k,t,m,s,e,netg;
  //cout<<"Enter the number of tests:";
  cin>>n;
  for(i=0;i<n;i++)
    {
      sum=0;
      cin>>s>>e;
      cin>>t;
      for(m=0;m<t;m++)
	{
	  cin>>amt[m]>>gram[m];
	  sum+=gram[m];
	}
      netg=e-s;

      for(h=1;h<=netg;h++)
	min[h]=MAX;
	  
      min[0]=0;

      for(k=1;k<=netg;k++)
	for(j=0;j<t;j++)
	  if(gram[j]<=k && min[k-gram[j]]+amt[j]<min[k])
	    min[k]=min[k-gram[j]]+amt[j];


      if(min[netg]!=MAX)
	printf("The minimum amount of money in the piggy-bank is %d.\n",min[netg]);
      else
	cout<<"This is impossible.\n";
    }
  return 0;
}

// AC
