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

#include <stdio.h>

#define i64 unsigned long long

i64 dp[66][33];

i64 nCr(int n, int r)
{
    if(n==r) return dp[n][r] = 1;
    if(r==0) return dp[n][r] = 1;
    if(r==1) return dp[n][r] = (i64)n;
    if(dp[n][r]) return dp[n][r];
    return dp[n][r] = nCr(n-1,r) + nCr(n-1,r-1);
}

i64 rec_nCr(int n, int r)
{
  if(n==r) return 1;
  if(r==0) return 1;
  if(r==1) return n;
  return rec_nCr(n-1,r)+rec_nCr(n-1,r-1);
}

int main()
{
    int n, r;
    while(scanf("%d %d",&n,&r)==2)
    {
        r = (r<n-r)? r : n-r;
	//        printf("%llu\n",nCr(n,r));
	printf("%lld\n",rec_nCr(n,r));
    }
    return 0;
}


