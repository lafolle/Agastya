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
typedef unsigned int uint;

#define LIMIT 60000000

int memo[LIMIT],n;

lli mx(lli n)
{
  if(!n)return 0;

  if(n<LIMIT){
    if(memo[n]!=-1)
      return memo[n];
    
    if(memo[n/2]==-1) memo[n/2]=mx(n/2);
 
    if(memo[n/3]==-1) memo[n/3]=mx(n/3);

    if(memo[n/4]==-1) memo[n/4]=mx(n/4);

    memo[n]=max((int)n,memo[n/2]+memo[n/3]+memo[n/4]);
    return memo[n];
  }
  else return max(n, mx(n/2)+mx(n/3)+mx(n/4));
}

int main()
{
  int i,t;
    fill(memo,memo+LIMIT,-1);  
  while(scanf("%d",&n)!=EOF)
    printf("%lld\n",mx(n));

  
  return 0;
}

// AC at 1.47
