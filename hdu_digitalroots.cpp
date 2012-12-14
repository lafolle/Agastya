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
#include <string.h>

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

char numb[10000];

int main()
{

  int i,j,k;

  unsigned long long int n, p, g;

  scanf("%s", numb);

  int len = strlen(numb);

  while(strcmp(numb, "0")){

    p=0;
    
    for(i=0;i<len;i++)p+=numb[i]-'0';

      
    while(p>=10){
      g=0;
      
      while(p){
	k=p%10;
	p/=10;
	g+=k;
      }
      p=g;
    }

    printf("%llu\n", p);

    //    bzero(numb,'0');
    memset(numb, '0', sizeof(char)*len);

    scanf("%s", numb);

  }
  
  return 0;
}

