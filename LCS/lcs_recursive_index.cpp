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

string s1,s2;
int l1,l2;


// memoization
int dp[100][100];

int lcs(int i, int j, int len)
{
  cout<<len<<endl;
  if(s1[i]==s2[j]){
    if(dp[i+1][j+1]!=-1) return dp[i+1][j+1];
    dp[i+1][j+1] = lcs(i+1,j+1,len+1);
    return dp[i+1][j+1];
  }

  if(dp[i][j+1]!=-1&&dp[i+1][j]!=-1)
    return max(dp[i][j+1], dp[i+1][j]);

  dp[i][j+1]=lcs(i,j+1,len);
  dp[i+1][j]=lcs(i+1,j,len);
  return max(dp[i][j+1], dp[i+1][j]);
}

int main()
{
  int i,j;

  cin>>s1>>s2;
  l1=s1.length();
  l2=s2.length();

  
  for(i=1;i<l1;i++)for(j=1;j<l2;j++)dp[i][j]=-1;
  for(i=0;i<l1;i++)dp[i][0]=0;
  for(i=0;i<l2;i++)dp[0][i]=0;


  cout<<"length(LCS) : "<<lcs(0,0,0)<<endl;
  return 0;
}

// something faulty
