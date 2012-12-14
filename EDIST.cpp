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

char a[2001], b[2001];
int l1, l2;

int edist(int i, int j, int d, string c)
{
  if(i>l2) return d;

  if(a[i]==b[i]){
    c+=a[i];
    return edist(i+1,j+1,d, c);
  }

  // either delete
  int del=edit(i+1, j, d+1, c);
  
  // or copy
  int cpy=edist(i+1, j+1, d+1, c+b[j]);

  // or insert
  int ins=edist(i, );
}

int main()
{
  int t=10;
  int i,j,k;

  while(t--){

    string s="";
    
    scanf("%s", a);
    scanf("%s", b);

    l1=strlen(a);
    l2=strlen(b);
    
    printf("%d\n",edist(0,0,0,s));

    memset(a, '\0', l1);
    memset(b, '\0', l2);
    
  }
  return 0;
}

