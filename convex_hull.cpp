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

vpii point;
int n;
const int stack_size_max = 100000;

bool left_turn(const pii &p, const pii &q, const pii &r)
{
  
}

class VStack{
  //  vector<pair<int, int> > v(stack_size_max);
  pii v[stack_size_max];
  int topi;
public:
  VStack(){topi=0;}
  void vpush(const pii &p){
    v[topi] = p;
    ++topi;
  }
  pii vtop(){ return v[topi]; }
  void vpop(){--topi;}
  pii next_to_top(){ return v[topi-1]; }
};

int main()
{
  int i,j,k, current_ntt=0,x,y;
  pii pivot, next_to_top; 
  pivot.first = INF;
  pivot.second = INF;

  VStack S;
  
  for(i=0;i<n;i++){
    scanf("%d", &x);
    scanf("%d", &y);
    point.pb(make_pair(x,y));
  }

  // get lowest leftmost point
  for(i=0;i<n;i++){
    if(point[i].second < pivot.second or
       point[i].second == pivot.second and point[i].second < pivot.second)
      pivot.second = point[i].second;
  }

  //  sort(all(point), cmp());

  S.vpush(point[0]);S.vpush(point[1]);S.vpush(point[2]);
  for(i=3;i<n;i++){
    while(!left_turn(S.next_to_top(), S.vtop(), point[i])){S.vpop();}
    S.vpush(point[i]);
  }
  
  return 0;
}

