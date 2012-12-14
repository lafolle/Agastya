#include<iostream>
#include<string.h>

using namespace std;

int main()
{
  int cases,i;
  char ch[1001];
  cin>>cases;
  string dummy;
  getline(cin,dummy);
  for(i=0;i<cases;i++)
    {
      int i=0,len=0,len1=0,cnt=0,cnt1=0,flag=0;
      cin.getline(ch,1000);
      while(ch[i]!='\0')
	{
	  while(ch[i]>=97 && ch[i]<=122)
	    { 
	      i++;
	      len++;
	    }
	  while(ch[i]==32)
	    i++; 
	  if(flag=0) 
	    {
	      len1=len;
	      len=0;
	      flag=1;
	    }
	  else if(len==len1)
	    {
	      cnt++;
	      len1=len;
	      len=0;
	    } 

	  if(len>0)
	    { 
	      if(++cnt>=cnt1)
		cnt1=cnt;
	      cnt=0;
	      len1=len; len=0;
	    }
	} 
      if(++cnt>=cnt1)
	cnt1=cnt;
      cout<<cnt1<<endl;
    } 
  return 0;
}
