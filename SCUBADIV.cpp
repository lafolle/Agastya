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

int L[30][80], ox[1001], ntr[1001], w[1001];
int n, ro, rn;

void compute()
{
  int i,j,k;

  for(i=0;i<=ro;i++)for(j=0;j<=rn;j++)L[i][j]=INF;
  
  for(i=0;i<n;i++)
    for(j=1;j<=ro;j++)
      for(k=1;k<=rn;k++)
	if(j>ox[i] and k>ntr[i])
	  L[k][j] = min(L[k][j], w[i] + L[k-ox[i]][j-ntr[i]]);
			
  for(i=0;i<=ro;i++,printf("\n"))for(j=0;j<=rn;j++)cout<<L[i][j]<<' ';			


}

int main()
{

  int t, i,j,k;

  scanf("%d", &t);

  while(t--){

    scanf("%d %d", &ro, &rn);

    scanf("%d", &n);

    for(i=0;i<n;i++) scanf("%d %d %d", &ox[i], &ntr[i], &w[i]);

    compute();

    printf("%d\n", L[ro][rn]);
    
  }
  
  return 0;
}

// NO, this is not how you do this!
