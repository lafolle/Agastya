#include<iostream>
#define MAX 10020
using namespace std;
int main()
{
  long int n,gram[502],h,min[10001],amt[502],i,j,sum=0,k,t,m,s,e,netg;
  //cout<<"Enter the number of tests:";
  cin>>n;
  for(i=0;i<n;i++)
    {
      sum=0;
      //cout<<"Enter the start and end\n";
      cin>>s>>e;
      //cout<<"Enter the number of cases\n";
      cin>>t;
      //cout<<"Enter the amt and grams\n";
      for(m=0;m<t;m++)
	{
	  cin>>amt[m]>>gram[m];
	  sum+=gram[m];
	}
      netg=e-s;

      if(sum<=netg)
	{

	  for(h=1;h<=netg;h++)
	    {
	      min[h]=10020;
	    }
	  min[0]=0;

	  for(k=1;k<=netg;k++)
	    {
	      for(j=0;j<t;j++)
		{
		  if(gram[j]<=k && min[k-gram[j]]+amt[j]<min[k])
		    min[k]=min[k-gram[j]]+amt[j];

		}
	    }

	}
      //for(int j=0;j<=netg;j++)
      // cout<<"\n"<<min[j];
      if(sum<=netg && min[netg]!=MAX)
	{
	  cout<<"The minimum amount of money in the piggy bank is "<<min[netg]<<"."<<"\n";

	}
      else
	cout<<"This is impossible."<<"\n";
    }
  return 0;
}
tauras
 
Posts: 9
Joined: Sun May 22, 2011 11:06
