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
using namespace __gnu_cxx;

#define fr(i,n) for(int i = 0; i < (int)(n);i++)
#define pl cout<<endl;
#define all(v) v.begin(),v.end()
#define alln(v,n) v.begin()+1,v.begin()+n
#define sz(v) v.size()
#define INF 1000001
#define pb push_back
#define PI 3.141592653589793


typedef unsigned int uint;
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

inline void unsetbit(unsigned int &n, int k) {n=n&(~(1<<k));}
inline void setbit(unsigned int &n, int k) {n=n|(1<<k);}
inline void toggle(unsigned int &n, int k) {n=n^(1<<k);}
inline uint gcd(uint a, uint b) {return !b?a:gcd(b,a%b);}
struct eqstr{bool operator()(const char* s1, const char* s2) const{return !strcmp(s1, s2);}};

void binrep(lli n, vi &bn)
{
  int i,k;
  lli j=1LL<<63;
  for(i=0;i<64;i++)if(((n<<i)&j)==j)break;
  k=63-i;
  for(i=0;i<=k;i++)bn.push_back((n>>i)&1);
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
  long long int a, b, n;

  cin >> a >> b >> n;

  
  cout << modexp(a, b, n) << endl;
  
  return 0;
}

