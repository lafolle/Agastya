#include <map>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iterator>
#include <queue>
#include <cassert>
#include <cstring>

using namespace std;

#define pl cout<<endl;
#define all(v) v.begin(),v.end()
#define sz(v) v.size()
#define SENTINEL 1000001


typedef long long int lli;
typedef vector<string, string> vpss;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef map<string, int> msi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;

int toint(char n){
  return n-'0';
}

char num[1000001]={'\0'},palin[1000000]={'\0'};

void solve_for_odd(int n,int l,int r)
{cout<<l<<' '<<r<<endl;
  int i,j,k,m,p,s,carry,q;
  for(i=l,j=r;i>=0&&j<n;i++,j--){
    if(num[i]==num[j])continue;
    if(num[i]-'0'>num[j]-'0'){cout<<"Greater"<<num[i]<<' '<<num[j]<<endl;
      for(p=0;p<=l;p++)palin[p]=num[p];
      for(q=p;q>=0;q--)palin[p++]=num[q];
      printf("%s\n",palin);
      return;
    }
    else if(num[i]-'0'==num[j]-'0'){cout<<"Small "<<num[i]<<' '<<num[j]<<endl;
      carry=1;
      for(p=i;p>=0&&carry;p--){
	k=num[p]-'0'+carry;
	num[p]='0'+k%10;
	carry=k/10;
      }
      if(carry)printf("1");
      for(p=0;p<=l;p++)palin[p]=num[p];
      for(q=l+1;q>=0;q--)palin[p++]=num[q];
      printf("%s\n",palin);
      if(carry)printf("1");
      printf("\n");
      return;
    }
  }

  cout<<"We have a palindrome!\n";
  // if num is palindrome
  carry=1;
  for(i=l;i>=0&&carry;i--){
    k=num[i]-'0'+carry;
    num[i]='0'+k%10;
    carry=k/10;
  }
  if(carry)printf("1");
  for(p=0;p<=l;p++)palin[p]=num[p];
  for(q=l+1;q>=0;q--)palin[p++]=num[q];
  printf("%s\n",palin);
  if(carry)printf("1");      
  printf("\n");
}

int main()
{
  int t,i,j,n,k,p,q,r,l;
  scanf("%d",&t);

  while(t--){
    scanf("%s",num);
    n=strlen(num);

    if(n==1){
      printf("%s\n",num);
      fill_n(num,n,'\0');
      continue;
    }
    
    if(!(n%2)){ // even
      l=n>>2;
      r=l-1;
      cout<<"Even\n";
    }
    else{  // odd
      r=(n/2)+1;
      l=(n/2)-1;
      solve_for_odd(n,l,r);      
    }

    fill_n(num,n,'\0');
    fill_n(palin,n+1,'\0');
  }
  
  return 0;
}

