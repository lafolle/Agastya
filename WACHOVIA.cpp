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

int weight[51], value[51];
int K, M;

int m[51][1005];

int getval()
{
  int i,j,k;

  for(i=1;i<=K;i++)m[0][i]=0;


  for(i=1;i<=M;i++)
    for(j=0;j<=K;j++)
      m[i][j] = j<weight[i] ? m[i-1][j] : max(m[i-1][j], value[i]+m[i-1][j-weight[i]]);


  return m[M][K];
}

int main()
{
  int i,j,k,t, mval;

  scanf("%d" ,&t);

  while(t--){

    scanf("%d %d", &K, &M); 

    for(i=1;i<=M;i++)scanf("%d %d", &weight[i], &value[i]);

    mval = getval();

    printf("Hey stupid robber, you can get %d.\n", mval);

    
  }
  
  return 0;
}

// AC
