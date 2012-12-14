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

#define fr(i,n) for(int i = 0; i < (int)(n);i++)
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

char A[5001];
int len;
lli dp[5001],s,d;


lli compute()
{
  int i,j,k;

  dp[0]=1;
  dp[1]=1;
  if(A[1]!='0' && ((A[0]=='1') || A[0]=='2' && A[1]<'7'))
    dp[1]=2;
  
  for(i=2;i<len;i++){
    s=0;
    d=0;
    if(A[i]!='0')
      s=dp[i-1];
    if(A[i-1]!='0' && (A[i-1]=='1' || A[i-1]=='2' && A[i]<'7'))
      d=dp[i-2];
      
    dp[i]=s+d;
  }

  return dp[len-1];
}

int main()
{
  int i,j,k;

  while(1){

    
    scanf("%s",A);
    
    if(!strcmp(A,"0"))break;

    len=strlen(A);
    fill_n(dp, len,-1); // dp

    printf("%lld\n",compute());

    fill_n(A,'\0',len); // A
  }
  
  return 0;
}

// AC at 0
