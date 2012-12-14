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
#define SENTINEL 1000000
#define pb push_back

typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef map<string, int> msi;


/*
  First 8 bits represent red.
  Second 8 bits represent green.
  Third 8 bites represent blue.

  So, for n=16777215, we have :
   b=255
   g=255
   r=255
*/
void setRGB(int n, int &b, int &g, int &r)
{
  int k = (1<<8)-1;;
  r=n&k;
  g=(n&(k<<8))>>8;
  b=(n&(k<<16))>>16;
}


// without reversing
void tobinary_optimal(int n)
{
  int k=1,s=0,g=1<<30,lim=31;;
  vb bin;
  for(;!(g&n);g>>=1,--lim); // get last digit set
  while(s<lim) bin.pb(n&g>>s++);
  copy(all(bin),ostream_iterator<bool>(cout, ""));pl;
}  

inline void unsetbit(unsigned int &n, int k) {n=n&(~(1<<k));}
inline void setbit(unsigned int &n, int k) {n=n|(1<<k);}
inline void toggle(unsigned int &n, int k) {n=n^(1<<k);}

int main()
{


  int k;
  unsigned int n;
  scanf("%u", &n);
  tobinary_optimal(n);
  
  while(1){

    n-=1;
    cout << n << ' ';tobinary_optimal(n); 

  }
  
  return 0;
  
}


/*
  Left shift - mulltiplication by 2
  Right shift - division by 2
*/
