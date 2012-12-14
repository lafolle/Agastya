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

vi v(10000,0);
int len;

void mulby2()
{
  int i ,k,carry=0;
  for(i=0;i<len;i++){
    k = v[i]*2;
    v[i]=k%10+carry;
    carry=k/10;
  }
  if(carry){
    v[len]=carry;
    ++len;
  }
}

void add1()
{

  int i,j,k, carry=0;

  k = v[0]+1;
  v[0]=k%10+carry;
  carry = k/10;

  for(i=1;carry && i<len;i++){
    k = v[i]+carry;
    v[i]=k%10+carry;
    carry=k/10;
  }

  if(carry){
    v[len]=carry;
    ++len;
  }
}

void sub1()
{
  int i,j,k;

  if(!v[0]){
    for(i=1;!v[i] && i<len;i++);
    v[i]-=1;
    for(j=i-1;j>=0;j--)v[j]=9;
    v[0]-=1;
  }
  else v[0]-=1;
}


int main()
{

  int n,i,j;

  //  scanf("%d", &n);



  for(n=1;n<1000;n++){
    len=1;
    for(i=2;i<=n;i++){

      mulby2();
    
      if((i-1)%2==1) add1();
      else sub1();
    }
  

    for(i=len-1;i>=0;i--) printf("%d", v[i]);pl;
  }
  
  return 0;
}
