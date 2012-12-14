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

void binrep(lli n, vi &bn)
{
  int i,k;
  lli j=1LL<<63;
  for(i=0;i<64;i++)if(((n<<i)&j)==j)break;
  k=63-i;
  for(i=0;i<=k;i++)bn.push_back((n>>i)&1);
  // copy(all(bn),ostream_iterator<int>(cout,""));pl;
}

lli modexp(int a,int b,int n)
{
  lli c=0,d=1;
  int i,k;
  vi bn;
  binrep(b,bn);
  k=sz(bn);
  for(i=k-1;i>=0;i--){
    c=2*c;
    d=(d*d)%n;
    if(bn[i]){
      c+=1;
      d=(d*a)%n;
    }
  }
  return d;
}

int main()
{
  int t;
  lli x,y,n;
  scanf("%d",&t);
  while(t--){
    scanf("%lld %lld %lld",&x,&y,&n);
    printf("%lld\n",modexp(x,y,n));
  }
  return 0;
}

/*
  AC for 2.
  Needs to be updated for 10.
*/
