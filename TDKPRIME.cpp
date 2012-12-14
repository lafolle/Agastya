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
#define alln(v,n) v.begin()+1,v.begin()+n
#define sz(v) v.size()
#define INF 1000001
#define pb push_back
#define PI 3.141592653589793

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
struct eqstr{bool operator()(const char* s1, const char* s2) const{return !strcmp(s1, s2);}};

//#define MAX 86688999
#define MAX 80000000

vi primes(5000001);
bitset<MAX+1> B;

int main()
{
  int i_time=clock();
  cout<<i_time<<endl;
  int i,j,k,t,n;

  B.set(0);
  B.set(1);


  for(i=3;i<=MAX;i+=2){
    if(!B[i]){
      k=MAX/i;
      for(j=3;j<=k;j+=2)
	B.set(i*j);
    }
  }

  j=1;
  primes[j++]=2;
  for(i=3;i<=MAX&&j<=5000000;i+=2) if(!B[i]) primes[j++]=i;

  scanf("%d", &t);

  while(t--){

    scanf("%d", &n);

    //    printf("%d\n", primes[n]);
    
  }

  int f_time=clock();
  cout<<f_time<<endl;
  cout<<(f_time-i_time)/1000000<<endl;
  return 0;
}

