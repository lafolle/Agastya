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

int W,j,k,n;
vi v(500), s(500), memo(10001);

int getmin(int p, int wt)
{
  int i,j,k;
  int mi;
  memo[0]=0;

  for(i=1;i<=W;i++){
    mi=SENTINEL;
    for(j=0;j<n;j++){
      if(i-s[j]>=0) // check if there is room for element j
	mi = min(mi, memo[i-s[j]]+v[j]);
    }
    memo[i]=mi;
  }

  return memo[W];
  
}

int main()
{
  int t,fp,ep,i;
  scanf("%d",&t);
  while(t--){
    scanf("%d %d", &ep, &fp);
    W=fp-ep;
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d %d",&v[i],&s[i]);
    fill(all(memo),-1);
    int k=getmin(0,W);
    if(k==SENTINEL)printf("This is impossible.\n");
    else printf("The minimum amount of money in the piggy-bank is %d.\n",k);
  }
  return 0;
}

// AC at 0.53 (simple knapsack with multiple copies allowed)

